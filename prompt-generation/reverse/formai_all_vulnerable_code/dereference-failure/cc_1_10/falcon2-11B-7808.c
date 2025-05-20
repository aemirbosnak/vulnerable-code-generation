//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Person {
    char *name;
    char *position;
    char *company;
    char *email;
};

struct Person *read_resume(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    struct Person *person = NULL;
    while (fscanf(file, "%s %s %s %s\n", person->name, person->position, person->company, person->email) == 4) {
        if (person == NULL) {
            person = malloc(sizeof(struct Person));
            if (person == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
        } else {
            free(person);
            person = malloc(sizeof(struct Person));
            if (person == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
    return person;
}

int main() {
    struct Person *person = read_resume("resume.txt");
    if (person!= NULL) {
        printf("Name: %s\n", person->name);
        printf("Position: %s\n", person->position);
        printf("Company: %s\n", person->company);
        printf("Email: %s\n", person->email);
        free(person);
    } else {
        printf("Failed to read the resume file.\n");
    }

    return 0;
}