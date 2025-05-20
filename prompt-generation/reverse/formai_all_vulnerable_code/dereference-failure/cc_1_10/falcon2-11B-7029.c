//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} Word;

int hash_function(const char *word) {
    int hash = 0;
    for (int i = 0; word[i]; i++) {
        hash = (hash << 2) ^ word[i];
    }
    return hash % MAX_WORD_SIZE;
}

Word* word_table = NULL;
int word_table_size = 0;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        int hash = hash_function(word);
        Word *entry = word_table + hash;
        for (int i = 0; entry[i].word[0]; i++) {
            if (!strcasecmp(entry[i].word, word)) {
                entry[i].count++;
                break;
            }
        }
    }

    fclose(file);

    for (int i = 0; i < MAX_WORD_SIZE; i++) {
        if (word_table[i].count) {
            printf("%s: %d\n", word_table[i].word, word_table[i].count);
        }
    }

    return 0;
}