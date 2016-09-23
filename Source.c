#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node_t;

node_t* node;

typedef struct list{
	node_t* head;
}list_t;

list_t list;


void insertNode(list_t* list, node_t* nodeA, node_t* nodeB){
	if (list == NULL || nodeB == NULL) return;
	if (nodeA){
		nodeB->next = nodeA->next;
		nodeA->next = nodeB;
	}
	else{
		nodeB->next = list->head;
		list->head = nodeB;
	}
}

void delete(list_t* list, node_t* prevN, node_t* targetN){
	if (list == NULL || targetN == NULL) return;
	if (prevN){
		prevN->next = targetN->next;
	}
	else{
		list->head = list->head->next;
	}
}

void printList(list_t* list){
	node_t* curNode;

	if (list == NULL) return;
	curNode = list->head;
	while (curNode){
		printf("%d\n", curNode->data);
		curNode = curNode->next;
	}
	return;
}

void insertNodeAtFront(list_t* list, node_t* node){

	if (list == NULL || node == NULL) return;

	if (list->head == NULL){
		list->head = node;
		node->next = NULL;
	}else{
		node->next = list->head;
		list->head = node;
	}
}

node_t* searchNode(list_t* list, int key){
	if (list == NULL) return NULL;
	node_t* nowNode = list->head;

	do{
		if (nowNode->data == key){
			break;
		}
		nowNode = nowNode->next;
	}while(nowNode!=NULL);
	return nowNode;
}

void deleteNode(list_t* list, node_t* prevNode, node_t* targetNode){
	if (list == NULL || targetNode == NULL) return;

	if (prevNode){
		prevNode->next = targetNode->next;
	}
	else{
		list->head = targetNode->next;
	}
	//free(targetNode);
}

void goNext(node_t* nowNode){
	if (nowNode->next){
		goNext(nowNode->next);
	}
	else{
		//printf("%d", nowNode->data);
	}
	printf("%d\n", nowNode->data);
}

void printListReverse(list_t* list){
	if (list == NULL) return;
	node_t* nowNode = list->head;
	if (nowNode->next){
		goNext(nowNode);
	}
	else{
		printf("%d\n", nowNode->data);
	}
}



int main(viod){

	list.head = NULL;
	node = (node_t*)malloc(sizeof(node_t)*10);
	node[0].data = 10;
	//node[0].next = NULL;
	//list.head = node;

	insertNodeAtFront(&list, node);
	node[1].data = 20;
	insertNodeAtFront(&list, node + 1);
	node[2].data = 30;
	insertNodeAtFront(&list, node+2);
	node[3].data = 40;
	insertNodeAtFront(&list, node + 3);
	node[4].data = 50;
	insertNodeAtFront(&list, node + 4);
	node[5].data = 100;
	insertNodeAtFront(&list, node + 5);
	node[6].data = 45;
	insertNode(&list, searchNode(&list, 40), node+6);
	node[7].data = 5;
	insertNode(&list, NULL, node + 7);
	printListReverse(&list);
	
	printf("\n\n\n");
	printList(&list);



	free(node);
}