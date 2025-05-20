//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Define a struct for the resume parsed data
typedef struct {
    char name[MAX_BUFFER_SIZE];
    char email[MAX_BUFFER_SIZE];
    char phone[MAX_BUFFER_SIZE];
    char skills[MAX_BUFFER_SIZE];
} Resume;

// Define a function to parse the resume and update the Resume struct
void parseResume(char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_BUFFER_SIZE];

    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        if (strstr(buffer, "Name: ")) {
            strncpy(resume->name, buffer+strlen("Name: "), MAX_BUFFER_SIZE);
        }
        else if (strstr(buffer, "Email: ")) {
            strncpy(resume->email, buffer+strlen("Email: "), MAX_BUFFER_SIZE);
        }
        else if (strstr(buffer, "Phone: ")) {
            strncpy(resume->phone, buffer+strlen("Phone: "), MAX_BUFFER_SIZE);
        }
        else if (strstr(buffer, "Skills: ")) {
            strncpy(resume->skills, buffer+strlen("Skills: "), MAX_BUFFER_SIZE);
        }
    }

    fclose(file);
}

int main(int argc, char **argv)
{
    char *filename = argv[1];
    Resume resume;

    parseResume(filename, &resume);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    
    return 0;
}