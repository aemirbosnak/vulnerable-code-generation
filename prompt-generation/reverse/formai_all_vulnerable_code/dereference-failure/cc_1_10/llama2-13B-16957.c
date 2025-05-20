//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUMBER_OF_WORDS 100

// Function to generate a random word from a list of words
void generate_random_word(char *word_list[], int num_words) {
    int i = rand() % num_words;
    strcpy(word_list[i], word_list[i]);
}

// Function to print a word in a fancy way
void print_word(char *word) {
    int i = 0;
    for (; i < strlen(word); i++) {
        if (isupper(word[i])) {
            printf("%c", word[i] - 'A' + 'A');
        } else {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}

// Function to print a poem
void print_poem(char *poem) {
    int line_length = strcspn(poem, "\n");
    int num_lines = strlen(poem) / line_length + 1;
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", poem + i * line_length);
    }
}

int main() {
    // List of words
    char word_list[MAX_NUMBER_OF_WORDS][MAX_LINE_LENGTH] = {
        "love", "life", "laughter", "tears", "dreams", "happiness", "sadness", "joy", "pain",
        "hope", "faith", "courage", "heart", "soul", "mind", "body", "spirit"
    };

    // Generate a random word from the list
    generate_random_word(word_list, MAX_NUMBER_OF_WORDS);

    // Print the word in a fancy way
    print_word(word_list[0]);

    // Print the poem
    char poem[] = "The world is a canvas, paint it with love and laughter\n"
                  "Embrace the tears, for they make the laughter sweeter\n"
                  "Chase your dreams, but never forget to dream\n"
                  "Happiness is a choice, so choose it every day\n"
                  "Sadness is a lesson, learn from it and move on\n"
                  "Joy is in the journey, not just the destination\n"
                  "Pain is a teacher, listen to its wisdom\n"
                  "Hope is the light that guides you through the darkness\n"
                  "Faith is the bridge that connects you to the divine\n"
                  "Courage is the fire that burns within your heart\n"
                  "Heart, soul, mind, and body, all one and the same\n"
                  "Embrace the beauty, embrace the pain\n"
                  "For in the end, it is love that remains\n";
    print_poem(poem);

    return 0;
}