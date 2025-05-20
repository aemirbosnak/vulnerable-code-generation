//Falcon-180B DATASET v1.0 Category: Database querying ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_QUERY_LENGTH 1000

// Structure to hold a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two WordFrequency structures by frequency
int compareFrequency(const void *a, const void *b) {
    const WordFrequency *wordA = (const WordFrequency *)a;
    const WordFrequency *wordB = (const WordFrequency *)b;
    return wordB->frequency - wordA->frequency;
}

// Function to read a line from a file and return it as a string
char *readLine(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return NULL;
    }
    line[strcspn(line, "\n")] = '\0';
    return line;
}

// Function to tokenize a line into words
void tokenizeLine(char *line, WordFrequency *wordFrequencies) {
    char *word = strtok(line, " \t\r\n");
    while (word!= NULL) {
        if (strlen(word) <= MAX_WORD_LENGTH) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }
            WordFrequency *frequency = bsearch(word, wordFrequencies, MAX_QUERY_LENGTH, sizeof(WordFrequency), compareFrequency);
            if (frequency == NULL) {
                frequency = wordFrequencies + MAX_QUERY_LENGTH - 1;
                strcpy(frequency->word, word);
                frequency->frequency = 1;
            } else {
                frequency->frequency++;
            }
        }
        word = strtok(NULL, " \t\r\n");
    }
}

// Function to print the top N most frequent words
void printTopWords(WordFrequency *wordFrequencies, int n) {
    qsort(wordFrequencies, MAX_QUERY_LENGTH, sizeof(WordFrequency), compareFrequency);
    printf("Top %d most frequent words:\n", n);
    int i;
    for (i = 0; i < n && i < MAX_QUERY_LENGTH; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main() {
    FILE *file;
    char *line;
    WordFrequency wordFrequencies[MAX_QUERY_LENGTH];

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read each line and tokenize it into words
    int lineNumber = 0;
    while ((line = readLine(file))!= NULL) {
        tokenizeLine(line, wordFrequencies);
        lineNumber++;
    }

    // Print the top N most frequent words
    int n;
    printf("Enter the number of top words to print: ");
    scanf("%d", &n);
    printTopWords(wordFrequencies, n);

    // Close the file
    fclose(file);
    return 0;
}