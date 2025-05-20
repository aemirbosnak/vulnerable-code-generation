//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define NUM_FIELDS 6

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    char education[50];
    char skills[100][20];
} Resume;

void parse_line(char *line, Resume *resume) {
    char field[50], value[100];
    int field_index = 0;

    strcpy(field, strtok(line, ":"));
    strcpy(value, strtok(NULL, ":"));

    switch (field_index) {
        case 0:
            strcpy(resume->name, value);
            break;
        case 1:
            resume->age = atoi(value);
            break;
        case 2:
            sscanf(value, "%f%s", &resume->height, &field);
            strcpy(resume->education, field);
            break;
        case 3:
            strcpy(resume->education, value);
            break;
        case 4:
            strcpy(field, strtok(NULL, ","));
            strcpy(resume->skills[0], field);
            if (strlen(value) > 0) {
                int i = 1;
                char *token = strtok(value, ",");
                while (token != NULL) {
                    strcpy(resume->skills[i], token);
                    i++;
                    token = strtok(NULL, ",");
                }
            }
            break;
    }

    field_index++;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Resume resume;

    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        parse_line(line, &resume);
        printf("Name: %s\n", resume.name);
        printf("Age: %d\n", resume.age);
        printf("Height: %.2f %s\n", resume.height, resume.education);
        printf("Education: %s\n", resume.education);
        printf("Skills:\n");
        for (int i = 0; i < NUM_FIELDS - 5; i++) {
            printf("- %s\n", resume.skills[i]);
        }
        memset(&resume, 0, sizeof(Resume));
    }

    fclose(fp);
    return 0;
}