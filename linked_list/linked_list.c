#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _node* nodePointer;
typedef struct _linked_list* listPointer;

typedef struct _linked_list {
	nodePointer head;
	nodePointer tail;
	int nodeCount;
}linked_list;


typedef struct _node {
	int data;
	nodePointer next;
}node;

void listInit(listPointer List) {
	List->head = NULL;
	List->tail = NULL;
	List->nodeCount = 0;
}

void input_data(listPointer List, int data) {
	nodePointer newNode = (nodePointer)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if (List->tail == NULL && List->head == NULL) {
		List->tail = List->head = newNode;
	}
	else {
		List->tail->next = newNode;
		List->tail = newNode;
	}
	List->nodeCount++;
}

int getAt(listPointer List, int idx) {
	nodePointer tmp = List->head;
	for (int i = 0; i < List->nodeCount; i++) {
		if (i == idx)
			break;
		tmp = tmp->next;
	}
	return tmp->data;
}


void delete_data(listPointer List, int idx) {
	nodePointer present_node = List->head;
	nodePointer prev_node = NULL;
	nodePointer next_node = NULL;

	for (int i = 0; present_node != NULL; i++) {
		if (idx == i) {
			if (idx == 0) {
				next_node = present_node->next;
				List->head = next_node;
				free(present_node);
				List->nodeCount--;
				break;
			}
			else if (idx == List->nodeCount - 1) {
				prev_node->next = NULL;
				List->tail = prev_node;
				free(present_node);
				List->nodeCount;
				break;
			}
			else if (idx < List->nodeCount - 1) {
				next_node = present_node->next;
				prev_node->next = next_node;
				free(present_node);
				List->nodeCount--;
				break;
			}
			else {
				printf("error idx\n");
				exit(-1);
			}
		}
		prev_node = present_node;
		present_node = present_node->next;
	}
}

void print_list(listPointer List) {
	nodePointer tmp = List->head;
	while(tmp){
		printf("%3d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main() {
	int arr[10] = { 5, 1, 3, 6, 8, 12, 4, 9, 15, 39 };

	listPointer List = (listPointer)malloc(sizeof(linked_list));

	listInit(List);
	
	for(int i = 0; i < 10; i++)
		input_data(List, arr[i]);
	print_list(List);

	delete_data(List, 5);
	print_list(List);
	delete_data(List, 8);
	print_list(List);
	delete_data(List, 0);
	print_list(List);
	return 0;
}