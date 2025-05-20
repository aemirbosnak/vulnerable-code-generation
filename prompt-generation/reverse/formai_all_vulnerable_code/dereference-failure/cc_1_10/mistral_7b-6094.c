//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char gender;
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

Node *head = NULL;

void parseLine(char *line) {
    Person newPerson;
    char *token, *tokenType;
    int index = 0;

    token = strtok(line, ",");
    strcpy(newPerson.name, token);

    tokenType = strtok(NULL, ",");
    token = strtok(NULL, ",");

    if (strcmp(tokenType, "age") == 0) {
        newPerson.age = atoi(token);
    } else if (strcmp(tokenType, "gender") == 0) {
        newPerson.gender = token[0];
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newPerson;
    newNode->next = head;
    head = newNode;
}

int main() {
    FILE *file;
    char line[100];

    file = fopen("resumes.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        parseLine(line);
    }

    Node *current = head;

    printf("Resumes:\n");

    while (current != NULL) {
        printf("\nName: %s\nAge: %d\nGender: %c", current->data.name, current->data.age, current->data.gender);
        current = current->next;
    }

    fclose(file);
    return 0;
}