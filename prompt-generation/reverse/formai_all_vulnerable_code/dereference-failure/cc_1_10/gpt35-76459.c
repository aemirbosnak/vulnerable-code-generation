//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void delete(int x) {
    struct Node* temp1 = head;
    if (temp1 == NULL) {
        return; 
    }
    if (temp1 -> data == x) {
        head = temp1 -> next;
        free(temp1);
        return;
    }
    while (temp1 -> next != NULL) {
        if (temp1 -> next -> data == x) {
            struct Node* temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next; 
            free(temp2);
            return;
        }
        temp1 = temp1 -> next;
    }
}

void print() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    int n,i,x;
    printf("How many numbers? ");
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        printf("Enter the number ");
        scanf("%d",&x);
        insert(x);
        print();
    }
    printf("Enter the number to delete ");
    scanf("%d",&x);
    delete(x);
    print();
    return 0;
}