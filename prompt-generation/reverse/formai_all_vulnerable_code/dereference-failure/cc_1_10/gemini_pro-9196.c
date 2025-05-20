//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node{
	char *name;
	char *number;
	struct _node *next;
}node;

node *head=NULL,*tail=NULL;

void insert(char *name,char *number){
	node *temp=(node*)malloc(sizeof(node));
	temp->name=(char*)malloc(strlen(name)+1);
	temp->number=(char*)malloc(strlen(number)+1);
	strcpy(temp->name,name);
	strcpy(temp->number,number);
	temp->next=NULL;
	if(head==NULL){
		head=tail=temp;
	}else{
		tail->next=temp;
		tail=temp;
	}
}

void delete(char *name){
	node *temp=head,*prev=NULL;
	while(temp!=NULL && strcmp(temp->name,name)!=0){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Contact not found!\n");
		return;
	}
	if(prev==NULL){
		head=temp->next;
	}else{
		prev->next=temp->next;
	}
	if(temp==tail){
		tail=prev;
	}
	free(temp->name);
	free(temp->number);
	free(temp);
}

void search(char *name){
	node *temp=head;
	while(temp!=NULL && strcmp(temp->name,name)!=0){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("Contact not found!\n");
		return;
	}
	printf("Name:%s\nNumber:%s\n",temp->name,temp->number);
}

void display(){
	node *temp=head;
	while(temp!=NULL){
		printf("Name:%s\nNumber:%s\n",temp->name,temp->number);
		temp=temp->next;
	}
}

int main(){
	insert("John","1234567890");
	insert("Jane","0987654321");
	insert("Jack","111222333");
	insert("Jill","444555666");
	insert("Jim","555666777");
	display();
	printf("\n");
	delete("Jack");
	display();
	printf("\n");
	search("Jill");
	printf("\n");
	return 0;
}