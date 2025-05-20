//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove non-letter characters from a word
void removeNonLetters(char* word) {
    int i = 0, j = 0;
    while (word[i]) {
        if (isalpha(word[i])) {
            word[j++] = tolower(word[i]);
        }
        i++;
    }
    word[j] = '\0';
}

// Function to check if a word exists in the dictionary
int checkWord(char* word, char** dictionary, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char** dictionary;
    int dictSize = 5;
    dictionary = (char**) malloc(dictSize * sizeof(char*));
    dictionary[0] = "castle";
    dictionary[1] = "sword";
    dictionary[2] = "queen";
    dictionary[3] = "knight";
    dictionary[4] = "armor";

    char* sentence = "The queen was in her castle with her knight and sword, wearing her armor.";
    char* delimiters = " ,.-\n\r\t";
    char* word = strtok(sentence, delimiters);

    while (word != NULL) {
        removeNonLetters(word);
        if (!checkWord(word, dictionary, dictSize)) {
            printf("'%s' is not a valid word.\n", word);
        }
        word = strtok(NULL, delimiters);
    }

    return 0;
}