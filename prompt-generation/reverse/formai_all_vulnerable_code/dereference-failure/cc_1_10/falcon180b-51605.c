//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    char phone[MAX_SIZE];
    char email[MAX_SIZE];
    int experience;
    int education;
    struct resume *next;
} resume;

void addNode(resume **head, char *name, char *address, char *phone, char *email, int experience, int education) {
    resume *newNode = (resume *)malloc(sizeof(resume));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    strcpy(newNode->phone, phone);
    strcpy(newNode->email, email);
    newNode->experience = experience;
    newNode->education = education;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    resume *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printResume(resume *head) {
    resume *temp = head;
    while (temp!= NULL) {
        printf("Name: %s\n", temp->name);
        printf("Address: %s\n", temp->address);
        printf("Phone: %s\n", temp->phone);
        printf("Email: %s\n", temp->email);
        printf("Experience: %d\n", temp->experience);
        printf("Education: %d\n", temp->education);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    resume *head = NULL;

    addNode(&head, "John", "123 Main St", "555-1234", "johndoe@gmail.com", 5, 4);
    addNode(&head, "Jane", "456 Elm St", "555-5678", "janedoe@gmail.com", 3, 3);
    addNode(&head, "Bob", "789 Oak St", "555-9012", "bobsmith@gmail.com", 7, 2);

    printResume(head);

    return 0;
}