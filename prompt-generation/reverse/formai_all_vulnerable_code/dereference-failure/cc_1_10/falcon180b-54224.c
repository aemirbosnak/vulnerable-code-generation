//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 // Maximum number of words in the dictionary

typedef struct {
    char* english;
    char* french;
} word_pair;

word_pair dictionary[MAX_WORDS]; // Dictionary of words
int num_words = 0; // Number of words in the dictionary

// Function to add a word to the dictionary
void add_word(char* english, char* french) {
    if (num_words >= MAX_WORDS) {
        printf("Dictionary is full!\n");
        return;
    }

    dictionary[num_words].english = strdup(english);
    dictionary[num_words].french = strdup(french);

    num_words++;
}

// Function to translate a sentence
void translate_sentence(char* sentence) {
    char* token = strtok(sentence, " "); // Tokenize the sentence into words

    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s -> %s\n", token, dictionary[i].french);
                break;
            }
        }

        if (i == num_words) {
            printf("%s not found in dictionary!\n", token);
        }

        token = strtok(NULL, " "); // Get the next token
    }
}

int main() {
    // Add some words to the dictionary
    add_word("cat", "chat");
    add_word("dog", "chien");
    add_word("bird", "oiseau");

    // Translate a sentence
    char* sentence = "The cat sat on the mat. ";
    translate_sentence(sentence);

    return 0;
}