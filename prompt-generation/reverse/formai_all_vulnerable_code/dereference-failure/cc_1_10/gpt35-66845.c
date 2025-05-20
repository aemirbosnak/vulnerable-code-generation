//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This is an introspective style C alien language translator program that translates an alien language into English. This program is capable of translating any short sentence or word from alien language into English. It works on the grammatical rules of the alien language and translates it accordingly.

The program is written in C and uses dynamic memory allocation to manage strings. It first takes the input from the user and then breaks it down into words. It then applies different grammatical rules to each word to generate the English translation. Finally, it displays the translated text on the console.

*/

// function to check whether a given character is a vowel or not
int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// function to translate a given word from alien language to English
char* translate_word(char* word) {
    int len = strlen(word);

    // check if the word ends with "zor"
    if (len >= 3 && strcmp(word + len - 3, "zor") == 0) {
        // remove "zor" and add "s" at the end
        word[len - 3] = '\0';
        strcat(word, "s");
        return word;
    }

    // check if the word starts with a consonant followed by a vowel
    if (len >= 2 && !is_vowel(word[0]) && is_vowel(word[1])) {
        // move the first consonant to the end and add "ay" at the end
        char* translated_word = (char*) malloc((len + 2) * sizeof(char));
        strcpy(translated_word, word + 1);
        strncat(translated_word, word, 1);
        strcat(translated_word, "ay");
        return translated_word;
    }

    // check if the word starts with two consonants followed by a vowel
    if (len >= 3 && !is_vowel(word[0]) && !is_vowel(word[1]) && is_vowel(word[2])) {
        // move the first two consonants to the end and add "ay" at the end
        char* translated_word = (char*) malloc((len + 2) * sizeof(char));
        strcpy(translated_word, word + 2);
        strncat(translated_word, word, 2);
        strcat(translated_word, "ay");
        return translated_word;
    }

    // if none of the above rules apply, return the original word
    return word;
}

// function to translate a given sentence from alien language to English
char* translate_sentence(char* sentence) {
    int len = strlen(sentence);

    // break down the sentence into words
    char* words[100];
    int word_count = 0;
    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            sentence[i] = '\0';
            words[word_count++] = sentence;
            sentence = sentence + i + 1;
        }
    }
    words[word_count++] = sentence;

    // translate each word and concatenate them to form the translated sentence
    char* translated_sentence = (char*) malloc(1000 * sizeof(char));
    strcpy(translated_sentence, "");
    for (int i = 0; i < word_count; i++) {
        char* translated_word = translate_word(words[i]);
        strcat(translated_sentence, translated_word);
        if (i != word_count - 1) {
            strcat(translated_sentence, " ");
        }
        free(translated_word);
    }

    return translated_sentence;
}

// main function
int main() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("----------------------------------------\n\n");

    // get input from user
    char* sentence = (char*) malloc(1000 * sizeof(char));
    printf("Please enter your sentence in alien language: ");
    gets(sentence);

    // translate the sentence and display the translation
    char* translated_sentence = translate_sentence(sentence);
    printf("\nTranslated sentence: %s\n", translated_sentence);

    // free memory
    free(sentence);
    free(translated_sentence);

    return 0;
}