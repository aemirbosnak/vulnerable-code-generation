//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define TABLE_SIZE 10000
typedef struct HashNode {
    char word[50];
    struct HashNode* next;
} HashNode;
unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 31 + c */
    return hash % TABLE_SIZE;
}
HashNode* create_node(char* str) {
    HashNode* new_node = (HashNode*) malloc(sizeof(HashNode));
    strcpy(new_node->word, str);
    new_node->next = NULL;
    return new_node;
}
HashNode* hash_table[TABLE_SIZE];
void insert_word(char* word) {
    int index = hash(word);
    HashNode* new_node = create_node(word);
    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        HashNode* current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
int main() {
    FILE* file = fopen("text.txt", "r");
    char line[1024], word[50];
    bool in_word = false;
    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        for (; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                in_word = true;
            }
            if (in_word) {
                word[i] = tolower(line[i]);
            }
        }
        if (strlen(word) > 0) {
            insert_word(word);
        }
    }
    fclose(file);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            printf("Word %s found at index %d\n", hash_table[i]->word, i);
        }
    }
    return 0;
}