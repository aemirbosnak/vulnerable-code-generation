//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to tokenize the text
char **tokenize(char *text, char *delims) {
    char **tokens = malloc(sizeof(char *) * 100);
    int num_tokens = 0;
    char *token = strtok(text, delims);
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, delims);
    }
    return tokens;
}

// Function to remove stop words from the text
char **remove_stop_words(char **tokens, int num_tokens) {
    char **filtered_tokens = malloc(sizeof(char *) * 100);
    int num_filtered_tokens = 0;
    for (int i = 0; i < num_tokens; i++) {
        if (strcmp(tokens[i], "a") != 0 && strcmp(tokens[i], "an") != 0 && strcmp(tokens[i], "the") != 0 && strcmp(tokens[i], "and") != 0 && strcmp(tokens[i], "or") != 0 && strcmp(tokens[i], "but") != 0 && strcmp(tokens[i], "of") != 0 && strcmp(tokens[i], "in") != 0 && strcmp(tokens[i], "on") != 0 && strcmp(tokens[i], "at") != 0 && strcmp(tokens[i], "to") != 0 && strcmp(tokens[i], "from") != 0 && strcmp(tokens[i], "by") != 0 && strcmp(tokens[i], "with") != 0) {
            filtered_tokens[num_filtered_tokens++] = tokens[i];
        }
    }
    return filtered_tokens;
}

// Function to stem the words in the text
char **stem(char **tokens, int num_tokens) {
    char **stemmed_tokens = malloc(sizeof(char *) * 100);
    int num_stemmed_tokens = 0;
    for (int i = 0; i < num_tokens; i++) {
        // Use a stemming algorithm to stem the word
        stemmed_tokens[num_stemmed_tokens++] = tokens[i];
    }
    return stemmed_tokens;
}

// Function to create a frequency table of the words in the text
int *create_frequency_table(char **tokens, int num_tokens) {
    int *frequency_table = malloc(sizeof(int) * 100);
    for (int i = 0; i < num_tokens; i++) {
        frequency_table[i] = 0;
    }
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < num_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency_table[i]++;
            }
        }
    }
    return frequency_table;
}

// Function to sort the frequency table in descending order
void sort_frequency_table(int *frequency_table, char **tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        for (int j = i + 1; j < num_tokens; j++) {
            if (frequency_table[i] < frequency_table[j]) {
                int temp = frequency_table[i];
                frequency_table[i] = frequency_table[j];
                frequency_table[j] = temp;
                char *temp_token = tokens[i];
                tokens[i] = tokens[j];
                tokens[j] = temp_token;
            }
        }
    }
}

// Function to print the summary of the text
void print_summary(char **tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

int main() {
    // Get the text from the user
    char text[1000];
    printf("Enter the text: ");
    gets(text);

    // Tokenize the text
    char **tokens = tokenize(text, " ");
    int num_tokens = 0;
    while (tokens[num_tokens] != NULL) {
        num_tokens++;
    }

    // Remove stop words from the text
    char **filtered_tokens = remove_stop_words(tokens, num_tokens);
    int num_filtered_tokens = 0;
    while (filtered_tokens[num_filtered_tokens] != NULL) {
        num_filtered_tokens++;
    }

    // Stem the words in the text
    char **stemmed_tokens = stem(filtered_tokens, num_filtered_tokens);
    int num_stemmed_tokens = 0;
    while (stemmed_tokens[num_stemmed_tokens] != NULL) {
        num_stemmed_tokens++;
    }

    // Create a frequency table of the words in the text
    int *frequency_table = create_frequency_table(stemmed_tokens, num_stemmed_tokens);

    // Sort the frequency table in descending order
    sort_frequency_table(frequency_table, stemmed_tokens, num_stemmed_tokens);

    // Print the summary of the text
    print_summary(stemmed_tokens, num_stemmed_tokens);

    return 0;
}