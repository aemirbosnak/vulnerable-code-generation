//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_THEORIES 1000

char *words[MAX_WORDS] = {
    "government",
    "aliens",
    "illuminati",
    "chemtrails",
    "9/11",
    "moon landing",
    "JFK assassination",
    "lizard people",
    "flat earth",
    "vaccines",
    "Bigfoot",
    "NWO",
    "FEMA camps",
    "crisis actors",
    "false flag",
    "deep state",
    "MK Ultra",
    "sandy hook",
    "climate change hoax",
    "Bilderberg group",
    "bohemian grove",
    "reptilians",
    "Freemasons",
    "trump russia collusion",
    "pizzagate",
    "qanon",
    "5G",
    "Bill Gates microchip",
    "COVID-19 hoax"
};

char *theories[MAX_THEORIES];
int num_theories = 0;

void generate_theory(int n) {
    char *theory = malloc(n * sizeof(char));
    int i = 0;
    while (i < n) {
        int word_index = rand() % MAX_WORDS;
        strncat(theory, words[word_index], strlen(words[word_index]));
        i += strlen(words[word_index]) + 1; // +1 for space
        if (i >= n - 10) {
            strncat(theory, " ", 1);
            i++;
        }
    }
    theories[num_theories++] = theory;
}

int main() {
    srand(time(NULL));
    int num_theories_to_generate = 10;
    for (int i = 0; i < num_theories_to_generate; i++) {
        generate_theory(rand() % 50 + 10); // random theory length between 10 and 59 words
    }

    for (int i = 0; i < num_theories; i++) {
        printf("%s\n", theories[i]);
    }

    return 0;
}