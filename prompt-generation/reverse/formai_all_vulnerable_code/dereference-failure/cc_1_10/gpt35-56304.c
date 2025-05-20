//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
// Romeo and Juliet style expense tracker program in C

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item[50];
    float price;
    char date[20];
} Expense;

typedef struct {
    Expense expense;
    struct Node *next;
} Node;

// Function to insert an expense in the linked list
void insertExpense(Node **head, Expense expense) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->expense = expense;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list of expenses
void printList(Node *head) {
    if (head == NULL) {
        printf("No expenses to display!\n");
        return;
    }
    printf("%-20s %-10s %-20s\n", "Item", "Price", "Date");
    printf("-------------------------------------\n");
    while (head != NULL) {
        printf("%-20s $%-9.2f %-20s\n", head->expense.item, head->expense.price, head->expense.date);
        head = head->next;
    }
}

// Function to get user input for a new expense
Expense getNewExpense() {
    Expense expense;
    printf("Enter the item: ");
    scanf("%s", expense.item);
    printf("Enter the price: ");
    scanf("%f", &expense.price);
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", expense.date);
    return expense;
}

// Function to display the menu and get user input for the selected option
int getMenuChoice() {
    int choice;
    printf("\n1. Add New Expense\n");
    printf("2. List All Expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    Node *head = NULL;
    int choice;
    do {
        printf("\nO Romeo, what dost thou desire?\n");
        choice = getMenuChoice();
        switch (choice) {
            case 1: {
                Expense expense = getNewExpense();
                insertExpense(&head, expense);
                printf("\nFair Juliet, I hath added thy new expense!\n");
                break;
            }
            case 2: {
                printf("\nLo, here are all thy expenses, brave Romeo!\n");
                printList(head);
                break;
            }
            case 3: {
                printf("\nParting is such sweet sorrow, but we must bid adieu!\n");
                break;
            }
            default: {
                printf("\nAlas, thy choice is not valid, good Romeo.\n");
                break;
            }
        }
    } while (choice != 3);
    return 0;
}