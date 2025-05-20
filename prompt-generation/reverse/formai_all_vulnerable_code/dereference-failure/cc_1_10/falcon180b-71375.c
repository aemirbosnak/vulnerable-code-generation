//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

struct Node{
    char name[50];
    char email[50];
    struct Node* next;
};

struct Node* head = NULL;

void add_node(char name[], char email[]){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    }
    else{
        struct Node* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_node(char name[]){
    struct Node* temp = head;
    struct Node* prev = NULL;

    if(temp!= NULL && strcmp(temp->name, name) == 0){
        head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && strcmp(temp->name, name)!= 0){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void search_node(char name[]){
    struct Node* temp = head;

    while(temp!= NULL){
        if(strcmp(temp->name, name) == 0){
            printf("Name: %s\nEmail: %s\n", temp->name, temp->email);
            return;
        }
        temp = temp->next;
    }

    printf("Node not found\n");
}

void display_all_nodes(){
    struct Node* temp = head;

    while(temp!= NULL){
        printf("Name: %s\nEmail: %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main(){
    add_node("John", "john@example.com");
    add_node("Doe", "doe@example.com");
    add_node("Jane", "jane@example.com");

    display_all_nodes();

    delete_node("John");

    display_all_nodes();

    search_node("Doe");

    return 0;
}