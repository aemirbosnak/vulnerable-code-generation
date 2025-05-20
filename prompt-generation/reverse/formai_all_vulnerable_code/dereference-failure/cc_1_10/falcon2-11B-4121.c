//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addToHead(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void addToTail(struct node** head, int data) {
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    struct node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct node** head, int data) {
    if (*head == NULL) {
        return;
    }
    struct node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            temp->next = temp->next->next;
            free(temp->next);
            return;
        }
        temp = temp->next;
    }
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int nodeExists(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void reverseList(struct node** head) {
    struct node* prev = NULL;
    struct node* curr = *head;
    while (curr!= NULL) {
        struct node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct node* mergeLists(struct node* list1, struct node* list2) {
    struct node* newHead = NULL;
    struct node* curr1 = list1;
    struct node* curr2 = list2;
    while (curr1!= NULL || curr2!= NULL) {
        if (curr1!= NULL) {
            addToTail(&newHead, curr1->data);
            curr1 = curr1->next;
        }
        if (curr2!= NULL) {
            addToTail(&newHead, curr2->data);
            curr2 = curr2->next;
        }
    }
    return newHead;
}

struct node* swapData(struct node** head, int data1, int data2) {
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;
    struct node* curr = *head;
    while (curr!= NULL) {
        if (curr->data == data1) {
            temp1 = curr;
            break;
        }
        curr = curr->next;
    }
    while (curr!= NULL) {
        if (curr->data == data2) {
            temp2 = curr;
            break;
        }
        curr = curr->next;
    }
    if (temp1 == NULL || temp2 == NULL) {
        return *head;
    }
    if (temp1->data == data2 && temp2->data == data1) {
        *head = temp2;
        *head = temp1;
        return *head;
    }
    temp1->data = temp2->data;
    temp2->data = temp1->data;
    return *head;
}

struct node* copyList(struct node* head) {
    struct node* newHead = NULL;
    struct node* curr = head;
    while (curr!= NULL) {
        struct node* newNode = createNode(curr->data);
        newNode->next = newHead;
        newHead = newNode;
        curr = curr->next;
    }
    return newHead;
}

int main() {
    struct node* head = NULL;
    addToHead(&head, 1);
    addToHead(&head, 2);
    addToHead(&head, 3);
    printf("Original List: ");
    printList(head);
    printf("\n");
    addToTail(&head, 4);
    printf("Reversed List: ");
    reverseList(&head);
    printList(head);
    printf("\n");
    addToTail(&head, 5);
    printf("Merged List: ");
    struct node* list1 = head;
    struct node* list2 = head->next;
    while (list2!= NULL) {
        list1 = list1->next;
        list2 = list2->next;
    }
    list1 = mergeLists(list1, list2);
    printList(list1);
    printf("\n");
    addToTail(&head, 6);
    printf("Swapped List: ");
    struct node* newHead = swapData(&head, 2, 4);
    printList(newHead);
    printf("\n");
    addToTail(&head, 7);
    printf("Copied List: ");
    struct node* newHead2 = copyList(head);
    printList(newHead2);
    printf("\n");
    addToTail(&head, 8);
    printf("Node Exists: ");
    int data = 5;
    printf("%d\n", nodeExists(head, data));
    printf("Node Exists: ");
    int data2 = 9;
    printf("%d\n", nodeExists(head, data2));
    printf("\n");
    addToTail(&head, 9);
    printf("Node Exists: ");
    int data3 = 5;
    printf("%d\n", nodeExists(head, data3));
    printf("Node Exists: ");
    int data4 = 10;
    printf("%d\n", nodeExists(head, data4));
    printf("\n");
    return 0;
}