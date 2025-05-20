//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct resume_entry {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(char* resume_text) {
    resume_entry* head = NULL;
    char* name_start = NULL;
    char* name_end = NULL;
    char* occupation_start = NULL;
    char* occupation_end = NULL;
    int age = -1;

    // Allocate memory for the first entry
    head = malloc(sizeof(resume_entry));
    head->next = NULL;

    // Find the name and age
    name_start = strstr(resume_text, "Name:");
    if (name_start) {
        name_start += 5;
        name_end = strstr(name_start, "\n");
        strncpy(head->name, name_start, name_end - name_start);
    }

    // Find the occupation
    occupation_start = strstr(resume_text, "Occupation:");
    if (occupation_start) {
        occupation_start += 9;
        occupation_end = strstr(occupation_start, "\n");
        strncpy(head->occupation, occupation_start, occupation_end - occupation_start);
    }

    // Find the age
    age = atoi(strchr(resume_text, "Age:") + 5);
    head->age = age;

    return head;
}

int main() {
    char* resume_text = "Name: John Doe\nAge: 25\nOccupation: Software Engineer\n";

    resume_entry* head = parse_resume(resume_text);

    printf("Name: %s\n", head->name);
    printf("Age: %d\n", head->age);
    printf("Occupation: %s\n", head->occupation);

    return 0;
}