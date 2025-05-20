//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    printf("The Adventure of the Text Summarizer\n\n");

    char text[1000];
    printf("Enter the text to be summarized: ");
    fgets(text, 1000, stdin);

    // Removing new line character from the input
    text[strcspn(text, "\n")] = 0;

    char vowels[] = "aeiouAEIOU";
    int sentences = 0, words = 0, characters = 0;
    int word_count = 0, sentence_count = 0, vowels_count = 0;

    for (int i = 0; i < strlen(text); i++) {
        characters++;

        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences++;
            sentence_count += word_count;
            word_count = 0;
        } else if (text[i] == ' ') {
            if (word_count > 0 && strchr(vowels, text[i - 1]) != NULL) {
                vowels_count++;
            }
            words++;
            word_count++;
        } else {
            word_count++;
        }
    }

    // Handle the last sentence
    if (word_count > 0) {
        sentences++;
        sentence_count += word_count;
    }

    int average_words_per_sentence = sentence_count / sentences;
    int average_vowels_per_word = vowels_count / words;

    printf("\n\nThe summary of the text is: \n");

    if (average_words_per_sentence < 15 && average_vowels_per_word > 5) {
        printf("The text is easy to read.\n");
    } else if (average_words_per_sentence >= 15 && average_vowels_per_word <= 5) {
        printf("The text is difficult to read.\n");
    } else {
        printf("The text is moderately easy to read.\n");
    }

    return 0;
}