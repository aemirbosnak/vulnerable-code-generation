//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int is_end_of_word;
    struct Node* children[26];
} Node;

Node* new_node() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->is_end_of_word = 0;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

void insert(Node* root, const char* word) {
    Node* current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL)
            current->children[index] = new_node();
        current = current->children[index];
    }
    current->is_end_of_word = 1;
}

int search(Node* root, const char* word) {
    Node* current = root;
    for (int level = 0; level < strlen(word); level++) {
        int index = tolower(word[level]) - 'a';
        if (current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    return current->is_end_of_word;
}

int prefix_search(Node* root, const char* prefix) {
    Node* current = root;
    for (int level = 0; level < strlen(prefix); level++) {
        int index = tolower(prefix[level]) - 'a';
        if (current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    return 1;
}

int main() {
    Node* root = new_node();
    const char* words[] = {"apple", "banana", "orange", "grape", "kiwi", "mango"};

    for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
        insert(root, words[i]);

    char input[100];
    while (1) {
        printf("Enter a word to check (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0)
            break;

        int result = search(root, input);
        if (result)
            printf("The word '%s' is in the dictionary.\n", input);
        else {
            printf("The word '%s' is not in the dictionary.\n", input);
            int prefix_found = prefix_search(root, input);
            if (prefix_found)
                printf("But it is a prefix of a word in the dictionary.\n");
            else
                printf("And it has no prefixes in the dictionary.\n");
        }
    }

    return 0;
}