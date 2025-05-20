//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char name[MAX_LINE_SIZE];
    char job_title[MAX_LINE_SIZE];
    char company[MAX_LINE_SIZE];
    int years_experience;
} Resume;

Resume* parse_resume(char* file_path) {
    FILE* file = fopen(file_path, "r");
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int i = 0;
        char* token = strtok(line, ",");
        while (token!= NULL) {
            if (i == 0) {
                strcpy(resume->name, token);
            } else if (i == 1) {
                strcpy(resume->job_title, token);
            } else if (i == 2) {
                strcpy(resume->company, token);
            } else if (i == 3) {
                resume->years_experience = atoi(token);
            }
            i++;
            token = strtok(NULL, ",");
        }
        i = 0;
    }

    fclose(file);
    return resume;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Job Title: %s\n", resume->job_title);
    printf("Company: %s\n", resume->company);
    printf("Years of Experience: %d\n", resume->years_experience);
}

int main() {
    char* file_path = "resume.csv";
    Resume* resume = parse_resume(file_path);
    print_resume(resume);
    free(resume);
    return 0;
}