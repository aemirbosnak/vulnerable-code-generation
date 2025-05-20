//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define ALIEN_SYMBOLS "ABCDEFGH"
#define HUMAN_LETTERS "abcdefghijklmnopqrstuvwxyz"

char* alien_to_human(char* alien_word){
    // Convert an alien word to human word
    int length = strlen(alien_word);
    char* human_word = malloc(length+1);
    for(int i=0; i<length; i++){
        char alien_letter = alien_word[i];
        int symbol_index = strchr(ALIEN_SYMBOLS, alien_letter) - ALIEN_SYMBOLS;
        if(symbol_index != -1){
            human_word[i] = HUMAN_LETTERS[symbol_index];
        } else{
            human_word[i] = alien_letter;
        }
    }
    human_word[length] = '\0';
    return human_word;
}

char* human_to_alien(char* human_word){
    // Convert a human word to alien word
    int length = strlen(human_word);
    char* alien_word = malloc(length+1);
    for(int i=0; i<length; i++){
        char human_letter = human_word[i];
        int letter_index = strchr(HUMAN_LETTERS, human_letter) - HUMAN_LETTERS;
        if(letter_index != -1){
            alien_word[i] = ALIEN_SYMBOLS[letter_index];
        } else{
            alien_word[i] = human_letter;
        }
    }
    alien_word[length] = '\0';
    return alien_word;
}

int main(int argc, char* argv[]){
    char* input_word = argv[1];
    char* output_word;
    if(strlen(input_word) <= MAX_WORD_LENGTH){
        output_word = human_to_alien(input_word);
        printf("%s -> %s\n", input_word, output_word);
    } else{
        output_word = alien_to_human(input_word);
        printf("%s -> %s\n", input_word, output_word);
    }
    free(output_word);
    return 0;
}