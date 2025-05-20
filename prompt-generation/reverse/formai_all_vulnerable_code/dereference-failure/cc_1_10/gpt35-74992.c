//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

struct Resume {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* education;
    char* experience;
    char* skills;
};

void freeResume(struct Resume* resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->address);
    free(resume->education);
    free(resume->experience);
    free(resume->skills);
}

void parseResumeLine(char* line, struct Resume* resume) {
    char* field = strtok(line, ":");
    char* value = strtok(NULL, "\n");

    if (field && value) {
        if (strcmp(field, "Name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(field, "Email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(field, "Phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(field, "Address") == 0) {
            resume->address = strdup(value);
        } else if (strcmp(field, "Education") == 0) {
            resume->education = strdup(value);
        } else if (strcmp(field, "Experience") == 0) {
            resume->experience = strdup(value);
        } else if (strcmp(field, "Skills") == 0) {
            resume->skills = strdup(value);
        }
    }
}

struct Resume* parseResume(char* filename) {
    FILE* fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    struct Resume* resume = malloc(sizeof(struct Resume));
    memset(resume, 0, sizeof(struct Resume));

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        parseResumeLine(line, resume);
    }

    fclose(fp);
    return resume;
}

void printResume(struct Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <resume file>\n", argv[0]);
        return 1;
    }

    struct Resume* resume = parseResume(argv[1]);
    printResume(resume);
    freeResume(resume);

    return 0;
}