//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 5000
#define MAX_SKILLS 10

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills[MAX_SKILLS];
} Resume;

void parseResume(char* resumeText, Resume* resume);

int main() {
    char resumeText[MAX_RESUME_SIZE];
    Resume resume = {0};
    
    printf("Please input resume text: ");
    fgets(resumeText, MAX_RESUME_SIZE, stdin);
    
    parseResume(resumeText, &resume);
    
    printf("\nParsed Resume:\n");
    printf("Name:\t%s\n", resume.name);
    printf("Email:\t%s\n", resume.email);
    printf("Phone:\t%s\n", resume.phone);
    printf("Address:\t%s\n", resume.address);
    printf("Skills:\t");
    for(int i = 0; i < MAX_SKILLS; i++) {
        if(resume.skills[i] != NULL) {
            printf("%s, ", resume.skills[i]);
        }
    }
    printf("\n");
    
    return 0;
}

void parseResume(char* resumeText, Resume* resume) {
    char *token, *data;
    int skillCount = 0;
    
    // Parse Name
    token = strtok(resumeText, "\n");
    resume->name = strdup(token);
    
    // Parse Email
    token = strtok(NULL, "\n");
    resume->email = strdup(token);
    
    // Parse Phone
    token = strtok(NULL, "\n");
    resume->phone = strdup(token);
    
    // Parse Address
    token = strtok(NULL, "\n");
    resume->address = strdup(token);
    
    // Parse Skills
    token = strtok(NULL, ",");
    while(token != NULL && skillCount < MAX_SKILLS) {
        data = strdup(token);
        resume->skills[skillCount++] = data;
        token = strtok(NULL, ",");
    }
}