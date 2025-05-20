//Falcon-180B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

void create(node** head) {
    *head = NULL;
}

void insert(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    node* temp = *head;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(node* head) {
    node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void delete(node** head, int data) {
    node* temp = *head;
    node* prev = NULL;

    if(temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void search(node* head, int data) {
    node* temp = head;
    while(temp!= NULL) {
        if(temp->data == data) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

int main() {
    node* head = NULL;
    create(&head);

    int choice, data;

    while(1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}