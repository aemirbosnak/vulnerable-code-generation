//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int age;
} Person;

void parseResume(char *filename) {
    FILE *fp;
    char line[1024];
    char *token;
    Person resume;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        token = strtok(line, ":");

        if (strcmp(token, "Name") == 0) {
            strcpy(resume.name, strtok(NULL, "\n"));
        }

        if (strcmp(token, "Age") == 0) {
            resume.age = atoi(strtok(NULL, "\n"));
        }
    }

    fclose(fp);

    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    parseResume(argv[1]);

    return 0;
}