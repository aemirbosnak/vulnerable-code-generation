//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct index {
    int id;
    char name[20];
    char address[50];
    int age;
};

struct node {
    struct index data;
    struct node* next;
};

struct node* create_node(struct index val) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insert_node(struct node** head, struct index val) {
    struct node* newnode = create_node(val);
    newnode->next = *head;
    *head = newnode;
}

void print_node(struct node* head) 
{
    struct node* temp = head;
    while(temp != NULL) {
        printf("ID: %d\nName: %s\nAddress: %s\nAge: %d\n\n", temp->data.id, temp->data.name, temp->data.address, temp->data.age);
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;

    struct index person1 = {100, "John", "Main Street", 30};
    insert_node(&head, person1);

    struct index person2 = {200, "Mark", "Park Avenue", 25};
    insert_node(&head, person2);
  
    struct index person3 = {300, "Mary", "Center Street", 35};
    insert_node(&head, person3);

    struct index person4 = {400, "Lisa", "Broadway Avenue", 27};
    insert_node(&head, person4);
  
    printf("Original list:\n\n");
    print_node(head);

    return 0;
}