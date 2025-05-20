//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    char name[MAX_SIZE];
    char city[MAX_SIZE];
    int age;
    char education[MAX_SIZE];
    double experience;
} Resume;

void printResume(Resume *r) {
    printf("Name: %s\n", r->name);
    printf("City: %s\n", r->city);
    printf("Age: %d\n", r->age);
    printf("Education: %s\n", r->education);
    printf("Experience: %.1f years\n", r->experience);
}

Resume *parseResume(char *file) {
    FILE *fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Error opening file: %s\n", file);
        return NULL;
    }

    Resume *resume = malloc(sizeof(Resume));
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, ":");
        if (strcmp(token, "Name") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume->name, token);
        } else if (strcmp(token, "City") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume->city, token);
        } else if (strcmp(token, "Age") == 0) {
            token = strtok(NULL, ":");
            resume->age = atoi(token);
        } else if (strcmp(token, "Education") == 0) {
            token = strtok(NULL, ":");
            strcpy(resume->education, token);
        } else if (strcmp(token, "Experience") == 0) {
            token = strtok(NULL, ":");
            resume->experience = atof(token);
        }
    }

    free(line);
    fclose(fp);

    return resume;
}

int main() {
    char file[MAX_SIZE];
    printf("Enter resume file name: ");
    scanf("%s", file);

    Resume *resume = parseResume(file);
    if (resume == NULL) {
        return 1;
    }

    printResume(resume);
    free(resume);

    return 0;
}