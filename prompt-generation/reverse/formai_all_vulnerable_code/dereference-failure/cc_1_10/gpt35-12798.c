//FormAI DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Function for checking spelling mistakes */
void spellCheck(char *word, char *dictionary[])
{
    int i, found = 0;

    /* Convert word to lowercase for matching with dictionary */
    for (i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }

    /* Loop through dictionary to find matching word */
    for (i = 0; dictionary[i] != NULL; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("%s is spelled correctly!\n", word);
    } else {
        printf("Oops! Did you mean ");

        /* Generate suggestions for misspelled words */
        for (i = 0; dictionary[i] != NULL; i++) {
            char temp[50];
            strcpy(temp, dictionary[i]);
            int j;

            /* Convert dictionary word to lowercase and remove any non-alphabets */
            for (j = 0; temp[j] != '\0'; j++) {
                if (!isalpha(temp[j])) {
                    temp[j] = '\0';
                    break;
                }
                temp[j] = tolower(temp[j]);
            }

            /* If dictionary word contains the same letters as the misspelled word, suggest it as a correction */
            if (strcmp(temp, word) != 0 && strstr(temp, word)) {
                printf("%s", dictionary[i]);

                /* Add comma if not last suggestion */
                if (dictionary[i+1] != NULL) {
                    printf(", ");
                }
            }
        }

        printf("?\n");
    }
}

int main(void)
{
    /* Dictionary of words */
    char *dictionary[] = {
        "hello",
        "world",
        "apple",
        "boy",
        "cat",
        "dog",
        "elephant",
        "flower",
        "game",
        "house",
        NULL
    };

    /* Input string */
    char *input = (char*) malloc(sizeof(char)*50);
    printf("Let's check if your word is spelled correctly! Enter a word: ");
    scanf("%s", input);

    spellCheck(input, dictionary);

    free(input);
    return 0;
}