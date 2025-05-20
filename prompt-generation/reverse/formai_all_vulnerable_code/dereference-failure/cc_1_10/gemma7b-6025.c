//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 1000

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    struct Resume* next;
} Resume;

void parseResume(char* resumeText)
{
    // Allocate memory for the resume structure
    Resume* resume = malloc(sizeof(Resume));

    // Extract the name from the resume text
    char* name = strstr(resumeText, "Name:");
    if (name)
    {
        name += 5;
        strncpy(resume->name, name, MAX_NAME_LENGTH - 1);
    }

    // Extract the experience from the resume text
    char* experience = strstr(resumeText, "Experience:");
    if (experience)
    {
        experience += 9;
        strncpy(resume->experience, experience, MAX_EXPERIENCE_LENGTH - 1);
    }

    // Link the resume structure to the next resume
    resume->next = NULL;

    // Print the resume information
    printf("Name: %s\n", resume->name);
    printf("Experience: %s\n", resume->experience);
}

int main()
{
    // Sample resume text
    char* resumeText = "Name: John Doe\nExperience: Software Engineer at Google\n\n"
                           "Skills: Java, C++, Python\n\n"
                           "Education: Bachelor's degree in Computer Science\n";

    // Parse the resume text
    parseResume(resumeText);

    return 0;
}