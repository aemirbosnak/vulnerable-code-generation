//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[30];
    int age;
    struct Node* next;
} node;

void insert(node* head) {
    node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    printf("Enter name: ");
    scanf("%s", new_node->name);
    printf("Enter age: ");
    scanf("%d", &new_node->age);
    new_node->next = NULL;
    curr->next = new_node;
}

void search(node* head, char name[]) {
    if (head == NULL) {
        printf("%s not found in the database.\n", name);
        return;
    } else if (strcmp(head->name, name) == 0) {
        printf("%s found in the database. Age: %d\n", name, head->age);
        return;
    }
    search(head->next, name);
}

void delete(node* head, char name[]) {
    node* curr = head;
    node* prev = NULL;
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("%s not found in the database.\n", name);
        return;
    }
    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    printf("%s has been removed from the database.\n", name);
    free(curr);
}

void print_database(node* head) {
    if (head == NULL) {
        printf("The database is empty.\n");
        return;
    }
    node* curr = head;
    while (curr != NULL) {
        printf("%s, %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

void menu() {
    printf("----------------MENU-----------------\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Print Database\n");
    printf("5. Exit\n");
    printf("-------------------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    strcpy(head->name, "John");
    head->age = 30;
    head->next = NULL;

    int choice;
    char name[30];
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(head);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                search(head, name);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete(head, name);
                break;
            case 4:
                print_database(head);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}