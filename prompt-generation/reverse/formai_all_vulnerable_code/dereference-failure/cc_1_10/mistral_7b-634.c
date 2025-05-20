//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct HashNode {
    char *meow;
    char *english;
    struct HashNode *next;
} HashNode;

HashNode *table[TABLE_SIZE];

int hash_function(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
        hash += (int)tolower(str[i]);
    return hash % TABLE_SIZE;
}

void create_node(HashNode **table, char *meow, char *english) {
    HashNode *new_node = (HashNode *)calloc(1, sizeof(HashNode));
    new_node->meow = strdup(meow);
    new_node->english = strdup(english);
    new_node->next = NULL;

    int hash_index = hash_function(meow);
    new_node->next = table[hash_index];
    table[hash_index] = new_node;
}

void translate_meow(char *meow) {
    int hash_index = hash_function(meow);
    HashNode *current = table[hash_index];

    while (current != NULL) {
        if (strcasecmp(current->meow, meow) == 0) {
            printf("%s: %s\n", meow, current->english);
            return;
        }
        current = current->next;
    }

    printf("%s: Unknown\n", meow);
}

int main() {
    create_node(table, "meow", "Hello");
    create_node(table, "miaow", "Goodbye");
    create_node(table, "hiss", "Angry");
    create_node(table, "purr", "Relaxed");
    create_node(table, "meow meow", "I love you");

    char meows[][20] = { "meow", "miaow", "hiss", "purr", "meow meow" };

    for (int i = 0; i < 5; i++)
        translate_meow(meows[i]);

    return 0;
}