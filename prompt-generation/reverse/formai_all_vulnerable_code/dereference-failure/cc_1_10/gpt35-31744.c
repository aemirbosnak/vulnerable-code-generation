//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Shape Shifting C Text Summarizer
// This program takes in a text file as input
// and outputs a summary of the text by keeping the overall meaning
// and shape shifting the text to make it more concise

#define MAX_LINES 1000
#define MAX_CHARS 1000

char* shapeShift(char* line) {
    int len = strlen(line);
    int vowels[] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117};
    char* newLine = malloc(len * sizeof(char));
    int counter = 0;

    for (int i = 0; i < len; i++) {
        int c = (int)line[i];
        int isVowel = 0;

        for (int j = 0; j < 10; j++) {
            if (c == vowels[j]) {
                isVowel = 1;
                break;
            }
        }

        if (isVowel && (i % 2 == 0)) {
            newLine[counter] = c + 1;
        } else if (isVowel && (i % 2 != 0)) {
            newLine[counter] = c - 1;
        } else {
            newLine[counter] = c;
        }

        counter++;
    }

    newLine[counter] = '\0';

    return newLine;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./summarizer <input_file>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    char line[MAX_CHARS];
    char* summary[MAX_LINES];
    int numLines = 0;

    while (fgets(line, MAX_CHARS, file)) {
        char* newLine = shapeShift(line);
        summary[numLines] = newLine;
        numLines++;

        if (numLines == MAX_LINES) {
            break;
        }
    }

    printf("Summary:\n");

    for (int i = 0; i < numLines; i++) {
        printf("%s", summary[i]);
    }

    fclose(file);

    return 0;
}