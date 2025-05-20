//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEYWORDS 10

typedef struct {
    char *keyword;
    int keyword_length;
    int index;
} Keyword;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <resume_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *resume_file = fopen(argv[1], "r");
    if (resume_file == NULL) {
        printf("Error: could not open resume file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *token;
    char *keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    fgets(line, MAX_LINE_LENGTH, resume_file);
    while (line!= NULL) {
        // split line into words
        token = strtok(line, " ");
        while (token!= NULL) {
            if (num_keywords >= MAX_KEYWORDS) {
                printf("Error: too many keywords.\n");
                exit(1);
            }
            keywords[num_keywords] = token;
            num_keywords++;
            token = strtok(NULL, " ");
        }

        // write keywords to output file
        for (int i = 0; i < num_keywords; i++) {
            fprintf(output_file, "%s\n", keywords[i]);
        }

        fgets(line, MAX_LINE_LENGTH, resume_file);
    }

    fclose(resume_file);
    fclose(output_file);

    return 0;
}