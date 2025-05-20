//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *english;
    char *cat;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(FILE *file) {
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english = strtok(line, " ");
        char *cat = strtok(NULL, " ");
        if (english!= NULL && cat!= NULL) {
            words[num_words].english = strdup(english);
            words[num_words].cat = strdup(cat);
            num_words++;
        }
    }
}

int main() {
    load_words(fopen("words.txt", "r"));

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        char *english_word = strtok(input, " ");
        if (english_word!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(english_word, words[i].english) == 0) {
                    printf("%s\n", words[i].cat);
                    break;
                }
            }
            if (i == num_words) {
                printf("Sorry, I do not know that word.\n");
            }
        }
    }

    return 0;
}