//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int is_end_of_word;
    struct Node *children[26];
} Node;

Node *create_node() {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->is_end_of_word = 0;
    for (int i = 0; i < 26; i++) {
        new_node->children[i] = NULL;
    }
    return new_node;
}

void insert(Node *root, const char *word) {
    Node *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }
    current->is_end_of_word = 1;
}

int search(Node *root, const char *word) {
    Node *current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL) {
            return 0;
        }
        current = current->children[index];
    }
    return current != NULL && current->is_end_of_word;
}

int main() {
    int num_words;
    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &num_words);

    Node *root = create_node();
    for (int i = 0; i < num_words; i++) {
        char word[50];
        printf("Enter word %d: ", i + 1);
        scanf("%s", word);
        insert(root, word);
    }

    char input_word[50];
    while (1) {
        printf("Enter a word to check its spelling: ");
        scanf("%s", input_word);

        if (strcmp(input_word, "quit") == 0) {
            break;
        }

        int result = search(root, input_word);
        if (result) {
            printf("The word '%s' is spelled correctly.\n", input_word);
        } else {
            printf("The word '%s' is not in the dictionary.\n", input_word);
        }
    }

    return 0;
}