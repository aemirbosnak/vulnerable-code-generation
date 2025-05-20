//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct node {
    char name[20];
    char type[20];
    int quantity;
    struct node* next;
};

struct node* start = NULL;

void push(struct node** top_ref, char* name, char* type, int quantity) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->type, type);
    new_node->quantity = quantity;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

void pop(struct node** top_ref) {
    struct node* temp = (*top_ref);
    (*top_ref) = (*top_ref)->next;
    free(temp);
}

void print_list(struct node* node) {
    while(node!= NULL) {
        printf("%s %s %d\n", node->name, node->type, node->quantity);
        node = node->next;
    }
}

int main() {
    char ch;
    start = NULL;
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                char name[20], type[20];
                int quantity;
                printf("Enter the name of the medicine: ");
                scanf("%s", name);
                printf("Enter the type of the medicine: ");
                scanf("%s", type);
                printf("Enter the quantity of the medicine: ");
                scanf("%d", &quantity);
                push(&start, name, type, quantity);
                break;
            }
            case 2: {
                pop(&start);
                break;
            }
            case 3: {
                print_list(start);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while(ch!= 4);
    return 0;
}