//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELD_SIZE 100

typedef struct {
    char* name;
    char* email;
    char* skills;
    int experience_years;
} Candidate;

char* parse_field(char* line) {
    int len = strlen(line);
    char* field = malloc(MAX_FIELD_SIZE);

    if (len == 0) {
        field = "";
    } else if (line[len-1] == '\n') {
        line[len-1] = '\0';
        strncpy(field, line, MAX_FIELD_SIZE);
    }

    return field;
}

Candidate* parse_candidate(char* line) {
    char* name = parse_field(strtok(line, ","));
    char* email = parse_field(strtok(NULL, ","));
    char* skills = parse_field(strtok(NULL, ","));
    int experience_years = atoi(parse_field(strtok(NULL, ",")));

    Candidate* candidate = malloc(sizeof(Candidate));
    candidate->name = name;
    candidate->email = email;
    candidate->skills = skills;
    candidate->experience_years = experience_years;

    return candidate;
}

int main() {
    FILE* file = fopen("candidates.csv", "r");
    char line[MAX_LINE_SIZE];
    Candidate* candidates[100];
    int num_candidates = 0;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        Candidate* candidate = parse_candidate(line);
        candidates[num_candidates++] = candidate;
    }

    fclose(file);

    printf("Parsed %d candidates\n", num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        Candidate* candidate = candidates[i];
        printf("Candidate %d: %s, %d years of experience\n", i+1, candidate->name, candidate->experience_years);
    }

    return 0;
}