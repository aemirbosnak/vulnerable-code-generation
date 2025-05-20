//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to remove trailing punctuation from word
void trim_punct(char *word) {
    int i = strlen(word) - 1;
    while (ispunct(word[i])) {
        word[i] = '\0';
        i--;
    }
}

// function to convert word to lowercase
void to_lower(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int main() {
    // declare variables
    char sentence[1000], word[50], dict_word[50];
    int i, j = 0, k = 0, match = 0, count = 0;

    // ask user for input sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // loop through sentence to extract words
    for (i = 0; sentence[i]; i++) {
        // if not a space or punctuation, add to word
        if (!isspace(sentence[i]) && !ispunct(sentence[i])) {
            word[j] = sentence[i];
            j++;
        }
        // if space or punctuation, check if word exists in dictionary
        else {
            // trim ending punctuation from word
            trim_punct(word);

            // convert word to lowercase
            to_lower(word);

            // open dictionary file for reading
            FILE *fp = fopen("dictionary.txt", "r");

            // loop through dictionary file to find word
            while (fscanf(fp, "%s", dict_word) != EOF) {
                if (strcmp(word, dict_word) == 0) {
                    match = 1;
                    break;
                }
            }

            // close dictionary file
            fclose(fp);

            // if word not found in dictionary, print misspelled word
            if (!match) {
                printf("%s ", word);
                count++;
            }

            // reset variables for next word
            memset(word, 0, sizeof(word));
            j = 0;
            match = 0;
        }
    }

    // print number of misspelled words and exit program
    printf("\n\nTotal Misspelled Words: %d\n", count);
    return 0;
}