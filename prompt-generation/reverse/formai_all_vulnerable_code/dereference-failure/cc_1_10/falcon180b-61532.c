//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 50

typedef struct {
    char *name;
    char *value;
} keyword_t;

typedef struct {
    int num_keywords;
    keyword_t keywords[MAX_KEYWORDS];
} resume_t;

void read_input(resume_t *resume, FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char delim[] = " :\t\r\n";
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, delim);

        while (token!= NULL) {
            if (i >= MAX_KEYWORDS) {
                printf("Error: Too many keywords\n");
                exit(1);
            }

            if (strlen(token) > MAX_KEYWORD_LENGTH) {
                printf("Error: Keyword too long\n");
                exit(1);
            }

            resume->keywords[i].name = strdup(token);
            resume->keywords[i].value = NULL;
            i++;

            token = strtok(NULL, delim);
        }
    }

    resume->num_keywords = i;
}

void write_output(resume_t *resume, FILE *fp) {
    for (int i = 0; i < resume->num_keywords; i++) {
        if (resume->keywords[i].value!= NULL) {
            fprintf(fp, "%s: %s\n", resume->keywords[i].name, resume->keywords[i].value);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Input file not found\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Output file not found\n");
        exit(1);
    }

    resume_t resume;
    read_input(&resume, input_file);
    write_output(&resume, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}