//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* skills;
} Resume;

void parseResume(char* filepath, Resume* resume) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        printf("Oops! Could not open the file: %s\n", filepath);
        return;
    }
    
    char line[1024];
    char* ptr;
    while (fgets(line, 1024, file)) {
        if (ptr = strtok(line, ":\n")) {
            if (strcmp(ptr, "Name") == 0) {
                resume->name = strdup(strtok(NULL, ":\n"));
            }
            else if (strcmp(ptr, "Email") == 0) {
                resume->email = strdup(strtok(NULL, ":\n"));
            }
            else if (strcmp(ptr, "Skills") == 0) {
                resume->skills = strdup(strtok(NULL, ":\n"));
            }
        }
    }
    
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s [filepath]\n", argv[0]);
        return 1;
    }
    
    Resume* resume = (Resume*) calloc(1, sizeof(Resume));
    parseResume(argv[1], resume);
    
    printf("\n\n-------------------\n");
    printf("Resume Parsing System\n");
    printf("-------------------\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills: %s\n", resume->skills);
    
    free(resume->name);
    free(resume->email);
    free(resume->skills);
    free(resume);
    return 0;
}