//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

/* Function to check if a word is in the dictionary */
int is_in_dictionary(char* word) {
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        return 0;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dictionary_file)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (tolower(line[i])!= tolower(word[i])) {
                break;
            }
        }
        if (i == strlen(word)) {
            return 1;
        }
    }

    fclose(dictionary_file);
    return 0;
}

/* Function to suggest corrections for a misspelled word */
void suggest_corrections(char* word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) {
            printf("%c", tolower(word[i]));
        } else {
            printf("%c", word[i]);
        }
    }
    printf("? ");
}

/* Main function */
int main() {
    char sentence[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        strcpy(word, token);
        int is_misspelled = 0;
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (!isalpha(word[j])) {
                continue;
            }
            if (!is_in_dictionary(word)) {
                is_misspelled = 1;
                break;
            }
        }
        if (is_misspelled) {
            printf("Misspelled word: %s\n", word);
            suggest_corrections(word);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}