//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TABLE_SIZE 101

typedef struct Node {
    char *human_word;
    char *alien_word;
    struct Node *next;
} Node;

Node **hash_table;

int hash_func(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += tolower(str[i]);
    }
    return hash % TABLE_SIZE;
}

Node *create_node(char *human_word, char *alien_word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->human_word = strdup(human_word);
    new_node->alien_word = strdup(alien_word);
    new_node->next = NULL;
    return new_node;
}

void add_to_hash(char *human_word, char *alien_word) {
    int index = hash_func(human_word);
    Node *new_node = create_node(human_word, alien_word);

    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        Node *current = hash_table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

char *translate(char *human_word) {
    int index = hash_func(human_word);
    Node *current = hash_table[index];

    while (current != NULL) {
        if (strcmp(current->human_word, human_word) == 0) {
            return current->alien_word;
        }
        current = current->next;
    }

    return "Invalid human word.";
}

int main() {
    srand(time(NULL));

    hash_table = (Node **)calloc(TABLE_SIZE, sizeof(Node *));

    // Add some human-alien word pairs
    add_to_hash("hello", "g'thok");
    add_to_hash("goodbye", "neH");
    add_to_hash("yes", "qon");
    add_to_hash("no", "beq");

    int num_queries = 5;
    for (int i = 0; i < num_queries; i++) {
        char human_word[20];
        printf("Enter a human word: ");
        scanf("%s", human_word);
        getchar(); // consume newline character

        char *alien_word = translate(human_word);
        printf("Alien word: %s\n", alien_word);

        free(alien_word);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = hash_table[i];
        while (current != NULL) {
            free(current->human_word);
            free(current->alien_word);
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(hash_table);

    return 0;
}