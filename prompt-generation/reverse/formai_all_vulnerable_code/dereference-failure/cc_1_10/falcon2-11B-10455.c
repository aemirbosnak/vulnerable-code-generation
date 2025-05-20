//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a hash function that takes a string and returns a hash value
unsigned int hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// Define a function to insert a string into a hash table
void insert(char **table, char *str) {
    unsigned int hash_val = hash(str);
    char *new_str = (char *)malloc(strlen(str) + 1);
    strcpy(new_str, str);
    table[hash_val] = new_str;
}

// Define a function to check if a string is in a hash table
int contains(char **table, char *str) {
    unsigned int hash_val = hash(str);
    return table[hash_val] == str;
}

// Define a function to print all the strings in a hash table
void print_table(char **table, int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        printf("%s\n", table[i]);
    }
}

// Define a function to remove all duplicates from a hash table
void remove_duplicates(char **table, int num_buckets) {
    char *current_str = NULL;
    char *prev_str = NULL;
    for (int i = 0; i < num_buckets; i++) {
        if (table[i] == NULL) {
            continue;
        }
        current_str = table[i];
        while (contains(table, current_str)) {
            if (prev_str == NULL) {
                insert(table, current_str);
            } else {
                if (strcmp(prev_str, current_str) == 0) {
                    free(prev_str);
                    prev_str = NULL;
                } else {
                    insert(table, current_str);
                }
            }
            current_str = NULL;
        }
        prev_str = current_str;
    }
}

// Define a function to get the top N most frequent words in a hash table
char **get_top_words(char **table, int num_buckets, int N) {
    char **result = (char **)malloc(N * sizeof(char *));
    int num_words = 0;
    for (int i = 0; i < num_buckets; i++) {
        if (table[i] == NULL) {
            continue;
        }
        result[num_words] = table[i];
        num_words++;
        if (num_words == N) {
            break;
        }
    }
    return result;
}

// Define a function to summarize a text by removing all duplicates and getting the top N most frequent words
void summarize_text(char *text, int N) {
    char **table = (char **)malloc(200 * sizeof(char *));
    for (int i = 0; i < 200; i++) {
        table[i] = NULL;
    }
    char *word;
    while ((word = strtok(text, " "))!= NULL) {
        insert(table, word);
    }
    remove_duplicates(table, 200);
    char **top_words = get_top_words(table, 200, N);
    printf("Top %d most frequent words:\n", N);
    print_table(top_words, N);
    free(top_words);
}

int main() {
    char text[] = "This is a sample text to be summarized. It contains some random words and phrases.";
    summarize_text(text, 10);
    return 0;
}