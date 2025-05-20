//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of occurrences of a word in a text
int count_word(char* text, char* word)
{
    int count = 0;
    char *token;

    token = strtok(text, " ");
    while (token!= NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to find the most common words in a text
void find_most_common_words(char* text, int max_count, int *count, char **words)
{
    char *token;
    int i = 0;
    int current_count = 0;

    token = strtok(text, " ");
    while (token!= NULL) {
        if (current_count < max_count) {
            count[i] = current_count;
            words[i] = token;
            current_count++;
            i++;
        }

        token = strtok(NULL, " ");
    }

    if (i > 0) {
        count[i] = current_count;
        words[i] = token;
    }
}

int main()
{
    char text[100];
    int max_count = 0;
    int count[100];
    char *words[100];

    printf("Enter the text: ");
    scanf("%[^\n]s", text);

    strcpy(words[0], text);
    max_count = count_word(text, words[0]);

    for (int i = 1; i < 100; i++) {
        count_word(text, words[i]);
        if (count[i] > max_count) {
            strcpy(words[0], words[i]);
            max_count = count[i];
        }
    }

    find_most_common_words(text, max_count, count, words);

    printf("The most common words in the text are:\n");
    for (int i = 0; i < max_count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}