//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char position[50];
    char company[50];
    int years_of_experience;
} Job;

typedef struct {
    Job jobs[100];
    int current_job;
} Resume;

Resume parse_resume(char *filename) {
    FILE *file;
    Resume resume;
    char line[100];
    char token[20];

    resume.current_job = 0;
    file = fopen(filename, "r");

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") || strstr(line, "name:")) {
            sscanf(line, "%s %s", resume.jobs[resume.current_job].name, token);
            strcpy(resume.jobs[resume.current_job].position, "");
            strcpy(resume.jobs[resume.current_job].company, "");
        } else if (strstr(line, "Position:") || strstr(line, "position:")) {
            sscanf(line, "%s %s", token, resume.jobs[resume.current_job].position);
        } else if (strstr(line, "Company:") || strstr(line, "company:")) {
            sscanf(line, "%s %s", resume.jobs[resume.current_job].company, token);
            if (strstr(line, "Years of Experience:")) {
                sscanf(line, "%s %d", token, &resume.jobs[resume.current_job].years_of_experience);
                resume.current_job++;
            }
        }
    }

    fclose(file);

    return resume;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_filename>\n", argv[0]);
        return 1;
    }

    Resume resume = parse_resume(argv[1]);

    for (int i = 0; i < resume.current_job; i++) {
        printf("Name: %s\n", resume.jobs[i].name);
        printf("Position: %s\n", resume.jobs[i].position);
        printf("Company: %s\n", resume.jobs[i].company);
        printf("Years of Experience: %d\n", resume.jobs[i].years_of_experience);
        printf("\n");
    }

    return 0;
}