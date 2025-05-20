//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <string.h>

// A structure to represent a word
typedef struct {
    char *word;
    int count;
} Word;

// A function to check if a word is in the dictionary
int isWordInDictionary(Word* dictionary, char* word) {
    for (int i = 0; i < dictionary->count; i++) {
        if (strcmp(dictionary->word[i], word) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Not found
}

// A function to check if a sentence is spelled correctly
int isSentenceSpelledCorrectly(char* sentence) {
    Word* dictionary = (Word*)malloc(sizeof(Word) * 100); // 100 words in the dictionary
    Word currentWord;

    // Populate the dictionary with words
    strcpy(currentWord.word, "apple");
    dictionary[0].word = currentWord.word;
    dictionary[0].count = 1;
    currentWord.word = "banana";
    dictionary[1].word = currentWord.word;
    dictionary[1].count = 1;
    currentWord.word = "carrot";
    dictionary[2].word = currentWord.word;
    dictionary[2].count = 1;

    // Check if each word in the sentence is in the dictionary
    for (int i = 0; i < strlen(sentence); i++) {
        if (isWordInDictionary(dictionary, sentence + i) == 0) {
            printf("The sentence '%s' is not spelled correctly.\n", sentence);
            return 0; // Not spelled correctly
        }
    }
    printf("The sentence '%s' is spelled correctly.\n", sentence);
    return 1; // Spelled correctly
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove newline character
    if (isSentenceSpelledCorrectly(sentence)) {
        printf("The sentence is spelled correctly.\n");
    }
    return 0;
}