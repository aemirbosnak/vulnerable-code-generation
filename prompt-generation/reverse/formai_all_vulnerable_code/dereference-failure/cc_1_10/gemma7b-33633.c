//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    int experience_years;
    char** skills;
    struct Resume* next;
} Resume;

Resume* parse_resume(char* resume_text) {
    // Allocate memory for the resume structure
    Resume* resume = malloc(sizeof(Resume));
    resume->next = NULL;

    // Extract the name, experience years, and skills from the resume text
    char* name = strstr(resume_text, "Name:");
    if (name) {
        name += 5;
        strcpy(resume->name, name);
    }

    char* experience_years_str = strstr(resume_text, "Experience Years:");
    if (experience_years_str) {
        experience_years_str += 14;
        resume->experience_years = atoi(experience_years_str);
    }

    char* skills_str = strstr(resume_text, "Skills:");
    if (skills_str) {
        skills_str += 6;
        resume->skills = malloc(sizeof(char*) * 10);
        char** skills = resume->skills;
        int i = 0;
        while (i < 10 && (skills_str = strstr(skills_str, ",")) != NULL) {
            *skills++ = strdup(skills_str + 1);
            skills_str = strstr(skills_str, ",");
            i++;
        }
        *skills = NULL;
    }

    return resume;
}

int main() {
    char* resume_text = "Name: John Doe\nExperience Years: 5\nSkills: Java, Python, C++, SQL";

    Resume* resume = parse_resume(resume_text);

    printf("Name: %s\n", resume->name);
    printf("Experience Years: %d\n", resume->experience_years);
    printf("Skills: ");
    for (char** skill = resume->skills; *skill; skill++) {
        printf("%s, ", *skill);
    }

    free(resume);

    return 0;
}