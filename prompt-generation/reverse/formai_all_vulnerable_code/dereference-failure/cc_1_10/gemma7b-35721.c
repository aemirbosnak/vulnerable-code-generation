//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ResumeEntry {
    char *name;
    char *email;
    char *phone;
    struct ResumeEntry *next;
} ResumeEntry;

ResumeEntry *parseResume(char *resumeText) {
    ResumeEntry *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *p = buffer;
    char *line = NULL;
    int lineNumber = 0;

    // Tokenize the resume text into lines
    line = strtok(resumeText, "\n");

    // Iterate over each line in the resume
    while (line) {
        // Extract the name, email, and phone from the line
        char *name = strstr(line, "Name:");
        char *email = strstr(line, "Email:");
        char *phone = strstr(line, "Phone:");

        // If the line contains a name, email, or phone, create a new resume entry
        if (name || email || phone) {
            ResumeEntry *newEntry = malloc(sizeof(ResumeEntry));
            newEntry->name = strdup(name);
            newEntry->email = strdup(email);
            newEntry->phone = strdup(phone);
            newEntry->next = head;
            head = newEntry;
        }

        // Move to the next line
        line = strtok(NULL, "\n");
        lineNumber++;
    }

    // Free the buffer and return the head of the resume entry list
    free(buffer);
    return head;
}

int main() {
    char *resumeText = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 123-456-7890\n\nName: Jane Doe\nEmail: jane.doe@example.com\nPhone: 456-789-0123";

    ResumeEntry *head = parseResume(resumeText);

    // Print the resume entries
    for (ResumeEntry *entry = head; entry; entry = entry->next) {
        printf("Name: %s\n", entry->name);
        printf("Email: %s\n", entry->email);
        printf("Phone: %s\n", entry->phone);
        printf("\n");
    }

    return 0;
}