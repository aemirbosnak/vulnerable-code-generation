//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold the data
typedef struct DataNode {
    char name[50]; // user name
    int age; // user age
    struct DataNode* next;
} DataNode;

// function to create a new DataNode
DataNode* createNewDataNode(char name[], int age) {
    DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// function to insert a new DataNode at the beginning of the list
DataNode* insertDataNode(DataNode** headRef, char name[], int age) {
    DataNode* newNode = createNewDataNode(name, age);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    return newNode; 
}

// function to delete a DataNode from the list
DataNode* deleteDataNode(DataNode** headRef, char name[]) {
    if ((*headRef) == NULL) {
        return NULL;
    }
    if (strcmp((*headRef)->name, name) == 0) {
        DataNode* temp = (*headRef);
        (*headRef) = (*headRef)->next;
        free(temp);
        return *headRef;
    } else {
        return deleteDataNode(&((*headRef)->next), name);
    }
}

// function to find a DataNode in the list
DataNode* findDataNode(DataNode** headRef, char name[]) {
    if ((*headRef) == NULL) {
        return NULL;
    }
    if (strcmp((*headRef)->name, name) == 0) {
        return *headRef;
    } else {
        return findDataNode(&((*headRef)->next), name);
    }
}

// function to print the list
void printList(DataNode** headRef) {
    if (*headRef == NULL) {
        printf("The list is empty.\n");
    } else {
        DataNode* curr = (*headRef);
        while (curr != NULL) {
            printf("%s\t%d\n", curr->name, curr->age);
            curr = curr->next;
        }
    }
}

// main function
int main() {
    DataNode* myData = NULL; // initialize the list
    
    // insert some test data
    insertDataNode(&myData, "John", 35);
    insertDataNode(&myData, "Mary", 25);
    insertDataNode(&myData, "Bob", 40);
    
    // print the original list
    printf("Original List:\n");
    printList(&myData);
    
    // delete a DataNode and print the updated list
    printf("\nDeleting Mary...\n");
    deleteDataNode(&myData, "Mary");
    printList(&myData);
    
    // find a DataNode and print its contents
    printf("\nFinding John...\n");
    DataNode* john = findDataNode(&myData, "John");
    if (john == NULL) {
        printf("John was not found.\n");
    } else {
        printf("%s\t%d\n", john->name, john->age);
    }
    
    return 0;
}