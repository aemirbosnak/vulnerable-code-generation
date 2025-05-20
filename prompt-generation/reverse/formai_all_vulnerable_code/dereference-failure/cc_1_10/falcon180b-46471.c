//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_WORD_LENGTH 20

typedef struct {
    char* word;
    int count;
} WordCount;

void process_line(char* line, WordCount words[]) {
    char* word = strtok(line, " ");
    while (word!= NULL) {
        if (strlen(word) > 0 && isalpha(word[0])) {
            int i;
            for (i = 0; i < MAX_WORD_LENGTH && isalpha(word[i]); i++) {
                word[i] = tolower(word[i]);
            }
            word[i] = '\0';
            int index = 0;
            while (index < MAX_WORD_LENGTH && words[index].count > 0) {
                if (strcmp(word, words[index].word) == 0) {
                    words[index].count++;
                    break;
                }
                index++;
            }
            if (index == MAX_WORD_LENGTH) {
                printf("Error: Maximum number of words reached.\n");
            } else {
                strcpy(words[index].word, word);
                words[index].count++;
            }
        }
        word = strtok(NULL, " ");
    }
}

void print_word_counts(WordCount words[]) {
    printf("Word counts:\n");
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Error: Filename required.\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    WordCount words[MAX_WORD_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        process_line(line, words);
        line_count++;
        if (line_count % 1000 == 0) {
            print_word_counts(words);
            for (int i = 0; i < MAX_WORD_LENGTH; i++) {
                words[i].count = 0;
            }
        }
    }
    fclose(file);
    print_word_counts(words);
    return 0;
}