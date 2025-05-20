//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Node structure for Linked List
struct Node{
    char *data;
    struct Node *next;
};

//Function to create a new node with given data
struct Node* newNode(char *data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

//Function to print the linked list
void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%s ", temp->data);
        temp = temp->next;
    }
}

//Function to add an element to the linked list
void addElement(struct Node** head, char* data){
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
}

//Function to free the memory allocated by linked list nodes
void freeList(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        free(temp->data);
        temp = temp->next;
        free(temp);
    }
}

//Function to parse the given resume and store the data in linked list
void parseResume(FILE* resume, struct Node** head){
    char line[1000];
    while(fgets(line, sizeof(line), resume)!= NULL){
        int i = 0;
        while(line[i]!= ':'){
            i++;
        }
        line[i] = '\0';
        char* key = line;
        char* value = &line[i+1];
        addElement(head, value);
    }
}

//Main function
int main(){
    FILE* resume = fopen("resume.txt", "r");
    if(resume == NULL){
        printf("Error opening resume file.\n");
        exit(1);
    }
    struct Node* head = NULL;
    parseResume(resume, &head);
    printList(head);
    freeList(head);
    fclose(resume);
    return 0;
}