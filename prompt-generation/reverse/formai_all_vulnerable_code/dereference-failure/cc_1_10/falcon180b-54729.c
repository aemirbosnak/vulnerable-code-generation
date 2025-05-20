//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_CONSPIRACY_LENGTH 200

struct word {
    char *word;
    int frequency;
};

struct conspiracy {
    char *conspiracy;
    int length;
};

void generate_random_conspiracy() {
    struct word *words = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;
    char *buffer;
    FILE *file;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    while ((buffer = fgets(buffer, MAX_WORD_LENGTH, file))!= NULL) {
        words[num_words].word = strdup(buffer);
        words[num_words].frequency = 1;
        num_words++;
    }

    fclose(file);

    srand(time(NULL));

    int conspiracy_length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    char *conspiracy = malloc((conspiracy_length + 1) * sizeof(char));

    for (int i = 0; i < conspiracy_length; i++) {
        int word_index = rand() % num_words;
        strncat(conspiracy, words[word_index].word, strlen(words[word_index].word));
        strncat(conspiracy, " ", 1);
    }

    conspiracy[conspiracy_length - 1] = '\0';

    printf("Random conspiracy theory: %s\n", conspiracy);

    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
    }
    free(words);
    free(conspiracy);
}

int main() {
    generate_random_conspiracy();
    return 0;
}