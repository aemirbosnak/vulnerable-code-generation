//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Personal Finance Planner struct
typedef struct PersonalFinancePlanner {
    char name[50];
    int age;
    double income;
    double expenses;
    double netWorth;
    struct PersonalFinancePlanner* next;
} PersonalFinancePlanner;

// Function to create a new Personal Finance Planner node
PersonalFinancePlanner* createNode(char* name, int age, double income, double expenses) {
    PersonalFinancePlanner* node = (PersonalFinancePlanner*)malloc(sizeof(PersonalFinancePlanner));
    strcpy(node->name, name);
    node->age = age;
    node->income = income;
    node->expenses = expenses;
    node->netWorth = income - expenses;
    node->next = NULL;
    return node;
}

// Function to add a new node to the end of the Personal Finance Planner list
void addNode(PersonalFinancePlanner* head, char* name, int age, double income, double expenses) {
    PersonalFinancePlanner* newNode = createNode(name, age, income, expenses);
    if (head == NULL) {
        head = newNode;
    } else {
        PersonalFinancePlanner* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the Personal Finance Planner list
void printList(PersonalFinancePlanner* head) {
    PersonalFinancePlanner* current = head;
    while (current) {
        printf("%s, %d, %.2lf, %.2lf, %.2lf\n", current->name, current->age, current->income, current->expenses, current->netWorth);
        current = current->next;
    }
}

int main() {
    // Create a new Personal Finance Planner list
    PersonalFinancePlanner* head = NULL;

    // Add some nodes to the list
    addNode(head, "John Doe", 25, 50000, 20000);
    addNode(head, "Jane Doe", 30, 60000, 30000);
    addNode(head, "Bob Smith", 40, 70000, 40000);

    // Print the list
    printList(head);

    return 0;
}