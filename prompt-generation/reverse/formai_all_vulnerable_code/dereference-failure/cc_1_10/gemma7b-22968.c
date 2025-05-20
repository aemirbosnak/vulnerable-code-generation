//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    struct Resume *next;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp;
    Resume *head = NULL;
    Resume *current = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the resume line by line
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Extract the relevant information from the line
        char *name = strstr(line, "Name:");
        char *email = strstr(line, "Email:");
        char *phone = strstr(line, "Phone:");
        char *address = strstr(line, "Address:");
        char *summary = strstr(line, "Summary:");

        // Create a new resume node
        Resume *new_resume = malloc(sizeof(Resume));
        new_resume->name = strdup(name);
        new_resume->email = strdup(email);
        new_resume->phone = strdup(phone);
        new_resume->address = strdup(address);
        new_resume->summary = strdup(summary);
        new_resume->next = NULL;

        // If the head of the list is NULL, make it the head
        if (head == NULL) {
            head = new_resume;
        } else {
            // Otherwise, add the node to the end of the list
            current->next = new_resume;
        }

        current = new_resume;
    }

    fclose(fp);

    return head;
}

int main() {
    char *filename = "resume.txt";
    Resume *head = parse_resume(filename);

    // Print the resume information
    for (Resume *current = head; current; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("Address: %s\n", current->address);
        printf("Summary: %s\n", current->summary);
        printf("\n");
    }

    return 0;
}