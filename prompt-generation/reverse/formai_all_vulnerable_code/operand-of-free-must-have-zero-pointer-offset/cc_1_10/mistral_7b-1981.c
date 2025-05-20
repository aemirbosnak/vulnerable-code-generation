//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[100];
    char position[50];
    char company[50];
    char start_date[20];
    char end_date[20];
} WorkExperience;

void parse_line(char *line, WorkExperience *work_exp) {
    char *token;
    int pos = 0;

    strcpy(work_exp->name, "");
    strcpy(work_exp->position, "");
    strcpy(work_exp->company, "");
    strcpy(work_exp->start_date, "");
    strcpy(work_exp->end_date, "");

    token = strtok(line, "|");
    if (token != NULL) strcpy(work_exp->name, token);

    token = strtok(NULL, "|");
    if (token != NULL) strcpy(work_exp->position, token);

    token = strtok(NULL, "|");
    if (token != NULL) strcpy(work_exp->company, token);

    token = strtok(NULL, "|");
    if (token != NULL) {
        strncpy(work_exp->start_date, token, 10);
        work_exp->start_date[10] = '\0';
    }

    token = strtok(NULL, "|");
    if (token != NULL) {
        strncpy(work_exp->end_date, token, 10);
        work_exp->end_date[10] = '\0';
    }
}

int main() {
    FILE *resume_file;
    char line[200];
    WorkExperience *work_exp;
    int num_exp = 0;

    resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        printf("Error opening resume file.\n");
        return 1;
    }

    work_exp = malloc(sizeof(WorkExperience));

    while (fgets(line, sizeof(line), resume_file)) {
        if (strlen(line) < 2 || line[0] == '\n') continue;

        parse_line(line, work_exp);

        printf("Name: %s\n", work_exp->name);
        printf("Position: %s\n", work_exp->position);
        printf("Company: %s\n", work_exp->company);
        printf("Start Date: %s\n", work_exp->start_date);
        printf("End Date: %s\n", work_exp->end_date);
        printf("\n");

        num_exp++;
        work_exp = realloc(work_exp, (num_exp + 1) * sizeof(WorkExperience));
        work_exp = work_exp + num_exp;
    }

    fclose(resume_file);
    free(work_exp);

    return 0;
}