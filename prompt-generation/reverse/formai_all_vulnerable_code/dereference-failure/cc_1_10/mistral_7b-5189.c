//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define WORDS_COUNT 10
#define MIN_SENTENCE_LENGTH 20
#define MAX_SENTENCE_LENGTH 50

const char *conspiracy_words[WORDS_COUNT] = {
        "illuminati",
        "reptilian",
        "alien",
        "freemason",
        "new_world_order",
        "government_conspiracy",
        "jfk_assassination",
        "9_11_conspiracy",
        "lizard_people",
        "mind_control"
};

void generate_sentence(char *sentence, int length) {
    for (int i = 0; i < length; i++) {
        sentence[i] = conspiracy_words[rand() % WORDS_COUNT][rand() % (strlen(conspiracy_words[rand() % WORDS_COUNT]))];
        if (i > 0 && i < length - 1) {
            sentence[i] += ' ';
        }
    }
    sentence[length] = '\0';
}

int main() {
    srand(time(NULL));
    char theories[MAX_THEORIES][MAX_SENTENCE_LENGTH];
    int theories_count = 0;

    while (theories_count < MAX_THEORIES) {
        char sentence[MAX_SENTENCE_LENGTH];
        int length = rand() % (MAX_SENTENCE_LENGTH - MIN_SENTENCE_LENGTH) + MIN_SENTENCE_LENGTH;
        generate_sentence(sentence, length);
        strcpy(theories[theories_count], sentence);
        theories_count++;
    }

    for (int i = 0; i < MAX_THEORIES; i++) {
        printf("%d. %s\n", i + 1, theories[i]);
    }

    return 0;
}