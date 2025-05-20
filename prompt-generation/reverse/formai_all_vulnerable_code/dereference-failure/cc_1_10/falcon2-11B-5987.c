//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createList(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void displayList(struct node* head) {
    struct node* ptr = head;
    while(ptr!= NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* deleteList(struct node* head, int index) {
    struct node* temp = head;
    struct node* prev = NULL;
    int count = 0;
    while(temp!= NULL) {
        if(count == index) {
            if(prev == NULL) {
                head = temp->next;
                free(temp);
                return head;
            }
            else {
                prev->next = temp->next;
                free(temp);
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return head;
}

int main() {
    struct node* head = NULL;
    head = createList(10);
    head->next = createList(20);
    head->next->next = createList(30);
    displayList(head);
    head = deleteList(head, 1);
    displayList(head);
    return 0;
}