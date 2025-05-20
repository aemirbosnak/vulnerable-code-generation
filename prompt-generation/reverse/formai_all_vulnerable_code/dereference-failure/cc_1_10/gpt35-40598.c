//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* name;
    char* email;
    char* skills[10];
    int num_skills;
} Resume;

bool parse_resume(Resume* resume, char* resume_string) {
    if (strstr(resume_string, "Name:") == NULL) {
        printf("Error: No name found in resume\n");
        return false;
    }
    resume->name = strtok(resume_string, ":");
    char* name = strtok(NULL, "\n");
    resume->name = (char*) malloc(sizeof(char) * strlen(name));
    strcpy(resume->name, name);

    if (strstr(resume_string, "Email:") == NULL) {
        printf("Error: No email found in resume\n");
        return false;
    }
    resume->email = strtok(NULL, ":");
    char* email = strtok(NULL, "\n");
    resume->email = (char*) malloc(sizeof(char) * strlen(email));
    strcpy(resume->email, email);

    char* skills_str = strstr(resume_string, "Skills:");
    if (skills_str == NULL) {
        printf("Error: No skills found in resume\n");
        return false;
    }
    skills_str += strlen("Skills:");
    char* skill = strtok(skills_str, ",");
    int i = 0;
    while (skill != NULL) {
        if (i >= 10) {
            printf("Error: Too many skills found in resume\n");
            return false;
        }
        resume->skills[i] = (char*) malloc(sizeof(char) * strlen(skill));
        strcpy(resume->skills[i], skill);
        i++;
        skill = strtok(NULL, ",");
    }
    resume->num_skills = i;
    return true;
}

int main() {
    char* resume_str = "Name: John Doe\nEmail: john.doe@gmail.com\nSkills: C++, Java, Python, SQL\n";
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    bool success = parse_resume(resume, resume_str);
    if (success) {
        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Skills:\n");
        for (int i = 0; i < resume->num_skills; i++) {
            printf(" - %s\n", resume->skills[i]);
        }
    }
    return 0;
}