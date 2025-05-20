//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hashtable data structure
struct hashtable {
    char **keys;
    int *values;
    int size;
    int count;
};

// create a new hashtable
struct hashtable *create_hashtable(int size) {
    struct hashtable *table = malloc(sizeof(struct hashtable));
    table->size = size;
    table->count = 0;
    table->keys = malloc(sizeof(char *) * size);
    table->values = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        table->keys[i] = NULL;
        table->values[i] = 0;
    }
    return table;
}

// free the hashtable
void free_hashtable(struct hashtable *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->keys[i]);
    }
    free(table->keys);
    free(table->values);
    free(table);
}

// insert a key-value pair into the hashtable
void insert(struct hashtable *table, char *key, int value) {
    int index = hash(key, table->size);
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }
    if (table->keys[index] == NULL) {
        table->count++;
        table->keys[index] = strdup(key);
        table->values[index] = value;
    } else {
        table->values[index] = value;
    }
}

// get the value associated with a key from the hashtable
int get(struct hashtable *table, char *key) {
    int index = hash(key, table->size);
    while (table->keys[index] != NULL && strcmp(table->keys[index], key) != 0) {
        index = (index + 1) % table->size;
    }
    if (table->keys[index] == NULL) {
        return 0;
    } else {
        return table->values[index];
    }
}

// hash function
int hash(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = (hash * 31 + key[i]) % size;
    }
    return hash;
}

// read a file and count the frequency of each word
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // create a hashtable to store the word frequencies
    struct hashtable *table = create_hashtable(1000);

    // open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // tokenize the line into words
        char *token = strtok(line, " ");
        while (token != NULL) {
            // convert the word to lowercase
            char *word = strdup(token);
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // insert the word into the hashtable
            insert(table, word, get(table, word) + 1);

            // free the word
            free(word);

            // get the next token
            token = strtok(NULL, " ");
        }
    }

    // close the file
    fclose(file);

    // print the word frequencies
    for (int i = 0; i < table->size; i++) {
        if (table->keys[i] != NULL) {
            printf("%s: %d\n", table->keys[i], table->values[i]);
        }
    }

    // free the hashtable
    free_hashtable(table);

    return 0;
}