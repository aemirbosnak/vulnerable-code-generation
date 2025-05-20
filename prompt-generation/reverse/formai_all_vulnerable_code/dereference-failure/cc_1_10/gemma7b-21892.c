//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ resumes 1000

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    struct resume *next;
} resume_t;

void parse_resumes(resume_t **head) {
    FILE *fp;
    resume_t *new_resume;
    char line[256];

    fp = fopen("resumes.txt", "r");
    if (fp == NULL) {
        return;
    }

    while (fgets(line, 256, fp) != NULL) {
        new_resume = malloc(sizeof(resume_t));
        new_resume->name = strdup(line);
        fgets(line, 256, fp);
        new_resume->email = strdup(line);
        fgets(line, 256, fp);
        new_resume->phone = strdup(line);
        fgets(line, 256, fp);
        new_resume->address = strdup(line);
        fgets(line, 256, fp);
        new_resume->summary = strdup(line);

        if (*head == NULL) {
            *head = new_resume;
        } else {
            (*head)->next = new_resume;
            *head = new_resume;
        }
    }

    fclose(fp);
}

int main() {
    resume_t *head = NULL;
    parse_resumes(&head);

    // Print resumes
    for (resume_t *curr = head; curr; curr = curr->next) {
        printf("Name: %s\n", curr->name);
        printf("Email: %s\n", curr->email);
        printf("Phone: %s\n", curr->phone);
        printf("Address: %s\n", curr->address);
        printf("Summary: %s\n", curr->summary);
        printf("\n");
    }

    return 0;
}