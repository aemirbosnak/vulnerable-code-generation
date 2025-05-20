//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct RomeoAndJuliet {
    char name[MAX];
    int age;
    char side[MAX];
    struct RomeoAndJuliet* next;
} RomeoAndJuliet;

void insert(RomeoAndJuliet** head, char* name, int age, char* side) {
    RomeoAndJuliet* new_node = (RomeoAndJuliet*)malloc(sizeof(RomeoAndJuliet));
    strcpy(new_node->name, name);
    new_node->age = age;
    strcpy(new_node->side, side);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void query(RomeoAndJuliet* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s, Age: %d, Side: %s\n", head->name, head->age, head->side);
            break;
        } else {
            head = head->next;
        }
    }

    if (head == NULL) {
        printf("No such person found.\n");
    }
}

int main() {
    RomeoAndJuliet* head = NULL;

    insert(&head, "Romeo", 18, "Montague");
    insert(&head, "Juliet", 16, "Capulet");
    insert(&head, "Benvolio", 20, "Montague");
    insert(&head, " Mercutio", 20, "Capulet");

    query(head, "Romeo");
    query(head, "Juliet");
    query(head, "Benvolio");
    query(head, "No_such_person");

    return 0;
}