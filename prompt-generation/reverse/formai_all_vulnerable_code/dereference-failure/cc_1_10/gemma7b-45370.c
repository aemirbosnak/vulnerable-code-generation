//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct resume_entry {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct resume_entry* next;
} resume_entry;

resume_entry* parse_resume(char* resume_text) {
    // Allocate memory for the resume entry
    resume_entry* new_entry = malloc(sizeof(resume_entry));

    // Extract the name from the resume text
    char* name_start = strstr(resume_text, "Name:");
    char* name_end = strstr(name_start, ",");
    strncpy(new_entry->name, name_start + 5, name_end - name_start - 5);

    // Extract the experience from the resume text
    char* experience_start = strstr(resume_text, "Experience:");
    char* experience_end = strstr(experience_start, "Skills:");
    strncpy(new_entry->experience, experience_start + 9, experience_end - experience_start - 9);

    // Link the new entry to the next entry
    new_entry->next = NULL;

    return new_entry;
}

int main() {
    // Example resume text
    char* resume_text = "Name: John Doe,\n"
                           "Experience:\n"
                           "Software Engineer at Google,\n"
                           "2018-2022\n"
                           "Designed and developed software for various clients.\n"
                           "Skills:\n"
                           "Java, C++, Python";

    // Parse the resume text
    resume_entry* new_entry = parse_resume(resume_text);

    // Print the name and experience
    printf("Name: %s\n", new_entry->name);
    printf("Experience:\n%s\n", new_entry->experience);

    return 0;
}