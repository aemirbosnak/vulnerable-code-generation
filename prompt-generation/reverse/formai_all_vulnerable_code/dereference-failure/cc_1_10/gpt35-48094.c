//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* skill;
    char* experience;
    char* education;
} Resume;

int main() {
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    resume->name = "Happy Bot";
    resume->skill = "Chatbot programming";
    resume->experience = "2 years";
    resume->education = "Bachelor's degree in Computer Science";
    
    char input[100];
    printf("Enter your resume: ");
    fgets(input, 100, stdin);
    
    char* attribute = strtok(input, " ");
    char* value = strtok(NULL, "\n");

    while(attribute != NULL && value != NULL) {
        if(strcmp(attribute, "name") == 0) {
            free(resume->name);
            resume->name = strdup(value);
        } else if(strcmp(attribute, "skill") == 0) {
            free(resume->skill);
            resume->skill = strdup(value);
        } else if(strcmp(attribute, "experience") == 0) {
            free(resume->experience);
            resume->experience = strdup(value);
        } else if(strcmp(attribute, "education") == 0) {
            free(resume->education);
            resume->education = strdup(value);
        } else {
            printf("Invalid attribute.\n");
        }
        
        attribute = strtok(NULL, " ");
        value = strtok(NULL, "\n");
    }
    
    printf("Name: %s\n", resume->name);
    printf("Skill: %s\n", resume->skill);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
    
    free(resume->name);
    free(resume->skill);
    free(resume->experience);
    free(resume->education);
    free(resume);
    
    return 0;
}