//FormAI DATASET v1.0 Category: Data recovery tool ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * This is a happy-style program for C data recovery tool example.
 * This program recovers deleted files from a hard drive.
 * The recovered data is saved in a new file.
 * It brings happiness to those who have lost their valuable data.
 */

typedef struct node {
    char data;
    struct node* next;
}Node;

// Function to create a linked list of characters from a string
Node* createLinkedList(char* str) {
    Node* head = NULL;
    int len = strlen(str);
    for(int i=0;i<len;i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = str[i];
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// Function to reverse a linked list of characters
Node* reverseLinkedList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to check if two linked lists of characters are identical
int isEqual(Node* list1, Node* list2) {
    while(list1 != NULL && list2 != NULL) {
        if(list1->data != list2->data) {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    if(list1 == NULL && list2 == NULL) {
        return 1;
    }
    return 0;
}

// Function to recover deleted data from a hard drive
void dataRecovery(char* fileName, char* deletedStr) {
    FILE* fp;
    fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    
    char buffer[101];
    int flag = 0;
    
    while(fgets(buffer, 100, fp)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from the end of the string
        Node* original = createLinkedList(buffer); // Create a linked list of characters from the original string
        Node* reversed = reverseLinkedList(original); // Reverse the linked list of characters
        if(isEqual(reversed, createLinkedList(deletedStr))) { // Check if the reversed linked list of characters is equal to the linked list of characters created from the deleted string
            printf("Match found!\n");
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) {
        printf("Error: Could not find a match for the deleted data\n");
        return;
    }
    
    FILE* fp2;
    fp2 = fopen("recovered.txt", "w"); // Create a new file for the recovered data
    if(fp2 == NULL) {
        printf("Error: Could not create file\n");
        return;
    }
    
    fprintf(fp2, "%s", deletedStr); // Write the recovered data to the new file
    
    fclose(fp);
    fclose(fp2);
    printf("Data recovery completed successfully!\n");
}

int main() {
    char fileName[101];
    char deletedStr[101];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the deleted string: ");
    scanf("%s", deletedStr);
    dataRecovery(fileName, deletedStr);
    return 0;
}