//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 500  // limit of input text size
#define SUMMARY 100 // size of summary

char *readInput(char filename[]) {
    FILE *fptr;
    char c, *input = (char*)malloc(sizeof(char)*LIMIT);
    int i = 0;

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    while ((c = fgetc(fptr)) != EOF && i < LIMIT)
        input[i++] = c;

    input[i] = '\0';
    fclose(fptr);

    return input;
}

void printSummary(char summary[], int size) {
    printf("\n-----------------------\n");
    printf("       Summary\n");
    printf("-----------------------\n");

    for (int i = 0; i < size; i++)
        printf("%c", summary[i]);

    printf("\n-----------------------\n");
}

int main() {
    char filename[30], *input, summary[SUMMARY];
    int inputSize, summaryIndex = 0;

    printf("Enter filename of input text: ");
    scanf("%s", filename);

    input = readInput(filename);
    inputSize = strlen(input);

    for (int i = 0; i < inputSize; i++) {
        if (input[i] == '.') {
            for (int j = i+1; j < inputSize && j < i+SUMMARY+1; j++)
                summary[summaryIndex++] = input[j];

            if (summaryIndex == SUMMARY)
                break;
        }
    }

    printSummary(summary, summaryIndex);

    free(input);

    return 0;
}