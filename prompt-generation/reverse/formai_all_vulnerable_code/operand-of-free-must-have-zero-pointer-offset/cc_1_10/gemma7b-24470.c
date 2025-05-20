//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char *resume)
{
    char *name = NULL;
    char *position = NULL;
    char *summary = NULL;
    char *skills = NULL;
    char *education = NULL;
    char *experience = NULL;

    // Allocate memory for each pointer
    name = malloc(256);
    position = malloc(256);
    summary = malloc(256);
    skills = malloc(256);
    education = malloc(256);
    experience = malloc(256);

    // Parse the resume and extract the relevant information
    name = strstr(resume, "Name:");
    position = strstr(resume, "Position:");
    summary = strstr(resume, "Summary:");
    skills = strstr(resume, "Skills:");
    education = strstr(resume, "Education:");
    experience = strstr(resume, "Experience:");

    // Print the extracted information
    printf("Name: %s\n", name);
    printf("Position: %s\n", position);
    printf("Summary: %s\n", summary);
    printf("Skills: %s\n", skills);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);

    // Free the allocated memory
    free(name);
    free(position);
    free(summary);
    free(skills);
    free(education);
    free(experience);
}

int main()
{
    char *resume = "John Doe\nPosition: Software Engineer\nSummary: Experienced software engineer with a strong background in Java and C++.\nSkills: Java, C++, Python, SQL, NoSQL\nEducation: Bachelor's degree in Computer Science\nExperience: Software Engineer at ACM Corporation, New York, NY, 2010-2015";

    parse_resume(resume);

    return 0;
}