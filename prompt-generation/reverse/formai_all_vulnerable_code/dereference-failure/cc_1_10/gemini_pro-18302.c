//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills[10];
    int num_skills;
} Applicant;

int parse_line(char *line, Applicant *a) {
    char *token;
    int i = 0;

    token = strtok(line, " ");
    while (token != NULL) {
        switch (i) {
            case 0:
                a->name = strdup(token);
                break;
            case 1:
                a->email = strdup(token);
                break;
            case 2:
                a->phone = strdup(token);
                break;
            default:
                a->skills[a->num_skills++] = strdup(token);
                break;
        }
        token = strtok(NULL, " ");
        i++;
    }

    return 0;
}

int main() {
    FILE *fp;
    char line[1024];
    Applicant *applicants[100];
    int num_applicants = 0;

    fp = fopen("resumes.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        Applicant *a = malloc(sizeof(Applicant));
        if (a == NULL) {
            perror("malloc");
            return -1;
        }

        parse_line(line, a);
        applicants[num_applicants++] = a;
    }

    fclose(fp);

    // Print the list of applicants
    for (int i = 0; i < num_applicants; i++) {
        printf("%s %s %s\n", applicants[i]->name, applicants[i]->email, applicants[i]->phone);
        for (int j = 0; j < applicants[i]->num_skills; j++) {
            printf("    %s\n", applicants[i]->skills[j]);
        }
    }

    return 0;
}