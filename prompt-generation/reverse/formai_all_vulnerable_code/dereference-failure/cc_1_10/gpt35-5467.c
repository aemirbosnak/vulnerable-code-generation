//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define FIELD_SIZE 50

struct candidate {
    char name[FIELD_SIZE];
    char address[FIELD_SIZE];
    char education[FIELD_SIZE];
    char experience[FIELD_SIZE];
    char skills[FIELD_SIZE];
};

void parse_resume(char *input_file, struct candidate *c);
void print_candidate(struct candidate c);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    struct candidate c;
    parse_resume(argv[1], &c);
    print_candidate(c);

    return 0;
}

void parse_resume(char *input_file, struct candidate *c) {

    FILE *fp;
    char line[MAX_LEN];
    char *token, *field;

    fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LEN, fp) != NULL) {
        field = strtok(line, ":");
        if (strcmp(field, "Name") == 0) {
            token = strtok(NULL, "\n");
            strcpy(c->name, token);
        }
        else if (strcmp(field, "Address") == 0) {
            token = strtok(NULL, "\n");
            strcpy(c->address, token);
        }
        else if (strcmp(field, "Education") == 0) {
            token = strtok(NULL, "\n");
            strcpy(c->education, token);
        }
        else if (strcmp(field, "Experience") == 0) {
            token = strtok(NULL, "\n");
            strcpy(c->experience, token);
        }
        else if (strcmp(field, "Skills") == 0) {
            token = strtok(NULL, "\n");
            strcpy(c->skills, token);
        }
    }

    fclose(fp);
}

void print_candidate(struct candidate c) {
    printf("Name: %s\n", c.name);
    printf("Address: %s\n", c.address);
    printf("Education: %s\n", c.education);
    printf("Experience: %s\n", c.experience);
    printf("Skills: %s\n", c.skills);
}