//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return head;
    }
    struct node *current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = temp;
    return head;
}

struct node *delete(struct node *head, int data) {
    struct node *temp = head;
    if (temp == NULL) {
        return NULL;
    }
    if (temp->data == data) {
        struct node *current = head;
        while (current->next!= NULL) {
            if (current->next->data == data) {
                current->next = current->next->next;
                free(current->next);
                return head;
            }
            current = current->next;
        }
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            struct node *temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    struct node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    printf("List: ");
    struct node *current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    delete(head, 4);
    printf("List after deleting 4: ");
    current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return 0;
}