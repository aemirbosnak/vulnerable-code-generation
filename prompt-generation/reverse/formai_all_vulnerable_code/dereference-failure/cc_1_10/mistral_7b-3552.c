//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 50
#define MAX_SKILL_LENGTH 30
#define MAX_EXPERIENCE_LENGTH 200
#define NUM_FIELDS 4

typedef struct {
    char name[MAX_NAME_LENGTH];
    char skills[NUM_FIELDS][MAX_SKILL_LENGTH];
    char experiences[NUM_FIELDS][MAX_EXPERIENCE_LENGTH];
} Candidate;

void parse_line(char line[], Candidate* candidate) {
    char field[MAX_LINE_LENGTH];
    char* token;
    int field_index = 0;

    strcpy(field, strtok(line, ":"));

    if (strcmp(field, "Name:") == 0) {
        strcpy(candidate->name, strtok(NULL, "\n"));
    }
    else {
        for (int i = 0; i < NUM_FIELDS; i++) {
            if (field_index++ == 0) {
                strcpy(candidate->skills[i], field);
            }
            else if (field_index == 1) {
                strcpy(candidate->experiences[i], "");
                token = strtok(NULL, "\n");
                if (token != NULL) {
                    strcpy(candidate->experiences[i], token);
                }
            }
        }
    }
}

void print_candidate(Candidate candidate) {
    printf("Name: %s\n", candidate.name);
    printf("Skills:\n");
    for (int i = 0; i < NUM_FIELDS; i++) {
        printf("\t%s\n", candidate.skills[i]);
    }
    printf("Experiences:\n");
    for (int i = 0; i < NUM_FIELDS; i++) {
        printf("\t%s\n", candidate.experiences[i]);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    Candidate candidate;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        parse_line(line, &candidate);
    }

    print_candidate(candidate);

    return 0;
}

// Input resume in the following format:
// Name: John Doe
// Skills: C, Java, Python
// Skills: Database, Networking
// Experience: Software Engineer at XYZ Inc. (2015-2018)
// Experience: Senior Software Engineer at ABC Corp. (2012-2015)