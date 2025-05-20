//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    // Structure definition for a simple person record
    typedef struct {
        char first_name[50];
        char last_name[50];
        int age;
    } person_record;

    // Function prototype for extracting a person record from a CSV file
    person_record* extract_person_record(FILE* file);

#ifdef __cplusplus
}
#endif

int main(int argc, char** argv) {
    FILE* file = NULL;
    person_record* person = NULL;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    person = extract_person_record(file);
    if (!person) {
        fprintf(stderr, "Error extracting person record\n");
        fclose(file);
        return 1;
    }

    printf("First name: %s\n", person->first_name);
    printf("Last name: %s\n", person->last_name);
    printf("Age: %d\n", person->age);

    free(person);
    fclose(file);

    return 0;
}

// Function for extracting a person record from a CSV file
person_record* extract_person_record(FILE* file) {
    char line[1024] = {0};
    char* token = NULL;
    person_record* person = NULL;

    if (getline(&line, sizeof(line), file) == -1) {
        return NULL;
    }

    person = malloc(sizeof(person_record));
    if (!person) {
        perror("Error allocating memory");
        free(line);
        return NULL;
    }

    token = strtok(line, ",");
    strcpy(person->first_name, token);
    token = strtok(NULL, ",");
    strcpy(person->last_name, token);
    token = strtok(NULL, ",");
    person->age = atoi(token);

    free(line);

    return person;
}