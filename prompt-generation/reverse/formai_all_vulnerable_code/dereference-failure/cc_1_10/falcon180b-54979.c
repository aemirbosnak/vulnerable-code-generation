//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int index;
} WordIndex;

int main() {
    FILE *file;
    char line[MAX_WORD_LEN];
    int num_words = 0;
    WordIndex *index = (WordIndex*) malloc(MAX_WORDS * sizeof(WordIndex));

    // Open the file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the file and create the index
    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        char *word = strtok(line, " \t\n\r\f\v");
        while (word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(word, index[i].word) == 0) {
                    index[i].index++;
                    break;
                }
            }
            if (i == num_words) {
                index[num_words].word = strdup(word);
                index[num_words].index = 1;
                num_words++;
            }
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }

    // Print the index
    printf("Word Index:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", index[i].word, index[i].index);
    }

    // Close the file
    fclose(file);

    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(index[i].word);
    }
    free(index);

    return 0;
}