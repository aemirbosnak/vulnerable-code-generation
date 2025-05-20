//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*head,*tail;

struct node* createNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int isEmpty(struct node* node){
	return (node == NULL);
}

void enqueue(int data){
	struct node* temp = createNode(data);
	if(isEmpty(head)){
		head = temp;
		tail = temp;
	}else{
		tail->next = temp;
		tail = tail->next;
	}
}

void dequeue(){
	if(isEmpty(head)){
		printf("Queue is empty.\n");
		return;
	}
	int data = head->data;
	head = head->next;
	free(head);
	printf("Element deleted: %d\n", data);
}

void display(){
	if(isEmpty(head)){
		printf("Queue is empty.\n");
		return;
	}
	struct node* temp = head;
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	head = NULL;
	tail = NULL;
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	display();
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
	return 0;
}