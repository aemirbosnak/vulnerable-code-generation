//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NAME_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    char *name;
    int age;
    char *email;
    char *phone;
} person_t;

void parse_resume(person_t *person, char *line) {
    char *name = strtok(line, ":");
    char *value = strtok(NULL, ":");

    if (strcmp(name, "name") == 0) {
        strncpy(person->name, value, MAX_NAME_SIZE);
    } else if (strcmp(name, "age") == 0) {
        person->age = atoi(value);
    } else if (strcmp(name, "email") == 0) {
        strncpy(person->email, value, MAX_VALUE_SIZE);
    } else if (strcmp(name, "phone") == 0) {
        strncpy(person->phone, value, MAX_VALUE_SIZE);
    }
}

void print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Email: %s\n", person->email);
    printf("Phone: %s\n", person->phone);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s resume.txt\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    person_t person;
    memset(&person, 0, sizeof(person_t));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        parse_resume(&person, line);
    }

    fclose(fp);

    print_person(&person);

    return 0;
}