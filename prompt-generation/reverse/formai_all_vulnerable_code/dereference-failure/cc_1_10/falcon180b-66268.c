//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64

typedef struct {
    char *name;
    char *phone;
    char *email;
    int experience;
    char *skills[10];
    int num_skills;
} Candidate;

void add_skill(Candidate *candidate, char *skill) {
    if (candidate->num_skills >= 10) {
        printf("Error: Candidate can have maximum 10 skills.\n");
        return;
    }
    strcpy(candidate->skills[candidate->num_skills++], skill);
}

void print_candidate(Candidate *candidate) {
    printf("Name: %s\n", candidate->name);
    printf("Phone: %s\n", candidate->phone);
    printf("Email: %s\n", candidate->email);
    printf("Experience: %d years\n", candidate->experience);
    printf("Skills:\n");
    for (int i = 0; i < candidate->num_skills; i++) {
        printf("\t%s\n", candidate->skills[i]);
    }
}

Candidate *parse_candidate(char *line) {
    Candidate *candidate = (Candidate *)malloc(sizeof(Candidate));
    char *token;
    int i = 0;

    token = strtok(line, ",");
    strcpy(candidate->name, token);

    token = strtok(NULL, ",");
    strcpy(candidate->phone, token);

    token = strtok(NULL, ",");
    strcpy(candidate->email, token);

    token = strtok(NULL, ",");
    candidate->experience = atoi(token);

    while ((token = strtok(NULL, ","))!= NULL) {
        add_skill(candidate, token);
    }

    return candidate;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    Candidate *candidate;

    fp = fopen("candidates.csv", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        candidate = parse_candidate(line);
        print_candidate(candidate);
    }

    fclose(fp);
    return 0;
}