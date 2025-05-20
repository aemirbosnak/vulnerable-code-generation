//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

WordCount wc[MAX_WORDS];
int word_index = 0;

int find_word(const char *word) {
    for (int i = 0; i < word_index; i++) {
        if (strcmp(wc[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void add_word(const char *word) {
    int index = find_word(word);
    if (index != -1) {
        wc[index].count++;
    } else {
        strncpy(wc[word_index].word, word, MAX_WORD_LEN);
        wc[word_index].count = 1;
        word_index++;
    }
}

int compare(const void *a, const void *b) {
    WordCount *wc_a = (WordCount *)a;
    WordCount *wc_b = (WordCount *)b;
    return wc_b->count - wc_a->count; // Descending order
}

void print_word_counts() {
    for (int i = 0; i < word_index; i++) {
        printf("%s: %d\n", wc[i].word, wc[i].count);
    }
}

void process_words(FILE *file) {
    char buffer[MAX_WORD_LEN];
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer);
        // Remove punctuation from the end
        char *end = buffer + strlen(buffer) - 1;
        while (end > buffer && !isalnum((unsigned char)*end)) {
            *end = '\0';
            end--;
        }
        add_word(buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }
    
    process_words(file);
    fclose(file);
    
    qsort(wc, word_index, sizeof(WordCount), compare);
    
    printf("Word Frequency Count:\n");
    print_word_counts();
    
    return 0;
}