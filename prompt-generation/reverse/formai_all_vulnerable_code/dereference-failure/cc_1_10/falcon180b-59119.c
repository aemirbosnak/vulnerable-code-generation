//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char* word;
    int frequency;
} WordFrequency;

void readFile(FILE* file, char* buffer) {
    int ch = fgetc(file);
    int i = 0;
    while (ch!= EOF) {
        buffer[i++] = (char) ch;
        ch = fgetc(file);
    }
    buffer[i] = '\0';
}

int isValidWord(char* word) {
    int length = strlen(word);
    if (length > MAX_WORD_LENGTH) {
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void countWords(char* buffer, WordFrequency* frequencies, int numFrequencies) {
    char* word = strtok(buffer, " \t\n\r\f\v,.?!;:");
    while (word!= NULL) {
        if (isValidWord(word)) {
            int index = 0;
            for (int i = 0; i < numFrequencies; i++) {
                if (strcmp(frequencies[i].word, word) == 0) {
                    frequencies[i].frequency++;
                    break;
                }
            }
            if (index == numFrequencies) {
                frequencies[index].word = strdup(word);
                frequencies[index].frequency = 1;
                numFrequencies++;
            }
        }
        word = strtok(NULL, " \t\n\r\f\v,.?!;:");
    }
}

void writeFrequencies(WordFrequency* frequencies, int numFrequencies) {
    for (int i = 0; i < numFrequencies; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].frequency);
    }
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char* buffer = (char*) malloc(MAX_LINE_LENGTH);
    readFile(file, buffer);

    WordFrequency frequencies[MAX_NUM_LINES];
    int numFrequencies = 0;
    countWords(buffer, frequencies, numFrequencies);

    writeFrequencies(frequencies, numFrequencies);

    free(buffer);
    fclose(file);

    return 0;
}