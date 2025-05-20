//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
} Dictionary;

void init_dictionary(Dictionary *dict) {
    dict->words = (Word *)malloc(MAX_WORDS * sizeof(Word));
    dict->num_words = 0;
}

void add_word(Dictionary *dict, char *word) {
    int i;
    for (i = 0; i < dict->num_words; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            dict->words[i].count++;
            return;
        }
    }
    if (dict->num_words >= MAX_WORDS) {
        printf("Dictionary is full.\n");
        return;
    }
    strcpy(dict->words[dict->num_words].word, word);
    dict->words[dict->num_words].count = 1;
    dict->num_words++;
}

void print_dictionary(Dictionary *dict) {
    int i;
    for (i = 0; i < dict->num_words; i++) {
        printf("%s %d\n", dict->words[i].word, dict->words[i].count);
    }
}

void translate_sentence(Dictionary *dict, char *sentence) {
    char *token;
    char *saveptr;
    int i;
    token = strtok_r(sentence, " ", &saveptr);
    while (token!= NULL) {
        i = 0;
        while (i < dict->num_words && strcmp(dict->words[i].word, token)!= 0) {
            i++;
        }
        if (i == dict->num_words) {
            printf("%s ", token);
        } else {
            printf("%s ", dict->words[i].word);
        }
        token = strtok_r(NULL, " ", &saveptr);
    }
    printf("\n");
}

int main() {
    Dictionary dict;
    init_dictionary(&dict);
    add_word(&dict, "hello");
    add_word(&dict, "world");
    add_word(&dict, "how");
    add_word(&dict, "are");
    add_word(&dict, "you");
    add_word(&dict, "doing");
    add_word(&dict, "today");
    add_word(&dict, "my");
    add_word(&dict, "name");
    add_word(&dict, "is");
    add_word(&dict, "Dennis");
    add_word(&dict, "Ritchie");
    add_word(&dict, ".");
    add_word(&dict, "I");
    add_word(&dict, "am");
    add_word(&dict, "an");
    add_word(&dict, "AI");
    add_word(&dict, "programmer");
    printf("Dictionary:\n");
    print_dictionary(&dict);
    printf("Sentence: Hello world, how are you doing today? My name is Dennis Ritchie. I am an AI programmer.\n");
    translate_sentence(&dict, "Hello world, how are you doing today? My name is Dennis Ritchie. I am an AI programmer.");
    printf("Dictionary:\n");
    print_dictionary(&dict);
    return 0;
}