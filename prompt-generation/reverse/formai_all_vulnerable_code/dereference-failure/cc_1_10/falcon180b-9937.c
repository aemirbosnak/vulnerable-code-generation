//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000

struct node {
    char line[MAX_LINE];
    struct node* next;
};

struct node* createNode(char* line) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(newNode->line, line);
    newNode->next = NULL;
    return newNode;
}

void addNode(struct node** head, char* line) {
    struct node* newNode = createNode(line);
    struct node* temp = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->line);
        temp = temp->next;
    }
}

int main() {
    FILE* fp;
    char line[MAX_LINE];
    struct node* head = NULL;

    fp = fopen("backup.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        addNode(&head, line);
    }

    fclose(fp);

    printf("Backup file content:\n");
    printList(head);

    return 0;
}