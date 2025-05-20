//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_THREADS 4
#define HASH_TABLE_SIZE 1000

typedef struct {
    char *word;
    int count;
    struct Node *next;
} Node;

typedef struct {
    Node *table[HASH_TABLE_SIZE];
    pthread_mutex_t lock;
} HashTable;

typedef struct {
    char *filename;
    HashTable *hash_table;
} ThreadData;

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % HASH_TABLE_SIZE;
}

void insert_word(HashTable *ht, const char *word) {
    unsigned long index = hash(word);
    
    pthread_mutex_lock(&ht->lock);

    Node *current = ht->table[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            pthread_mutex_unlock(&ht->lock);
            return;
        }
        current = current->next;
    }

    Node *new_node = malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = ht->table[index];
    ht->table[index] = new_node;

    pthread_mutex_unlock(&ht->lock);
}

void *count_words(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    FILE *file = fopen(data->filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert to lowercase and filter non-alpha characters
        for (char *p = word; *p; p++) {
            *p = tolower(*p);
        }
        insert_word(data->hash_table, word);
    }

    fclose(file);
    return NULL;
}

void print_word_counts(HashTable *ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *current = ht->table[i];
        while (current) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}

void free_hash_table(HashTable *ht) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node *current = ht->table[i];
        while (current) {
            Node *to_free = current;
            current = current->next;
            free(to_free->word);
            free(to_free);
        }
    }
    free(ht);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    HashTable *hash_table = malloc(sizeof(HashTable));
    memset(hash_table->table, 0, sizeof(hash_table->table));
    pthread_mutex_init(&hash_table->lock, NULL);

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int thread_count = 0;

    for (int i = 1; i < argc && thread_count < MAX_THREADS; i++) {
        thread_data[thread_count].filename = argv[i];
        thread_data[thread_count].hash_table = hash_table;

        if (pthread_create(&threads[thread_count], NULL, count_words, &thread_data[thread_count]) != 0) {
            perror("Failed to create thread");
        }
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    print_word_counts(hash_table);
    
    free_hash_table(hash_table);
    pthread_mutex_destroy(&hash_table->lock);
    
    return 0;
}