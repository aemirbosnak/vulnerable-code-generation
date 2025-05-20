//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Resume* next;
} Resume;

int main() {
    Resume* head = NULL;
    char input[MAX_NAME_LENGTH];

    // Loop to read resumes
    while (1) {
        printf("Enter name: ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        Resume* new_resume = malloc(sizeof(Resume));
        strcpy(new_resume->name, input);

        // Read other resume details
        printf("Enter email: ");
        scanf("%s", new_resume->email);

        printf("Enter phone: ");
        scanf("%s", new_resume->phone);

        printf("Enter address: ");
        scanf("%s", new_resume->address);

        printf("Enter experience: ");
        scanf("%s", new_resume->experience);

        new_resume->next = head;
        head = new_resume;
    }

    // Print resumes
    for (Resume* current = head; current; current = current->next) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("Address: %s\n", current->address);
        printf("Experience: %s\n", current->experience);
        printf("\n");
    }

    return 0;
}