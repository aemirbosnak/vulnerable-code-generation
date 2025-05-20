//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a resume
typedef struct {
    char* name;
    char* city;
    char* skills[5];
} Resume;

// Define a struct to represent a parsed resume
typedef struct {
    char* name;
    char* city;
    char* skills;
} ParsedResume;

// Define a function to parse a resume
ParsedResume parseResume(Resume resume) {
    ParsedResume parsedResume;

    // Parse the name
    char* space = strstr(resume.name, " ");
    space[0] = '\0';
    parsedResume.name = resume.name;

    // Parse the city
    parsedResume.city = resume.city;

    // Parse the skills
    parsedResume.skills = malloc(sizeof(char) * 50);
    for (int i = 0; i < 5; i++) {
        strcat(parsedResume.skills, resume.skills[i]);
        if (i < 4) {
            strcat(parsedResume.skills, ", ");
        }
    }

    return parsedResume;
}

int main() {
    // Define a resume
    Resume resume;
    resume.name = "Sir Lancelot of Camelot";
    resume.city = "Camelot";
    resume.skills[0] = "Jousting";
    resume.skills[1] = "Sword Fighting";
    resume.skills[2] = "Horse Riding";
    resume.skills[3] = "Bow and Arrow";
    resume.skills[4] = "Chivalry";

    // Parse the resume
    ParsedResume parsedResume = parseResume(resume);

    // Print the parsed resume
    printf("Name: %s\n", parsedResume.name);
    printf("City: %s\n", parsedResume.city);
    printf("Skills: %s\n", parsedResume.skills);

    // Free the memory allocated for the parsed skills
    free(parsedResume.skills);

    return 0;
}