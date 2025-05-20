//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define FILENAME "happiness.txt"

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *tokens[10];
    int happiness_count = 0;

    fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("Oops! Couldn't open the file. Let's make one instead!\n");
        fp = fopen("happiness.txt", "w");
        fprintf(fp, "Initializing happiness file...\n");
        fclose(fp);
        fp = fopen(FILENAME, "r");
    }

    printf("\nWelcome to the Happiness File Handler!\n");
    printf("We'll count how many happy lines we have in this file!\n");

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int i = 0;
        char *token = strtok(line, " \n\t");
        if (strcmp(token, "happy") == 0) {
            happiness_count++;
            printf("%s: Happy line found!\n", line);
        }
        while ((token = strtok(NULL, " \n\t")) != NULL) {
            tokens[i++] = token;
        }
        tokens[i] = NULL;
        int j = 0;
        while (tokens[j] != NULL) {
            if (strcmp(tokens[j], "happy") == 0) {
                happiness_count++;
                printf("%s: Happy word found!\n", line);
            }
            j++;
        }
    }

    fclose(fp);

    printf("\nTotal number of happy lines and words in the file: %d\n", happiness_count);
    return 0;
}