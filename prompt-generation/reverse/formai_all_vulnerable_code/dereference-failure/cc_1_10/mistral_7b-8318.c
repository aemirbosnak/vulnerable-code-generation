//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define CAT_SIZE 50

typedef struct cat {
    char name[CAT_SIZE];
    int age;
    struct cat *next;
} Cat;

void translate(char *line, Cat **head) {
    char *token, str[MAX_LINE];
    int i;
    Cat *temp, *newCat;

    strcpy(str, line);
    token = strtok(str, " ");

    while (token != NULL) {
        newCat = (Cat *)malloc(sizeof(Cat));

        strcpy(newCat->name, token);

        for (i = 0; i < strlen(token); i++) {
            if (token[i] >= 'A' && token[i] <= 'Z') {
                newCat->name[i] += 32;
            }
        }

        token = strtok(NULL, " ");

        if (token != NULL) {
            newCat->age = atoi(token);
        } else {
            newCat->age = 0;
        }

        newCat->next = *head;
        *head = newCat;

        token = strtok(NULL, " ");
    }

    printf("Translated line: ");
    Cat *current = *head;

    while (current != NULL) {
        printf("%s (%d years)", current->name, current->age);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    Cat *head = NULL;

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, fp) != NULL) {
        translate(line, &head);
    }

    fclose(fp);

    Cat *current = head;

    while (current != NULL) {
        Cat *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}