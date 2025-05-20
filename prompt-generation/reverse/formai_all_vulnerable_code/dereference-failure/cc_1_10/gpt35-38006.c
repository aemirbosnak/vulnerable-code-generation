//FormAI DATASET v1.0 Category: Mailing list manager ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node { 
    char email[50]; 
    struct node* next; 
}; 

typedef struct node NODE; 

NODE* create_node(char* email) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE)); 
    strcpy(new_node->email, email); 
    new_node->next = NULL; 
    return new_node; 
}

void insert(NODE** head, char* email) {
    NODE* temp = create_node(email); 
    if (*head == NULL) { 
        *head = temp; 
        return; 
    } 
    NODE* itr = *head; 
    while (itr->next != NULL) { 
        itr = itr->next; 
    } 
    itr->next = temp; 
}

void delete(NODE** head, char* email) {
    NODE* temp = *head, *prev; 
    if (temp != NULL && strcmp(temp->email, email) == 0) { 
        *head = temp->next; 
        free(temp); 
        return; 
    } 
    while (temp != NULL && strcmp(temp->email, email) != 0) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp); 
}

void display(NODE* head) {
    NODE* itr = head; 
    while (itr != NULL) { 
        printf("%s\n", itr->email); 
        itr = itr->next; 
    } 
    printf("\n"); 
}

int main() {
    NODE* head = NULL; 

    insert(&head, "user1@example.com"); 
    insert(&head, "user2@example.com"); 
    insert(&head, "user3@example.com"); 

    printf("Mailing list:\n"); 
    display(head); 

    printf("Deleting user2@example.com from mailing list\n"); 
    delete(&head, "user2@example.com"); 

    printf("Updated mailing list:\n"); 
    display(head); 

    return 0; 
}