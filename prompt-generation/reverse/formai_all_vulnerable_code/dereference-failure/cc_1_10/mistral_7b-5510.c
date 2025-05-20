//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKEN_LEN 256
#define MAX_FIELDS 25
#define MAX_RESUMES 100

typedef struct {
    char name[MAX_TOKEN_LEN];
    char field[MAX_TOKEN_LEN][MAX_FIELDS];
    int num_fields;
} resume_t;

typedef struct {
    char keyword[MAX_TOKEN_LEN];
    int num_fields;
} keyword_t;

resume_t resumes[MAX_RESUMES];
keyword_t keywords[MAX_FIELDS];

int current_resume = 0;
int current_field = 0;
int num_keywords = 0;

int is_delimiter(char c) {
    return (c == ':' || c == ',' || c == '\n');
}

void parse_keyword(char *line) {
    char *token = strtok(line, ":");
    strcpy(keywords[num_keywords].keyword, token);
    token = strtok(NULL, ":");
    if (token != NULL) {
        sscanf(token, "%d", &(keywords[num_keywords].num_fields));
    }
    num_keywords++;
}

void parse_resume(char *line) {
    char *token = strtok(line, ",");
    strcpy(resumes[current_resume].name, token);
    current_field = 0;

    while (token = strtok(NULL, ":")) {
        strcpy(resumes[current_resume].field[current_field], token);
        current_field++;
        if (current_field >= MAX_FIELDS) {
            printf("Error: Too many fields in resume %s\n", resumes[current_resume].name);
            exit(1);
        }
    }

    if (current_field < keywords[num_keywords - 1].num_fields) {
        printf("Error: Missing fields in resume %s\n", resumes[current_resume].name);
        exit(1);
    }

    current_resume++;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];

    if (argc != 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (strstr(line, "KEYWORDS:") != NULL) {
            parse_keyword(line + strlen("KEYWORDS:") + 1);
        } else {
            parse_resume(line);
        }
    }

    fclose(fp);

    printf("\nResumes:\n");
    for (int i = 0; i < current_resume; i++) {
        printf("%s\n", resumes[i].name);
        for (int j = 0; j < keywords[num_keywords - 1].num_fields; j++) {
            printf("%s: %s\n", keywords[j].keyword, resumes[i].field[j]);
        }
    }

    return 0;
}