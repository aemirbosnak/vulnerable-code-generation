//FormAI DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

//Node structure for linked list
struct node{
    int amount;
    struct node *next;
};

//Function prototypes
void add_expense(struct node **head_ref, int amount); //Add expense to linked list
void print_expenses(struct node *node); //Print all expenses in linked list
int calculate_total(struct node *node); //Calculate total expense

int main(){
    struct node *head = NULL;
    int choice, amount;

    printf("\n\tExpense Tracker\n");

    do{
        printf("\n1. Add Expense\n2. Print Expenses\n3. Calculate Total\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter amount: ");
                scanf("%d", &amount);
                add_expense(&head, amount);
                break;

            case 2:
                printf("\nExpenses:\n");
                print_expenses(head);
                break;

            case 3:
                printf("\nTotal Expense: %d\n", calculate_total(head));
                break;

            case 4:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }while(choice != 4);

    return 0;
}

//Function to add expense to linked list
void add_expense(struct node **head_ref, int amount){
    //Create new node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->amount = amount;
    new_node->next = NULL;

    if(*head_ref == NULL){
        //Linked list is empty, set new node as head
        *head_ref = new_node;
    }else{
        //Linked list is not empty, find the last node and add the new node
        struct node *last_node = *head_ref;
        while(last_node->next != NULL){
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }

    printf("\nExpense added successfully!\n");
}

//Function to print all expenses in linked list
void print_expenses(struct node *node){
    if(node == NULL){
        printf("\nNo Expenses Added!\n");
        return;
    }

    printf("\nAmount\n");
    printf("------\n");
    while(node != NULL){
        printf("%d\n", node->amount);
        node = node->next;
    }
}

//Function to calculate total expense using recursion
int calculate_total(struct node *node){
    if(node == NULL){
        return 0;
    }
    return node->amount + calculate_total(node->next);
}