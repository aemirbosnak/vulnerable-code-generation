//Gemma-7B DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct File {
    char name[MAX_SIZE];
    FILE *fp;
    struct File *next;
} File;

void insertFile(File **head, char *name) {
    File *newNode = malloc(sizeof(File));
    strcpy(newNode->name, name);
    newNode->fp = fopen(name, "r");
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void readFiles(File *head) {
    FILE *fp;
    char line[MAX_SIZE];

    while (head) {
        fp = head->fp;
        printf("File: %s\n", head->name);

        while (fgets(line, MAX_SIZE, fp) != NULL) {
            printf("  Line: %s\n", line);
        }

        fclose(fp);
        head = head->next;
    }
}

int main() {
    File *head = NULL;

    insertFile(&head, "romeo.txt");
    insertFile(&head, "juliet.txt");
    insertFile(&head, "mercutio.txt");

    readFiles(head);

    return 0;
}