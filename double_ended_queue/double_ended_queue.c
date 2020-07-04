#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node* nodePointer;
typedef struct _deque* dequePointer;

typedef struct _node {
	nodePointer prev;
	nodePointer next;
	int data;
}node;

typedef struct _deque {
	nodePointer rear;
	nodePointer front;
	int nodeCount;
}deque;

void queueInit(dequePointer q) {
	q->front = NULL;
	q->rear = NULL;
	q->nodeCount = 0;
}

bool isEmpty(dequePointer q) {
	if (q->rear == NULL && q->front == NULL)
		return true;
	else
		return false;
}

void rear_enQueue(dequePointer q, int data) {
	nodePointer newNode = (nodePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (isEmpty(q)) {
		q->rear = newNode;
		q->front = newNode;
	}
	else {
		q->rear->prev = newNode;
		newNode->next = q->rear;
		q->rear = newNode;
	}
	q->nodeCount++;
}

void front_enQueue(dequePointer q, int data) {
	nodePointer newNode = (nodePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (isEmpty(q)) {
		q->rear = newNode;
		q->front = newNode;
	}
	else {
		q->front->next = newNode;
		newNode->prev = q->front;
		q->front = newNode;
	}
	q->nodeCount++;
}

void rear_deQueue(dequePointer q) {
	nodePointer tmp = q->rear;
	if (!isEmpty(q)) {
		tmp->next->prev = NULL;
		q->rear = tmp->next;
		free(tmp);
	}
	q->nodeCount--;
}

void front_dequeue(dequePointer q) {
	nodePointer tmp = q->front;
	if(!isEmpty(q)){
		tmp->prev->next = NULL;
		q->front = tmp->prev;
		free(tmp);
	}
	q->nodeCount--;
}

void print_queue(dequePointer q) {
	nodePointer tmp = q->rear;
	for (int i = 0; i < q->nodeCount; i++) {
		printf("%3d  ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	int arr[] = { 5, 10, 15, 20, 2, 4, 6, 8 };
	dequePointer q = (dequePointer)malloc(sizeof(deque));
	queueInit(q);

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		rear_enQueue(q, arr[i]);
	print_queue(q);

	rear_deQueue(q);
	print_queue(q);
	front_dequeue(q);
	print_queue(q);

	front_enQueue(q, 70);
	print_queue(q);

	return 0;
}