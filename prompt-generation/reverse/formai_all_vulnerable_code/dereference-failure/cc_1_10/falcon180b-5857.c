//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 10
#define NUM_WORDS 100
#define NUM_SENTENCES 10

char words[NUM_WORDS][MAX_WORD_LENGTH];
char sentences[NUM_SENTENCES][100];
int num_words = 0;
int num_sentences = 0;

void generate_random_string(char* str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
}

void generate_random_sentence() {
    char str[100];
    generate_random_string(str, rand() % 10 + 5);
    strcat(str, " ");
    strcat(str, "the ");
    strcat(str, "quick ");
    strcat(str, "brown ");
    strcat(str, "fox ");
    strcat(str, "jumps ");
    strcat(str, "over ");
    strcat(str, "the ");
    strcat(str, "lazy ");
    strcat(str, "dog ");
    strcpy(sentences[num_sentences], str);
    num_sentences++;
}

void generate_random_words() {
    for (int i = 0; i < NUM_WORDS; i++) {
        char str[MAX_WORD_LENGTH];
        generate_random_string(str, rand() % MAX_WORD_LENGTH + 1);
        strcpy(words[i], str);
    }
    num_words = NUM_WORDS;
}

void translate_sentence(char* sentence) {
    int i = 0;
    while (i < strlen(sentence)) {
        if (isalpha(sentence[i])) {
            int j = 0;
            while (j < num_words) {
                if (isalpha(words[j][0]) && tolower(sentence[i]) == tolower(words[j][0])) {
                    strcpy(&sentence[i], words[j]);
                    i += strlen(words[j]) - 1;
                    break;
                }
                j++;
            }
        }
        i++;
    }
}

int main() {
    srand(time(NULL));
    generate_random_words();
    generate_random_sentence();

    printf("Original sentence: %s\n", sentences[0]);
    printf("Translated sentence: ");
    translate_sentence(sentences[0]);
    printf("\n");

    return 0;
}