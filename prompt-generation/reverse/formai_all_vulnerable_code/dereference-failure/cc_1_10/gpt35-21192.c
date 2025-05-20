//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold the data from the input file
struct Data {
    char name[50];
    int age;
    double gpa;
};

//Struct for the linked list node
struct Node {
    struct Data data;
    struct Node* next;
};

//Function prototypes
void printData(struct Data data);
void printList(struct Node* head);
void insertData(struct Node** head, struct Data data);
void freeList(struct Node* head);

int main(void) {
    //Open input file
    FILE* fptr;
    fptr = fopen("data.txt", "r");
    if(fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    //Read data from input file
    char buffer[100];
    struct Node* head = NULL;
    while(fgets(buffer, sizeof(buffer), fptr) != NULL) {
        struct Data data;
        char* token = strtok(buffer, ",");
        strcpy(data.name, token);
        token = strtok(NULL, ",");
        data.age = atoi(token);
        token = strtok(NULL, ",");
        data.gpa = atof(token);
        insertData(&head, data);
    }
    fclose(fptr);
    
    //Print the linked list
    printList(head);
    
    //Free the memory used by the linked list
    freeList(head);
    return 0;
}

//Function to print a single data entry
void printData(struct Data data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("GPA: %.2f\n", data.gpa);
    printf("\n");
}

//Function to print the entire linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printData(current->data);
        current = current->next;
    }
}

//Function to insert a new data entry into the linked list
void insertData(struct Node** head, struct Data data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

//Function to free the memory used by the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}