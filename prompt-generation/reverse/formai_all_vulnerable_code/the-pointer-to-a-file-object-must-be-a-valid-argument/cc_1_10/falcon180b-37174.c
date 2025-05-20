//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void ReadWords(char *filename, WordCount *words) {
    FILE *file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == MAX_WORDS) {
                strncpy(words[i].word, word, MAX_WORD_LENGTH - 1);
                words[i].word[MAX_WORD_LENGTH - 1] = '\0';
                words[i].count = 1;
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(file);
}

void WriteWords(WordCount *words) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].word[0]!= '\0') {
            printf("%s %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char input_filename[MAX_WORD_LENGTH];
    char output_filename[MAX_WORD_LENGTH];
    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    WordCount words[MAX_WORDS];
    ReadWords(input_filename, words);

    FILE *output_file = fopen(output_filename, "w");
    WriteWords(words);
    fclose(output_file);

    return 0;
}