//FormAI DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char email[100];
    struct Node* next;
};

struct Node* head;

void initialize(){
    head = NULL;
}

void insert(char email[]){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->email,email);
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        return;
    }
    struct Node* current = head;
    while(current->next!=NULL)
        current = current->next;
    current->next = temp;
}

void delete(char email[]){
    if(head==NULL) return;
    if(strcmp(head->email,email)==0){
        head = head->next;
        return;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    while(current!=NULL && strcmp(current->email,email)!=0){
        prev = current;
        current = current->next;
    }
    if(current==NULL) return;
    prev->next = current->next;
}

void print(){
    struct Node* current = head;
    while(current!=NULL){
        printf("%s\n",current->email);
        current = current->next;
    }
}

int main(){
    initialize();
    insert("johndoe@gmail.com");
    insert("janedoe@yahoo.com");
    insert("smithjoe@hotmail.com");
    insert("kimlee@gmail.com");
    printf("Mailing list:\n");
    print();
    printf("------------------------------------\n");
    printf("Removing 'smithjoe@hotmail.com' from mailing list:\n");
    delete("smithjoe@hotmail.com");
    print();
    return 0;
}