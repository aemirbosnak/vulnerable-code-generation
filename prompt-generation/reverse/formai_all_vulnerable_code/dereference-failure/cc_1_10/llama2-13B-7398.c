//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define MAX_CHARS 5000

// Define a struct to hold our text data
struct text_data {
    char *text;
    size_t len;
};

// Function to generate a random poem
void generate_poem(struct text_data *data) {
    // Generate a random number of lines and words per line
    int num_lines = rand() % 5 + 2;
    int words_per_line = rand() % 3 + 2;

    // Allocate memory for the text data
    data->text = malloc(num_lines * words_per_line * sizeof(char));
    data->len = 0;

    // Loop through each line and generate words
    for (int i = 0; i < num_lines; i++) {
        for (int j = 0; j < words_per_line; j++) {
            // Generate a random word
            char word[MAX_CHARS];
            snprintf(word, sizeof(word), "%c%c%c%c%c",
                     'a' + (rand() % 26), 'b' + (rand() % 26),
                     'c' + (rand() % 26), 'd' + (rand() % 26),
                     'e' + (rand() % 26));

            // Add the word to the line
            strncat(data->text + data->len, word, sizeof(word));
            data->len += strlen(word);

            // Check if we've reached the end of the line
            if (j == words_per_line - 1) {
                // Add a newline character
                data->text[data->len] = '\n';
                data->len++;
            }
        }
    }
}

int main() {
    // Create a struct to hold our text data
    struct text_data data;

    // Generate a poem and print it out
    generate_poem(&data);
    printf("%s\n", data.text);

    // Free the memory allocated for the text data
    free(data.text);

    return 0;
}