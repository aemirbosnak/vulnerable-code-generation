//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ResumeNode {
    char *name;
    char *email;
    char *phone;
    char *skills;
    struct ResumeNode *next;
} ResumeNode;

ResumeNode *create_resume(char *name, char *email, char *phone, char *skills) {
    ResumeNode *new_resume = (ResumeNode *)malloc(sizeof(ResumeNode));
    new_resume->name = strdup(name);
    new_resume->email = strdup(email);
    new_resume->phone = strdup(phone);
    new_resume->skills = strdup(skills);
    new_resume->next = NULL;
    return new_resume;
}

void add_resume(ResumeNode **head, ResumeNode *new_resume) {
    if (*head == NULL) {
        *head = new_resume;
    } else {
        ResumeNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_resume;
    }
}

void print_resume(ResumeNode *head) {
    ResumeNode *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("Skills: %s\n", current->skills);
        printf("\n");
        current = current->next;
    }
}

int main() {
    // Create a linked list of resumes
    ResumeNode *head = NULL;
    add_resume(&head, create_resume("John Doe", "john.doe@example.com", "555-123-4567", "C, C++, Java, Python"));
    add_resume(&head, create_resume("Jane Doe", "jane.doe@example.com", "555-234-5678", "C#, VB.NET, SQL Server"));
    add_resume(&head, create_resume("John Smith", "john.smith@example.com", "555-345-6789", "PHP, MySQL, HTML, CSS"));

    // Print the list of resumes
    print_resume(head);

    return 0;
}