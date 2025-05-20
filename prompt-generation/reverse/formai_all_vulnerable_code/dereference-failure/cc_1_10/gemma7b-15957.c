//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char summary[200];
    struct Resume* next;
} Resume;

Resume* parseResume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char line[200];
    Resume* head = NULL;
    Resume* current = NULL;

    while (fgets(line, 200, file) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        if (head == NULL) {
            head = current = malloc(sizeof(Resume));
            strcpy(head->name, line);
        } else {
            current->next = malloc(sizeof(Resume));
            current = current->next;
            strcpy(current->name, line);
        }
    }

    fclose(file);
    return head;
}

int main() {
    char* filename = "resume.txt";
    Resume* head = parseResume(filename);

    if (head) {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("Phone: %s\n", head->phone);
        printf("Email: %s\n", head->email);
        printf("Summary: %s\n", head->summary);
    } else {
        printf("Error parsing resume.\n");
    }

    return 0;
}