//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

typedef struct TrieNode {
    bool is_word;
    struct TrieNode *children[26];
} TrieNode;

TrieNode *create_trie_node() {
    TrieNode *node = malloc(sizeof(TrieNode));
    node->is_word = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert_word(TrieNode *root, char *word) {
    TrieNode *current_node = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current_node->children[index] == NULL) {
            current_node->children[index] = create_trie_node();
        }
        current_node = current_node->children[index];
    }
    current_node->is_word = true;
}

bool search_word(TrieNode *root, char *word) {
    TrieNode *current_node = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current_node->children[index] == NULL) {
            return false;
        }
        current_node = current_node->children[index];
    }
    return current_node->is_word;
}

char *get_closest_word(TrieNode *root, char *word) {
    int min_distance = MAX_WORD_LENGTH;
    char *closest_word = NULL;
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            char new_word[strlen(word) + 2];
            sprintf(new_word, "%s%c", word, i + 'a');
            int distance = levenshtein_distance(word, new_word);
            if (distance < min_distance) {
                min_distance = distance;
                closest_word = strdup(new_word);
            }
            char *child_closest_word = get_closest_word(root->children[i], word);
            if (child_closest_word != NULL && levenshtein_distance(word, child_closest_word) < min_distance) {
                min_distance = levenshtein_distance(word, child_closest_word);
                closest_word = child_closest_word;
            }
        }
    }
    return closest_word;
}

int levenshtein_distance(char *word1, char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }
    return matrix[len1][len2];
}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    TrieNode *root = create_trie_node();
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary, "%s\n", word) != EOF) {
        insert_word(root, word);
    }
    fclose(dictionary);
    char input_word[MAX_WORD_LENGTH];
    printf("Enter a word to check spelling: ");
    scanf("%s", input_word);
    if (search_word(root, input_word)) {
        printf("The word is spelled correctly.\n");
    } else {
        char *closest_word = get_closest_word(root, input_word);
        printf("The word is spelled incorrectly.\n");
        printf("The closest word in the dictionary is: %s\n", closest_word);
        free(closest_word);
    }
    return EXIT_SUCCESS;
}