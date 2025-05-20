//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store resume data
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *summary;
    struct resume *next;
} resume;

// Function to parse a resume file
void parse_resume(FILE *fp) {
    resume *head = NULL;
    resume *curr = NULL;

    // Read the resume file line by line
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Remove whitespace from the line
        char *p = line;
        while (*p) {
            if (*p == ' ' || *p == '\t' || *p == '\n') {
                *p = '\0';
            }
            p++;
        }

        // Create a new resume node if necessary
        if (head == NULL) {
            head = curr = malloc(sizeof(resume));
        } else {
            curr = curr->next = malloc(sizeof(resume));
            curr = curr->next;
        }

        // Store the resume data in the node
        curr->name = strdup(line);
        curr->email = strdup(line);
        curr->phone = strdup(line);
        curr->summary = strdup(line);
    }

    // Print the resume data
    curr = head;
    while (curr) {
        printf("Name: %s\n", curr->name);
        printf("Email: %s\n", curr->email);
        printf("Phone: %s\n", curr->phone);
        printf("Summary: %s\n", curr->summary);
        printf("\n");
        curr = curr->next;
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    parse_resume(fp);
    fclose(fp);

    return 0;
}