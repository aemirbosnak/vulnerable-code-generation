//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *str;
    int len;
} Token;

char *input_file = "resume.txt";
char *output_file = "parsed_resume.txt";

int main() {
    FILE *fp_in, *fp_out;
    char line[MAX_TOKEN_LEN];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;

    fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_TOKEN_LEN, fp_in)!= NULL) {
        char *token = strtok(line, " \n\r\t");
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: too many tokens on line.\n");
                exit(1);
            }
            tokens[num_tokens].str = token;
            tokens[num_tokens].len = strlen(token);
            num_tokens++;
            token = strtok(NULL, " \n\r\t");
        }
        fprintf(fp_out, "%s\n", line);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}