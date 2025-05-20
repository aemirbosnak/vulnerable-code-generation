//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000

char* resume = "Name: John Smith\n\nSkills: C Programming Language\n\nExperience: 2 years\n\nEducation: Bachelor's degree in Computer Science\n\n";

int main() {
    char* name;
    char* skills;
    char* experience;
    char* education;
    char* ptr = resume;
    char* end_ptr;

    printf("Parsing resume...\n");

    // Extract name
    ptr = strstr(ptr, "Name: ");
    end_ptr = strstr(ptr, "\n\n");
    int name_len = end_ptr - ptr - 6;
    name = (char *) malloc(name_len + 1);
    strncpy(name, ptr+6, name_len);
    name[name_len] = '\0';
    ptr = end_ptr;

    // Extract skills
    ptr = strstr(ptr, "Skills: ");
    end_ptr = strstr(ptr, "\n\n");
    int skills_len = end_ptr - ptr - 8;
    skills = (char *) malloc(skills_len + 1);
    strncpy(skills, ptr+8, skills_len);
    skills[skills_len] = '\0';
    ptr = end_ptr;

    // Extract experience
    ptr = strstr(ptr, "Experience: ");
    end_ptr = strstr(ptr, "\n\n");
    int experience_len = end_ptr - ptr - 12;
    experience = (char *) malloc(experience_len + 1);
    strncpy(experience, ptr+12, experience_len);
    experience[experience_len] = '\0';
    ptr = end_ptr;

    // Extract education
    ptr = strstr(ptr, "Education: ");
    end_ptr = strstr(ptr, "\n\n");
    int education_len = end_ptr - ptr - 11;
    education = (char *) malloc(education_len + 1);
    strncpy(education, ptr+11, education_len);
    education[education_len] = '\0';
    ptr = end_ptr;

    printf("Name: %s\nSkills: %s\nExperience: %s\nEducation: %s\n", name, skills, experience, education);

    free(name);
    free(skills);
    free(experience);
    free(education);

    return 0;
}