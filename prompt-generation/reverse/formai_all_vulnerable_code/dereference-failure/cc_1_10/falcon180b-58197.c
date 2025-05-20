//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

//Function to add a node at the end of the list
void addNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL)
        *head = newNode;
    else{
        struct Node* temp = *head;
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

//Function to reverse the list
void reverseList(struct Node** head){
    struct Node* prev = NULL;
    struct Node* curr = *head;
    while(curr!= NULL){
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

//Function to print the list
void printList(struct Node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

//Function to check if the list is a palindrome
bool isPalindrome(struct Node* head){
    reverseList(&head);
    struct Node* curr1 = head;
    struct Node* curr2 = head->next;
    while(curr1!= NULL && curr2!= NULL){
        if(curr1->data!= curr2->data)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}

int main(){
    struct Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);
    printf("Original list: ");
    printList(head);
    if(isPalindrome(head))
        printf("\nThe list is a palindrome.\n");
    else
        printf("\nThe list is not a palindrome.\n");
    return 0;
}