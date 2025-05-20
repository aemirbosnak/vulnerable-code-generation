//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_CREDITS 5
#define MAX_DEBTS 3

typedef struct Person {
    char name[50];
    int credits;
    int debts;
    struct Person* next;
} Person;

int main() {
    Person* head = NULL;

    // Create a few people
    Person* bob = malloc(sizeof(Person));
    strcpy(bob->name, "Bob");
    bob->credits = 20;
    bob->debts = 10;
    bob->next = NULL;

    Person* sue = malloc(sizeof(Person));
    strcpy(sue->name, "Sue");
    sue->credits = 50;
    sue->debts = 20;
    sue->next = NULL;

    Person* tom = malloc(sizeof(Person));
    strcpy(tom->name, "Tom");
    tom->credits = 10;
    tom->debts = 30;
    tom->next = NULL;

    // Add people to the list
    head = bob;
    bob->next = sue;
    sue->next = tom;

    // Print the list of people
    printf("List of people:\n");
    Person* current = head;
    while (current) {
        printf("%s has %d credits and %d debts.\n", current->name, current->credits, current->debts);
        current = current->next;
    }

    // Calculate total credits and debts
    int total_credits = 0;
    int total_debts = 0;
    current = head;
    while (current) {
        total_credits += current->credits;
        total_debts += current->debts;
        current = current->next;
    }

    // Print total credits and debts
    printf("Total credits: %d\n", total_credits);
    printf("Total debts: %d\n", total_debts);

    return 0;
}