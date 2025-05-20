//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define LINE_LENGTH 256

typedef struct Line {
    char data[LINE_LENGTH];
    struct Line *next;
} Line;

void readFile(FILE *file, Line **head) {
    Line *current, *newLine;

    while (fgets((*head)->data, LINE_LENGTH, file) != NULL) {
        if (strlen((*head)->data) > 0 && (*head)->next == NULL) {
            newLine = (Line *)malloc(sizeof(Line));
            strcpy(newLine->data, (*head)->data);
            newLine->next = *head;
            *head = newLine;
        } else if (strlen((*head)->data) > 0 && (*head)->next != NULL) {
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            newLine = (Line *)malloc(sizeof(Line));
            strcpy(newLine->data, (*head)->data);
            current->next = newLine;
            newLine->next = NULL;
        }
    }

    if (feof(file)) {
        newLine = (Line *)malloc(sizeof(Line));
        newLine->next = NULL;
        *head = newLine;
    }

    fclose(file);
}

void printList(Line *head) {
    Line *current = head;

    while (current != NULL) {
        printf("%s", current->data);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Line *head = NULL;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    readFile(file, &head);

    if (head == NULL) {
        printf("Error: Empty file\n");
        return 1;
    }

    printList(head);

    Line *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    fclose(file);
    return 0;
}