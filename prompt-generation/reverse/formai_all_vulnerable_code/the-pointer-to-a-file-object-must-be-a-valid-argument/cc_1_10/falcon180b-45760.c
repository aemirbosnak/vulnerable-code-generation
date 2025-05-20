//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
};

int num_words = 0;
struct word words[MAX_WORDS];

void add_word(char* english, char* cat) {
    strcpy(words[num_words].english, english);
    strcpy(words[num_words].cat, cat);
    num_words++;
}

void load_dictionary() {
    FILE* dict_file = fopen("dictionary.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), dict_file)) {
        char* english = strtok(line, " ");
        char* cat = strtok(NULL, " ");
        add_word(english, cat);
    }
    fclose(dict_file);
}

void translate_sentence(char* sentence) {
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    load_dictionary();
    char sentence[1000];
    printf("Enter a sentence to translate: ");
    fgets(sentence, sizeof(sentence), stdin);
    translate_sentence(sentence);
    return 0;
}