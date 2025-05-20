//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to count the number of words in a sentence
int count_words(char* sentence) {

    int count = 0;
    int length = strlen(sentence);
    int i = 0;

    // loop through the sentence
    while (i < length) {

        // if the current character is a whitespace
        if (isspace(sentence[i])) {
            count++;

            // skip all the whitespaces until the next word
            while (i < length && isspace(sentence[i]))
                i++;
        }

        // move to the next character
        i++;
    }

    // increment the count for the last word
    if (!isspace(sentence[length - 1]))
        count++;

    return count;
}

int main() {

    char sentence[256];

    // get user input
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // remove the trailing newline character
    sentence[strcspn(sentence, "\n")] = 0;

    // count the number of words and display the result
    int word_count = count_words(sentence);
    printf("The sentence \"%s\" has %d words.\n", sentence, word_count);

    return 0;
}