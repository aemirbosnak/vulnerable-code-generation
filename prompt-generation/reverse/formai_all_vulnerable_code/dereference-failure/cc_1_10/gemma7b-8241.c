//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ResumeEntry
{
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    struct ResumeEntry *next;
} ResumeEntry;

void parseResume(char *resumeText)
{
    ResumeEntry *head = NULL;
    char *line = strtok(resumeText, "\n");
    while (line)
    {
        char *name = strstr(line, "Name:");
        char *email = strstr(line, "Email:");
        char *phone = strstr(line, "Phone:");
        char *address = strstr(line, "Address:");
        char *summary = strstr(line, "Summary:");

        if (name && email && phone && address && summary)
        {
            ResumeEntry *newEntry = malloc(sizeof(ResumeEntry));
            newEntry->name = strdup(name);
            newEntry->email = strdup(email);
            newEntry->phone = strdup(phone);
            newEntry->address = strdup(address);
            newEntry->summary = strdup(summary);
            newEntry->next = head;
            head = newEntry;
        }
        line = strtok(NULL, "\n");
    }

    // Print the parsed resume entries
    ResumeEntry *current = head;
    while (current)
    {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("Address: %s\n", current->address);
        printf("Summary: %s\n", current->summary);
        printf("\n");
        current = current->next;
    }
}

int main()
{
    char *resumeText = "Name: John Doe\nEmail: john.doe@example.com\nPhone: (123) 456-7890\nAddress: 123 Main St., New York, NY 10001\nSummary: Experienced software engineer with a strong background in Java and C++.\n\nName: Jane Doe\nEmail: jane.doe@example.com\nPhone: (456) 789-0123\nAddress: 456 Oak Ave., Los Angeles, CA 90028\nSummary: Highly motivated marketing professional with a passion for social media marketing.\n";

    parseResume(resumeText);

    return 0;
}