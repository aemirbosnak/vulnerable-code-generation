//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100

// function to find the index of a word in the dictionary
int find_word_index(char *dict[], int dict_size, char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict[i], word) == 0) {
            return i;
        }
    }
    return -1; // word not found
}

// function to translate a sentence recursively
void translate_sentence(char *dict[], int dict_size, char *sentence) {
    // base case: sentence is empty
    if (strlen(sentence) == 0) {
        printf("\n");
        return;
    }

    // find the index of the first word in the sentence
    char *word = strtok(sentence, " ");
    int word_index = find_word_index(dict, dict_size, word);

    // if the word is not found, print an error message and exit the program
    if (word_index == -1) {
        printf("Error: Word \"%s\" not found in dictionary.\n", word);
        exit(1);
    }

    // print the translation of the word
    printf("%s ", dict[word_index]);

    // recursively translate the rest of the sentence
    translate_sentence(dict, dict_size, strtok(NULL, " "));
}

// main function
int main() {
    // dictionary of words and their translations
    char *dict[] = {"cat", "dog", "bird", "fish", "hamster"};

    // size of the dictionary
    int dict_size = sizeof(dict) / sizeof(dict[0]);

    // sample sentence to translate
    char *sentence = "The cat sat on the mat.";

    // translate the sentence recursively
    translate_sentence(dict, dict_size, sentence);

    return 0;
}