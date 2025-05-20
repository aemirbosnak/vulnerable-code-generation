//FormAI DATASET v1.0 Category: Spell checking ; Style: optimized
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_MISTAKES 5

int num_mistakes = 0; // global variable to keep track of number of mistakes

void check_spelling(char* word) {
    // remove punctuation marks at the end of the word
    int len = strlen(word);
    while (len > 0 && ispunct(word[len-1])) {
        word[len-1] = '\0';
        len--;
    }

    // check the word against a dictionary
    int found = 0;
    FILE *fp = fopen("dictionary.txt", "r");
    char dict_word[MAX_WORD_LEN];
    while (fgets(dict_word, MAX_WORD_LEN, fp)) {
        dict_word[strcspn(dict_word, "\n")] = '\0'; // remove newline character
        if (strcasecmp(word, dict_word) == 0) { // case-insensitive string comparison
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found) {
        num_mistakes++;
        if (num_mistakes <= MAX_MISTAKES) {
            printf("Did you mean: %s?\n", dict_word); // suggest a correction
        }
    }
}

int main() {
    char sentence[MAX_WORD_LEN*10];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_WORD_LEN*10, stdin);

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        check_spelling(token);
        token = strtok(NULL, " ");
    }

    if (num_mistakes == 0) {
        printf("No spelling mistakes found.\n");
    } else if (num_mistakes == 1) {
        printf("1 spelling mistake found.\n");
    } else {
        printf("%d spelling mistakes found.\n", num_mistakes);
    }

    return 0;
}