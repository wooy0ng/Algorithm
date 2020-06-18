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