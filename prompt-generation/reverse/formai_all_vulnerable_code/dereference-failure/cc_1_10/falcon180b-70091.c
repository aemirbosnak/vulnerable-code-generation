//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordIndex;

void build_index(char* filename, WordIndex* index) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char ch;
    char word[MAX_WORD_LENGTH] = "";
    int word_length = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[word_length++] = tolower(ch);
        } else {
            if (word_length > 0) {
                word[word_length] = '\0';
                if (index[word_length - 1].word[0] == '\0') {
                    strcpy(index[word_length - 1].word, word);
                    index[word_length - 1].count = 1;
                } else {
                    index[word_length - 1].count++;
                }
            }
            word_length = 0;
        }
    }

    if (word_length > 0) {
        word[word_length] = '\0';
        if (index[word_length - 1].word[0] == '\0') {
            strcpy(index[word_length - 1].word, word);
            index[word_length - 1].count = 1;
        } else {
            index[word_length - 1].count++;
        }
    }

    fclose(file);
}

void search_index(char* query, WordIndex* index) {
    char* token = strtok(query, " ");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORD_LENGTH && index[i].word[0]!= '\0') {
            if (strcmp(index[i].word, token) == 0) {
                printf("Found %s %d times\n", token, index[i].count);
            }
            i++;
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <query>\n", argv[0]);
        exit(1);
    }

    WordIndex index[MAX_WORDS];
    build_index(argv[1], index);
    search_index(argv[2], index);

    return 0;
}