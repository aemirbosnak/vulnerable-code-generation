//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101

typedef struct HashNode {
    char *english;
    char *cat;
    struct HashNode *next;
} HashNode;

HashNode *table[TABLE_SIZE];

int hash(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += tolower(str[i]);
    }
    return hash % TABLE_SIZE;
}

void addWord(char *english, char *cat) {
    int index = hash(english);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));

    newNode->english = strdup(english);
    newNode->cat = strdup(cat);
    newNode->next = table[index];
    table[index] = newNode;
}

char *translate(char *english) {
    int index = hash(english);

    HashNode *node = table[index];
    while (node != NULL) {
        if (strcmp(node->english, english) == 0) {
            return strdup(node->cat);
        }
        node = node->next;
    }

    return NULL;
}

int main() {
    addWord("hello", "miaow meow");
    addWord("world", "purr purr");
    addWord("how", "meow how");
    addWord("are", "purr are");
    addWord("you", "you meow");

    char input[100];
    while (1) {
        printf("Enter English word: ");
        scanf("%s", input);

        char *translation = translate(input);
        if (translation != NULL) {
            printf("Translation: %s\n", translation);
        } else {
            printf("Unknown word.\n");
        }

        free(translation);
    }

    return 0;
}