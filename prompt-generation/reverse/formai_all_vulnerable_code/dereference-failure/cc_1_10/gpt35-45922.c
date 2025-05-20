//FormAI DATASET v1.0 Category: Mailing list manager ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

typedef struct node {
    char data[MAX];
    struct node* next;
}Node;

void display(Node* head) {
    printf("The mailing list: ");
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
}

void insert(Node** head_ref, char* item) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    strcpy(new_node->data, item);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteElement(Node** head_ref, char* key) {
    Node* temp = *head_ref, * prev;

    if (temp != NULL && strcmp(temp->data, key) == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->data, key) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main()
{
    Node* head = NULL;
    int choice, i;
    char name[MAX], item[MAX];

    do {
        printf("\n1.Insert a name\t2.Delete a name\t3.Display list\t4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the name you want to add: ");
            scanf("%s", name);
            insert(&head, name);
            break;
        case 2:
            printf("Enter the name you want to delete: ");
            scanf("%s", name);
            deleteElement(&head, name);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid Choice.\n");
        }

    } while (choice != 4);

    return 0;
}