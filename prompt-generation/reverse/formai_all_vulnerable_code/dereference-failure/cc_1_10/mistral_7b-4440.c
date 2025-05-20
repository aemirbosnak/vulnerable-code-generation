//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

//Curious Struct
typedef struct curious {
    int data;
    int random;
    struct curious *next;
} Curious;

//Curious Function Prototypes
void curious_insert(Curious **head, int data, int random);
void curious_display(Curious *head);
void curious_delete(Curious **head, int data, int random);

int main(int argC, char *argV[]) {
    Curious *head = NULL;

    //Curious Input
    if(argC != 4) {
        printf("Usage : %s <data> <random> <operation(i/d/p)>");
        return 1;
    }

    int data = atoi(argV[1]);
    int random = atoi(argV[2]);
    char operation = argV[3][0];

    //Curious List Operations
    if(operation == 'i')
        curious_insert(&head, data, random);
    else if(operation == 'd') {
        curious_delete(&head, data, random);
    } else if(operation == 'p') {
        curious_display(head);
    } else {
        printf("Invalid Operation. Use i for Insert, d for Delete and p for Print.");
        return 1;
    }

    curious_display(head);
    return 0;
}

//Curious List Insertion
void curious_insert(Curious **head, int data, int random) {
    Curious *newCurious = (Curious*)malloc(sizeof(Curious));
    Curious *current = *head;

    newCurious->data = data;
    newCurious->random = random;
    newCurious->next = NULL;

    //Curious Positioning
    if(*head == NULL) {
        *head = newCurious;
        return;
    }

    while(current->next != NULL && (current->next->data < data || current->next->random != random)) {
        current = current->next;
    }

    newCurious->next = current->next;
    current->next = newCurious;
}

//Curious List Display
void curious_display(Curious *head) {
    printf("\nCurious List : \n");

    Curious *current = head;
    while(current != NULL) {
        printf("{ %d, %d } -->", current->data, current->random);
        current = current->next;
    }

    printf("NULL");
}

//Curious List Deletion
void curious_delete(Curious **head, int data, int random) {
    Curious *current = *head, *previous = NULL;

    //Curious Search
    while(current != NULL && (current->data != data || current->random != random)) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("Element not found.\n");
        return;
    }

    if(previous == NULL) { //Curious Head Deletion
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}