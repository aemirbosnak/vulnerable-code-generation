//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void pig_latin(char *word) {
    int i, consonant_count = 0;
    char temp;

    // Check if word is empty
    if (*word == '\0') {
        printf("Empty string\n");
        return;
    }

    // Move to the first consonant or the first letter of the word
    for (i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i]) && (i == 0 || !isalpha(word[i - 1]))) {
            consonant_count++;
            break;
        }
    }

    // If the entire word is a vowel, place it at the end of the word
    if (consonant_count == 0) {
        strcat(word, word);
        strcat(word, "way");
        return;
    }

    // Move the first consonant to the end of the word and add 'ay'
    temp = word[i];
    strncpy(word + i, word, consonant_count);
    word[i + consonant_count] = '\0';
    strcat(word, &temp);
    strcat(word, "ay");
}

int main(int argc, char **argv) {
    char input[MAX_LENGTH], output[MAX_LENGTH];

    // Check for command line arguments
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // Copy the input text to the input array
    strcpy(input, argv[1]);

    // Call pig_latin function to convert each word to pig latin
    pig_latin(input);

    // Copy the modified text to the output array
    strcpy(output, input);

    // Print the pig latin text
    printf("Pig Latin: %s\n", output);

    return 0;
}