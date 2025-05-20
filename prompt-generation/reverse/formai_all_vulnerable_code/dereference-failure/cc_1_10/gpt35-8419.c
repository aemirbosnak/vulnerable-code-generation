//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to translate a word from Alien language to English
char* translate(char* word) {
    char* translation;
    if (strcmp(word, "xoob") == 0) {
        translation = "hello";
    } else if (strcmp(word, "glip") == 0) {
        translation = "goodbye";
    } else if (strcmp(word, "skree") == 0) {
        translation = "thank you";
    } else if (strcmp(word, "boor") == 0) {
        translation = "sorry";
    } else {
        translation = "unknown";
    }
    return translation;
}

// Function to translate a sentence from Alien language to English
void translateSentence(char* sentence) {
    char* word;
    char* translation;
    int i = 0;
    while (sentence[i] != '\0') {
        int j = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            word[j] = sentence[i];
            i++;
            j++;
        }
        word[j] = '\0';
        translation = translate(word);
        printf("%s ", translation);
        if (sentence[i] != '\0') {
            i++;
        }
    }
    printf("\n");
}

// Main function
int main() {
    char sentence[100];
    printf("Enter a sentence in Alien language: ");
    fgets(sentence, 100, stdin);
    printf("Translated sentence: ");
    translateSentence(sentence);
    return 0;
}