//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume_data {
    char* name;
    char* email;
    char* phone_number;
    char* address;
    char* summary;
    struct resume_data* next;
} resume_data;

resume_data* parse_resume(char* resume_text) {
    resume_data* head = NULL;
    char* line = strtok(resume_text, "\n");

    while (line) {
        // Extract data from the line
        char* name = strstr(line, "Name:");
        char* email = strstr(line, "Email:");
        char* phone_number = strstr(line, "Phone Number:");
        char* address = strstr(line, "Address:");
        char* summary = strstr(line, "Summary:");

        // Create a new resume data node
        resume_data* new_node = malloc(sizeof(resume_data));
        new_node->name = strdup(name);
        new_node->email = strdup(email);
        new_node->phone_number = strdup(phone_number);
        new_node->address = strdup(address);
        new_node->summary = strdup(summary);
        new_node->next = NULL;

        // Add the new node to the head of the list
        if (head == NULL) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }

        line = strtok(NULL, "\n");
    }

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone Number: 123-456-7890\nAddress: 123 Main St., New York, NY 10001\nSummary: Highly motivated and experienced professional with a strong track record of success in the technology industry.\n";

    resume_data* head = parse_resume(resume_text);

    while (head) {
        printf("Name: %s\n", head->name);
        printf("Email: %s\n", head->email);
        printf("Phone Number: %s\n", head->phone_number);
        printf("Address: %s\n", head->address);
        printf("Summary: %s\n", head->summary);
        printf("\n");

        head = head->next;
    }

    return 0;
}