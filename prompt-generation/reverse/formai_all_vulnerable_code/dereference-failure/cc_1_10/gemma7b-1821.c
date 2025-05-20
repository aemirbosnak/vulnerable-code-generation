//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[20];
    struct node* next;
};

struct node* insert(struct node* head, char name[]) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = insert(head->next, name);
    }

    return head;
}

int search(struct node* head, char name[]) {
    if (head == NULL) {
        return 0;
    }

    if (strcmp(head->name, name) == 0) {
        return 1;
    }

    return search(head->next, name);
}

void appointment(struct node* head) {
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    if (search(head, name) == 1) {
        printf("You are already booked for today.\n");
    } else {
        insert(head, name);
        printf("Your appointment has been booked.\n");
    }
}

int main() {
    struct node* head = NULL;

    appointment(head);

    return 0;
}