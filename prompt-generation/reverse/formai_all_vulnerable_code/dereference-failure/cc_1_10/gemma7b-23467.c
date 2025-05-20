//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Cv {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Cv* next;
} Cv;

void parse_resume(Cv* cv_head) {
    FILE* resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        return;
    }

    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, resume_file) != NULL) {
        // Extract name and age from the line
        char* name = strtok(line, ":");
        int age = atoi(strtok(name, ","));

        // Create a new CV node
        Cv* new_cv = malloc(sizeof(Cv));
        new_cv->name[0] = '\0';
        strncpy(new_cv->name, name, MAX_NAME_LENGTH - 1);
        new_cv->age = age;
        new_cv->next = NULL;

        // Insert the new CV node into the linked list
        if (cv_head == NULL) {
            cv_head = new_cv;
        } else {
            cv_head->next = new_cv;
            cv_head = new_cv;
        }
    }

    fclose(resume_file);
}

int main() {
    Cv* cv_head = NULL;
    parse_resume(cv_head);

    // Print the CV list
    Cv* current_cv = cv_head;
    while (current_cv) {
        printf("%s (%d)\n", current_cv->name, current_cv->age);
        current_cv = current_cv->next;
    }

    return 0;
}