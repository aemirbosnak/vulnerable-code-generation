//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
/*
 * This program reads in a text file and checks the spelling of each word
 * against a dictionary file. It prints out misspelled words along with
 * their line numbers and suggestions for correct spelling.
 *
 * USAGE:
 *  $ ./spell_check <text_file> <dictionary_file>
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_SUGGESTIONS 10

int line_number = 1;

/*
 * Nodes for the binary search tree used to store the dictionary entries
 */
typedef struct node {
    char word[MAX_WORD_LENGTH];
    struct node *left;
    struct node *right;
} node;

/*
 * Insert a new word into the binary search tree.
 * Takes a pointer to the root node and the word to insert.
 * Returns a pointer to the updated root node.
 */
node *insert_word(node *root, char *word) {
    if (root == NULL) {
        root = (node *) malloc(sizeof(node));
        strncpy(root->word, word, MAX_WORD_LENGTH);
        root->left = NULL;
        root->right = NULL;
    } else if (strcmp(word, root->word) < 0) {
        root->left = insert_word(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert_word(root->right, word);
    }
    return root;
}

/*
 * Traverse the binary search tree and free all memory associated with it.
 * Takes a pointer to the root node.
 */
void free_tree(node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/*
 * Check if a word is spelled correctly by searching the binary search tree.
 * Takes a pointer to the root node and the word to check.
 * Returns true if the word is found in the tree, false otherwise.
 */
bool check_word(node *root, char *word) {
    if (root == NULL) {
        return false;
    }
    if (strcmp(word, root->word) == 0) {
        return true;
    } else if (strcmp(word, root->word) < 0) {
        return check_word(root->left, word);
    } else {
        return check_word(root->right, word);
    }
}

/*
 * Get a list of suggested spellings for a misspelled word.
 * Takes a pointer to the root node of the binary search tree,
 * the misspelled word and a pointer to the list of suggestions.
 * Stores up to MAX_SUGGESTIONS suggestions in the list.
 * Returns the number of suggestions stored in the list.
 */
int get_suggestions(node *root, char *word, char **suggestions) {
    char *temp_word = (char *) malloc((MAX_WORD_LENGTH + 1) * sizeof(char));
    strncpy(temp_word, word, MAX_WORD_LENGTH);

    int num_suggestions = 0;
    int temp_length = strlen(temp_word);

    /*
     * Try adding one character at different positions in the word
     */
    for (int i = 0; i <= temp_length; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            memmove(temp_word + i + 1, temp_word + i, temp_length - i + 1);
            temp_word[i] = c;
            if (check_word(root, temp_word)) {
                strncpy(suggestions[num_suggestions++], temp_word, MAX_WORD_LENGTH);
                if (num_suggestions == MAX_SUGGESTIONS) {
                    free(temp_word);
                    return num_suggestions;
                }
            }
            memmove(temp_word + i, temp_word + i + 1, temp_length - i);
        }
    }

    /*
     * Try deleting each character in the word
     */
    for (int i = 0; i < temp_length; i++) {
        memmove(temp_word + i, temp_word + i + 1, temp_length - i);
        if (check_word(root, temp_word)) {
            strncpy(suggestions[num_suggestions++], temp_word, MAX_WORD_LENGTH);
            if (num_suggestions == MAX_SUGGESTIONS) {
                free(temp_word);
                return num_suggestions;
            }
        }
        memmove(temp_word + i + 1, temp_word + i, temp_length - i);
    }

    /*
     * Try substituting each character in the word with other letters
     */
    for (int i = 0; i < temp_length; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (temp_word[i] == c) {
                continue;
            }
            temp_word[i] = c;
            if (check_word(root, temp_word)) {
                strncpy(suggestions[num_suggestions++], temp_word, MAX_WORD_LENGTH);
                if (num_suggestions == MAX_SUGGESTIONS) {
                    free(temp_word);
                    return num_suggestions;
                }
            }
            temp_word[i] = word[i];
        }
    }

    free(temp_word);
    return num_suggestions;
}

/*
 * Check the spelling of a single word and print out any suggestions if it is
 * misspelled.
 * Takes the root node of the dictionary binary search tree,
 * the current word being checked and a boolean flag indicating if we are
 * currently inside a word (to ignore apostrophes in contractions or possessives).
 */
void check_single_word(node *root, char *word, bool in_word) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    if (!check_word(root, word) && !in_word) {
        char **suggestions = (char **) malloc(MAX_SUGGESTIONS * sizeof(char *));
        for (int i = 0; i < MAX_SUGGESTIONS; i++) {
            suggestions[i] = (char *) malloc((MAX_WORD_LENGTH + 1) * sizeof(char));
        }
        int num_suggestions = get_suggestions(root, word, suggestions);
        printf("Misspelled word: %s (line %d)\n", word, line_number);
        printf("Suggestions:\n");
        for (int i = 0; i < num_suggestions; i++) {
            printf("  %s\n", suggestions[i]);
        }
        for (int i = 0; i < MAX_SUGGESTIONS; i++) {
            free(suggestions[i]);
        }
        free(suggestions);
    }
}

/*
 * Main function that reads in the text file and dictionary file,
 * spell checks each word in the text file and prints out any misspellings.
 */
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <text_file> <dictionary_file>\n", argv[0]);
        return 1;
    }

    FILE *text_file = fopen(argv[1], "r");
    FILE *dictionary_file = fopen(argv[2], "r");

    if (text_file == NULL) {
        printf("Error: could not open text file '%s'\n", argv[1]);
        return 1;
    }
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file '%s'\n", argv[2]);
        fclose(text_file);
        return 1;
    }

    node *root = NULL;

    // Load dictionary into binary search tree
    char dict_word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", dict_word) == 1) {
        root = insert_word(root, dict_word);
    }

    // Spell check each word in the text file
    char text_word[MAX_WORD_LENGTH];
    bool in_word = false;
    int c;
    while ((c = fgetc(text_file)) != EOF) {
        if (isalpha(c)) {
            if (!in_word) {
                in_word = true;
                memset(text_word, 0, MAX_WORD_LENGTH);
            }
            strncat(text_word, (char *) &c, 1);
        } else if (in_word) {
            in_word = false;
            check_single_word(root, text_word, false);
        }
        if (c == '\n') {
            line_number++;
        }
    }

    if (in_word) {
        check_single_word(root, text_word, true);
    }

    // Clean up and exit
    free_tree(root);
    fclose(text_file);
    fclose(dictionary_file);
    return 0;
}