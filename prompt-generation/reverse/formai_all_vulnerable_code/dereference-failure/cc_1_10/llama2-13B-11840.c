//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_ROMANCE_SCORE 10

// Function to calculate the romance score of a given text
int calculate_romance_score(const char *text) {
    int score = 0;
    int words_count = strcspn(text, " ");
    for (int i = 0; i < words_count; i++) {
        if (strchr("love heart sweet", text[i]) != NULL) {
            score++;
        }
    }
    return score;
}

// Function to generate a poetic message based on the input text
void generate_poem(const char *text) {
    int romance_score = calculate_romance_score(text);
    char *poem = malloc(MAX_LINE_LENGTH * sizeof(char));
    int current_line = 0;

    // Generate the poem line by line
    for (int i = 0; i < romance_score; i++) {
        switch (i % 3) {
            case 0:
                strcat(poem, "My love, you are the ");
                break;
            case 1:
                strcat(poem, "sweetest rose in the ");
                break;
            case 2:
                strcat(poem, "garden of my heart, ");
                break;
        }
        current_line += strlen(poem);
        if (current_line >= MAX_LINE_LENGTH) {
            break;
        }
    }
    printf("%s\n", poem);
    free(poem);
}

int main() {
    char text[MAX_LINE_LENGTH];
    printf("Enter a text to analyze: ");
    fgets(text, MAX_LINE_LENGTH, stdin);
    generate_poem(text);
    return 0;
}