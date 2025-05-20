//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_ resumes 10

typedef struct resume {
    char name[20];
    char address[50];
    int age;
    float salary;
} resume;

void parse_resumes(resume **resumes) {
    FILE *fp;
    int i = 0;

    fp = fopen("resumes.txt", "r");
    if (fp == NULL) {
        return;
    }

    while (!feof(fp)) {
        resumes[i] = malloc(sizeof(resume));

        fscanf(fp, "%s", resumes[i]->name);
        fscanf(fp, "%s", resumes[i]->address);
        fscanf(fp, "%d", &resumes[i]->age);
        fscanf(fp, "%f", &resumes[i]->salary);

        i++;
    }

    fclose(fp);
}

int main() {
    resume **resumes = NULL;

    parse_resumes(&resumes);

    for (int i = 0; resumes[i] != NULL; i++) {
        printf("Name: %s\n", resumes[i]->name);
        printf("Address: %s\n", resumes[i]->address);
        printf("Age: %d\n", resumes[i]->age);
        printf("Salary: %.2f\n", resumes[i]->salary);
        printf("\n");
    }

    return 0;
}