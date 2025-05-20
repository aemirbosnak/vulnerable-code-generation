//Falcon-180B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

// Node structure definition
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

// Function for creating an empty list
LinkList create_list() {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    if (!L) {
        printf("Memory error\n");
        exit(ERROR);
    }
    L->next = NULL;
    return L;
}

// Function for inserting a node at the end of the list
void insert_node(LinkList* L, int data) {
    LinkList p = *L, q = (LinkList) malloc(sizeof(LNode));
    if (!q) {
        printf("Memory error\n");
        exit(ERROR);
    }
    q->data = data;
    q->next = NULL;
    while (p->next!= NULL)
        p = p->next;
    p->next = q;
}

// Function for deleting a node from the list
void delete_node(LinkList* L, int data) {
    LinkList p = *L, q = (LinkList) malloc(sizeof(LNode));
    if (!q) {
        printf("Memory error\n");
        exit(ERROR);
    }
    q = p->next;
    while (q!= NULL && q->data!= data) {
        p = q;
        q = q->next;
    }
    if (q == NULL) {
        printf("Element not found\n");
        exit(ERROR);
    }
    p->next = q->next;
    free(q);
}

// Function for displaying the list
void display_list(LinkList L) {
    while (L!= NULL) {
        printf("%d ", L->data);
        L = L->next;
    }
}

// Function for sorting the list using bubble sort
void bubble_sort(LinkList L) {
    int n = 0, i, j, temp;
    LinkList p, q;
    p = L->next;
    while (p!= NULL) {
        n++;
        p = p->next;
    }
    for (i = 0; i < n - 1; i++) {
        p = L->next;
        for (j = 0; j < n - i - 2; j++) {
            if (p->data > p->next->data) {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
}

// Main function
int main() {
    int choice, data;
    LinkList L = create_list();
    while (TRUE) {
        printf("\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Sort\n");
        printf("5. Exit\n");
        printf("\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_node(&L, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                delete_node(&L, data);
                break;
            case 3:
                display_list(L);
                break;
            case 4:
                bubble_sort(L);
                printf("\nList sorted successfully\n");
                break;
            case 5:
                exit(OK);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}