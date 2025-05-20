//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Max size of word
#define MAX_WORD_SIZE 100

// Function declarations
void insert(char *word);
int compare(const void *a, const void *b);
void print();

struct node {
    char *word;
    int count;
};

struct node *word_list = NULL;
int num_words = 0;

int main() {
    char current_word[MAX_WORD_SIZE];
    int c, i = 0;

    // Read input stream until EOF
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            // Add character to current word
            current_word[i++] = tolower(c);

            // Check if word is too big
            if (i >= MAX_WORD_SIZE) {
                // Skip current word and reset index
                while ((c = getchar()) != EOF && isalpha(c));
                i = 0;
            }
        } else if (i > 0) {
            // Terminating character found, insert word
            current_word[i] = '\0';
            insert(current_word);

            // Reset index
            i = 0;
        }
    }

    // Sort word list and print frequencies
    qsort(word_list, num_words, sizeof(struct node), compare);
    print();

    // Free memory used by word_list
    for (i = 0; i < num_words; i++) {
        free(word_list[i].word);
    }
    free(word_list);

    return 0;
}

void insert(char *word) {
    int i;

    // Check if word already exists, if so, increment count
    for (i = 0; i < num_words; i++) {
        if (strcmp(word_list[i].word, word) == 0) {
            word_list[i].count++;
            return;
        }
    }

    // Increase size of word_list
    num_words++;
    word_list = realloc(word_list, num_words * sizeof(struct node));

    // Create new node
    word_list[num_words - 1].word = malloc(strlen(word) + 1);
    strcpy(word_list[num_words - 1].word, word);
    word_list[num_words - 1].count = 1;
}

int compare(const void *a, const void *b) {
    const struct node *p1 = (const struct node*) a;
    const struct node *p2 = (const struct node*) b;
    return p2->count - p1->count; // Descending order
}

void print() {
    int i;

    printf("%-15s%s\n", "Word", "Frequency");
    printf("---------------\n");

    for (i = 0; i < num_words; i++) {
        printf("%-15s%d\n", word_list[i].word, word_list[i].count);
    }
}