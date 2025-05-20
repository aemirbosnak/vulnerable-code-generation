//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *first_name;
    char *last_name;
    int age;
} person;

void free_person(person *p) {
    free(p->first_name);
    free(p->last_name);
    free(p);
}

person *parse_person(char *line) {
    char *delimiter = ",";
    char *token;

    // parse first name
    token = strtok(line, delimiter);
    if (!token) {
        return NULL;
    }
    char *first_name = (char *) malloc(strlen(token) + 1);
    strcpy(first_name, token);

    // parse last name
    token = strtok(NULL, delimiter);
    if (!token) {
        free(first_name);
        return NULL;
    }
    char *last_name = (char *) malloc(strlen(token) + 1);
    strcpy(last_name, token);

    // parse age
    token = strtok(NULL, delimiter);
    if (!token) {
        free(first_name);
        free(last_name);
        return NULL;
    }
    int age = atoi(token);

    // create person
    person *p = (person *) malloc(sizeof(person));
    p->first_name = first_name;
    p->last_name = last_name;
    p->age = age;

    return p;
}

int main() {
    FILE *csv_file = fopen("sample.csv", "r");
    if (!csv_file) {
        printf("Failed to open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    person *p;

    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        line[strcspn(line, "\n")] = '\0'; // remove trailing newline

        p = parse_person(line);
        if (!p) {
            printf("Failed to parse person.\n");
            continue;
        }

        // print person
        printf("First Name: %s\n", p->first_name);
        printf("Last Name: %s\n", p->last_name);
        printf("Age: %d\n", p->age);

        free_person(p);
    }

    fclose(csv_file);
    return 0;
}