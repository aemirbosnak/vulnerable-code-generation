//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    int size;
    struct node *next;
};

struct node *head = NULL;

void insert(char *str) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->size = strlen(str);
    strncpy(new_node->data, str, MAX_SIZE);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void search(char *str) {
    struct node *temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("Found %s\n", str);
            return;
        }
        temp = temp->next;
    }

    printf("Not Found\n");
}

int main() {
    char str[MAX_SIZE];
    int choice;

    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter string to insert: ");
            scanf("%s", str);
            insert(str);
            break;
        case 2:
            printf("Enter string to search: ");
            scanf("%s", str);
            search(str);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}