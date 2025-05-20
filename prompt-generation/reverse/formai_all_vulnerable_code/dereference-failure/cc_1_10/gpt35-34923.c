//FormAI DATASET v1.0 Category: Database simulation ; Style: content
#include<stdio.h>
#include<stdlib.h> 

struct node {
    int data;
    struct node* next;
};

void insert(struct node** list, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*list);
    (*list) = new_node;
}

void delete(struct node** list, int data) {
    struct node* temp = *list;
    struct node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        *list = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display(struct node* list) {
    struct node* temp = list;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct node* list = NULL;
    int choice, data;

    printf("\nLinked List Operations\n\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                insert(&list, data);
                break;

            case 2:
                printf("\nEnter data to delete: ");
                scanf("%d", &data);
                delete(&list, data);
                break;

            case 3:
                display(list);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}