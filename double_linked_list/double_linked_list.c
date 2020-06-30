#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node* nodePointer;
typedef struct _D_linked_list* DlinkPointer;


typedef struct _node {
	nodePointer prev;
	nodePointer next;
	int data;
}node;

typedef struct _D_linked_list {
	nodePointer head;
	nodePointer tail;
	int nodeCount;
}D_linked_list;

void ListInit(DlinkPointer d) {
	d->head = NULL;
	d->tail = NULL;
	d->nodeCount = 0;
}

void List_head_input(DlinkPointer d, int data) {
	nodePointer newNode = (nodePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (d->head == NULL && d->tail == NULL) {
		d->head = newNode;
		d->tail = newNode;
	}
	else {
		newNode->next = d->head;
		d->head->prev = newNode;
		d->head = newNode;
	}
	d->nodeCount++;
}

void List_tail_input(DlinkPointer d, int data) {
	nodePointer newNode = (nodePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (d->head == NULL && d->tail == NULL) {
		d->head = newNode;
		d->tail = newNode;
	}
	else {
		newNode->prev = d->tail;
		d->tail->next = newNode;
		d->tail = newNode;
	}
	d->nodeCount++;
}

void List_delete(DlinkPointer d, int idx) {
	nodePointer tmp = d->head;
	int cnt = 0;

	while (tmp != NULL) {
		if (idx == 0) {
			nodePointer delete_node = d->head;
			d->head->next->prev = NULL;
			d->head = d->head->next;
			free(delete_node);
			break;
		}
		else if (idx == d->nodeCount - 1) {
			nodePointer delete_node = d->tail;
			d->tail->prev->next = NULL;
			d->tail = d->tail->prev;
			free(delete_node);
			break;
		}
		else if (idx == cnt) {
			nodePointer delete_node = tmp;
			delete_node->prev->next = delete_node->next;
			delete_node->next->prev = delete_node->prev;
			free(delete_node);
			break;
		}
		tmp = tmp->next;
		cnt++;
	}
	d->nodeCount--;
}

void List_print(DlinkPointer d) {
	nodePointer tmp = d->head;
	for (int i = 0; i < d->nodeCount; i++) {
		printf("%3d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}



int main() {
	int arr[] = { 5, 10, 15, 20, 1, 2, 4, 6, 8 };
	DlinkPointer d = (DlinkPointer)malloc(sizeof(D_linked_list));
	ListInit(d);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		List_head_input(d, arr[i]);
	List_print(d);

	List_delete(d, 8);
	List_print(d);
	List_delete(d, 0);
	List_print(d);
	List_delete(d, 5);
	List_print(d);

	return 0;
}