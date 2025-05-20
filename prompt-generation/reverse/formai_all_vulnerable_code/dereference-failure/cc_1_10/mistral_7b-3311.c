//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashNode {
    char *english;
    char *alien;
} HashNode;

unsigned int hash(char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashNode *create_node(char *english, char *alien) {
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));

    new_node->english = strdup(english);
    new_node->alien = strdup(alien);

    return new_node;
}

void insert_word(HashNode **table, char *english, char *alien) {
    unsigned int index = hash(english);

    if (!table[index])
        table[index] = create_node(english, alien);
}

char *translate(HashNode **table, char *english) {
    unsigned int index = hash(english);
    HashNode *node;

    if (!(node = table[index]))
        return "Translation not found.";

    return node->alien;
}

int main() {
    HashNode *table[TABLE_SIZE];

    // Initialize the table with some English phrases and their alien translations
    insert_word(table, "hello", "kla-atu");
    insert_word(table, "goodbye", "xva-xva");
    insert_word(table, "thank you", "joo-joo-la-la");

    // Translate some English phrases to the alien language
    printf("Translation of 'hello': %s\n", translate(table, "hello"));
    printf("Translation of 'goodbye': %s\n", translate(table, "goodbye"));
    printf("Translation of 'thank you': %s\n", translate(table, "thank you"));

    // Translate an unknown English phrase
    printf("Translation of 'world': %s\n", translate(table, "world"));

    return 0;
}