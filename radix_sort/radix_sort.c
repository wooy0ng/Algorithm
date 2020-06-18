#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node* nodePointer;
typedef struct _lqueue* queuePointer;

typedef struct _node {
	int data;
	nodePointer prev;
}node;


typedef struct _lqueue {
	nodePointer rear;
	nodePointer front;
}queue;


bool isEmpty(queuePointer q) {
	if (q->front == NULL)
		return true;
	else
		return false;
}

void Enqueue(queuePointer q, int data) {
	nodePointer Node = (nodePointer)malloc(sizeof(node));
	Node->data = data;
	Node->prev = NULL;

	if (isEmpty(q)) {
		q->front = Node;
		q->rear = Node;
	}
	else {
		q->rear->prev = Node;
		q->rear = Node;
	}
}

int Dequeue(queuePointer q) {
	int pop_data = 0;
	
	nodePointer temp = q->front;
	pop_data = q->front->data;
	q->front = temp->prev;
	free(temp);
	return pop_data;
	
}

void queueInit(queuePointer q) {
	q->rear = NULL;
	q->front = NULL;
}

void print(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}


void radix_sort(int* arr, int size) {
	queuePointer queueArr = (queuePointer)malloc(sizeof(queue) * 10);
	for (int i = 0; i < 10; i++) {
		queueInit(&queueArr[i]);
	}
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	int pos = 1;
	while (max / pos) {
		for (int i = 0;i < size; i++) {
			int radix = (arr[i] / pos) % 10;
			Enqueue(&queueArr[radix], arr[i]);
		}
		for (int i = 0, j = 0; i < 10; i++) {
			while (!isEmpty(&queueArr[i])) {
				arr[j++] = Dequeue(&queueArr[i]);
			}
		}
		print(arr, size);
		pos *= 10;
	}
}

int main() {
	int arr[5] = { 3771, 1, 5022, 3, 98 };
	int size = sizeof(arr) / sizeof(int);

	radix_sort(arr, size);

	return 0;
}