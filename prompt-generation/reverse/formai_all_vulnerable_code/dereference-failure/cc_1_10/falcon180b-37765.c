//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char input_file[MAX_LINE_LENGTH];
    char output_file[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *token;
    FILE *input_fp, *output_fp;

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_fp)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, "meow") == 0) {
                fprintf(output_fp, "purr\n");
            } else if (strcmp(token, "purr") == 0) {
                fprintf(output_fp, "meow\n");
            } else {
                fprintf(output_fp, "%s ", token);
            }
            token = strtok(NULL, " ");
        }
        fprintf(output_fp, "\n");
    }

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}