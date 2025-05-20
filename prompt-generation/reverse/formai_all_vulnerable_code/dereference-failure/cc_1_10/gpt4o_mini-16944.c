//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 256
#define HASH_TABLE_SIZE 128

typedef struct KeyValue {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct KeyValue *next;
} KeyValue;

typedef struct HashTable {
    KeyValue *table[HASH_TABLE_SIZE];
} HashTable;

unsigned int hash(char *key) {
    unsigned int hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % HASH_TABLE_SIZE;
}

HashTable *create_table() {
    HashTable *new_table = malloc(sizeof(HashTable));
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        new_table->table[i] = NULL;
    }
    return new_table;
}

void insert(HashTable *hash_table, char *key, char *value) {
    unsigned int index = hash(key);
    KeyValue *new_kv = malloc(sizeof(KeyValue));
    strncpy(new_kv->key, key, MAX_KEY_LENGTH);
    strncpy(new_kv->value, value, MAX_VALUE_LENGTH);
    new_kv->next = hash_table->table[index];
    hash_table->table[index] = new_kv;
}

char *search(HashTable *hash_table, char *key) {
    unsigned int index = hash(key);
    KeyValue *kv = hash_table->table[index];
    while (kv != NULL) {
        if (strcmp(kv->key, key) == 0) {
            return kv->value;
        }
        kv = kv->next;
    }
    return NULL;
}

void free_table(HashTable *hash_table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        KeyValue *kv = hash_table->table[i];
        while (kv != NULL) {
            KeyValue *temp = kv;
            kv = kv->next;
            free(temp);
        }
    }
    free(hash_table);
}

void parse_json(const char *json_string, HashTable *hash_table) {
    const char *p = json_string;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    
    while (*p) {
        while (*p && isspace((unsigned char)*p)) p++; // Skip whitespace
        if (*p == '"') {
            p++; // Skip opening quote
            char *key_start = p;
            while (*p && *p != '"') p++; // Find closing quote
            strncpy(key, key_start, p - key_start);
            key[p - key_start] = '\0'; // Null-terminate
            
            p++; // Skip closing quote
            while (*p && isspace((unsigned char)*p)) p++; // Skip whitespace
            if (*p == ':') p++; // Skip colon
            while (*p && isspace((unsigned char)*p)) p++; // Skip whitespace
            if (*p == '"') {
                p++; // Skip opening quote
                char *value_start = p;
                while (*p && *p != '"') p++; // Find closing quote
                strncpy(value, value_start, p - value_start);
                value[p - value_start] = '\0'; // Null-terminate
                
                insert(hash_table, key, value);
            }
        }
        while (*p && *p != '}') p++; // Skip to next object or end
        if (*p == '}') break; // End of JSON object
        p++; // Move to next character
    }
}

void print_table(HashTable *hash_table) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        KeyValue *kv = hash_table->table[i];
        while (kv != NULL) {
            printf("%s: %s\n", kv->key, kv->value);
            kv = kv->next;
        }
    }
}

int main() {
    const char *json_string = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";

    HashTable *hash_table = create_table();
    parse_json(json_string, hash_table);
    
    printf("Parsed JSON:\n");
    print_table(hash_table);
    
    free_table(hash_table);

    return 0;
}