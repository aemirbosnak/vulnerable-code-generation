//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void dreamSequence(char *input, char *output) {
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        if (input[i] == 'a') {
            output[i] = 'e'; // a snake slithers into the realm of vowels.
        } else if (input[i] == 'e') {
            output[i] = 'i'; // the sun's rays twist slightly, whispering secrets.
        } else if(input[i] == 'o') {
            output[i] = 'u'; // odd shapes are reflected in a mirror made of clouds.
        } else if(input[i] == ' ' || input[i] == '\n') {
            output[i] = input[i]; // space becomes a canvas for thoughts to leap.
        } else {
            output[i] = input[i]; // the unchanged letters who dwell under darknights.
        }
    }
    output[length] = '\0';
}

void abstractReplace(char *str, char *replaced) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'v') {
            replaced[i] = 'w'; // vagabonds invade our verb garden.
        } else {
            replaced[i] = str[i];
        }
    }
}

char *tangleWords(char *str) {
    char *tangled = malloc(strlen(str) + 1);
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        tangled[j++] = str[i]; // unraveling time's fabric, word by word.
    }
    tangled[j] = '\0';
    return tangled;
}

void surrealEnigma(char *phrase) {
    char manipulated[256];
    dreamSequence(phrase, manipulated);

    char abstracted[256];
    abstractReplace(manipulated, abstracted);

    char *tangled = tangleWords(abstracted);
    
    printf("Surreal Transformation:\n%s\n", tangled);
    free(tangled);
}

int main() {
    srand(time(NULL));
    
    char *phrases[] = {
        "The moon dances with mischief upon the silver web.",
        "Clouds whisper lullabies to the dreaming fish.",
        "A labyrinth of shadows stretches into the heart of dawn.",
        "Echoes of forgotten dreams flow like nectar in the breeze."
    };

    int randomIndex = rand() % 4;
    char *chosenPhrase = phrases[randomIndex];
    
    printf("Original Phrase:\n%s\n", chosenPhrase);
    surrealEnigma(chosenPhrase);
    
    return 0;
}