//FormAI DATASET v1.0 Category: Spell checking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief This function returns the minimum value between two integers.
 */
int min(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
}

/**
 * @brief This function creates a matrix of dimensions num_rows and num_cols.
 */
char **create_matrix(int num_rows, int num_cols) {
    char **matrix = (char **) malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = (char *) malloc(num_cols * sizeof(char));
        for (int j = 0; j < num_cols; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

/**
 * @brief This function frees the memory allocated for a matrix.
 */
void free_matrix(char **matrix, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/**
 * @brief This function performs spell checking on a given input string.
 */
void spell_check(char *input_string, char **dictionary, int num_words, int max_typo_distance) {
    const int input_len = strlen(input_string);
    char **matrix = create_matrix(input_len + 1, num_words + 1);

    // Initialize first row and first column of matrix
    for (int i = 0; i <= input_len; i++) {
        matrix[i][0] = i;
    }
    for (int i = 0; i <= num_words; i++) {
        matrix[0][i] = i;
    }

    // Calculate typo distance for each word in the dictionary
    for (int i = 1; i <= num_words; i++) {
        const char *word = dictionary[i - 1];
        const int word_len = strlen(word);
        for (int j = 1; j <= input_len; j++) {
            const char input_char = tolower(input_string[j - 1]);
            const char word_char = tolower(word[j - 1]);
            const int typo_cost = input_char == word_char ? 0 : 1;
            matrix[j][i] = min(min(matrix[j - 1][i] + 1,
                                    matrix[j][i - 1] + 1),
                                    matrix[j - 1][i - 1] + typo_cost);
        }
    }

    // Find suggestions for misspelled words in the input string
    for (int j = 1; j <= input_len; j++) {
        bool misspelled = true;
        for (int i = 1; i <= num_words; i++) {
            const char *word = dictionary[i - 1];
            const int word_len = strlen(word);
            if (matrix[j][i] <= max_typo_distance) {
                misspelled = false;
                break;
            }
        }
        if (misspelled) {
            printf("'%c' at position %d is misspelled. Suggestions:\n", input_string[j - 1], j);
            for (int i = 1; i <= num_words; i++) {
                const char *word = dictionary[i - 1];
                const int word_len = strlen(word);
                if (abs(word_len - (j - 1)) <= max_typo_distance) {
                    printf("- %s\n", word);
                }
            }
        }
    }

    free_matrix(matrix, input_len + 1);
}

int main() {
    const int max_words = 100;
    char **dictionary = create_matrix(max_words, 50);
    
    // Populate dictionary with some sample words
    strcpy(dictionary[0], "hello");
    strcpy(dictionary[1], "world");
    strcpy(dictionary[2], "apple");
    strcpy(dictionary[3], "banana");

    // Perform spell checking on some sample input strings
    spell_check("hllo wrold", dictionary, 4, 2);
    spell_check("hppey brnnnaa", dictionary, 4, 3);

    free_matrix(dictionary, max_words);
    return 0;
}