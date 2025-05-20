//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: medieval
/* This program translates English sentences to C Cat Language */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *translate(char *sentence) {
    char *translated = malloc(strlen(sentence) + 1);
    if (translated == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    int i = 0;
    while (sentence[i]!= '\0') {
        if (islower(sentence[i])) {
            if (i == 0) {
                translated[i] = toupper(sentence[i]);
            } else {
                if (isupper(sentence[i - 1])) {
                    translated[i] = toupper(sentence[i]);
                } else {
                    translated[i] = tolower(sentence[i]);
                }
            }
        } else if (isupper(sentence[i])) {
            translated[i] = toupper(sentence[i]);
        } else {
            translated[i] = sentence[i];
        }
        i++;
    }
    translated[i] = '\0';
    return translated;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <sentence>\n", argv[0]);
        return 1;
    }
    char *sentence = argv[1];
    char *translated = translate(sentence);
    if (translated!= NULL) {
        printf("Translated sentence: %s\n", translated);
        free(translated);
    } else {
        fprintf(stderr, "Translation failed\n");
    }
    return 0;
}