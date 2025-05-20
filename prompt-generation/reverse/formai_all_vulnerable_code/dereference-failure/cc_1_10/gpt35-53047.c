//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: futuristic
#include <stdio.h>
#include <string.h>

char* translate(char* sentence);

int main() {

    char sentence[100];
    printf("Enter a sentence in the C Alien Language: ");
    fgets(sentence, 100, stdin);
   
    char* translation = translate(sentence);

    printf("Translation: %s\n", translation);

    return 0;
}

char* translate(char* sentence) {

    char* translation = "";
    int len = strlen(sentence);

    for(int i=0; i<len; i++) {
        char letter = sentence[i];

        switch(letter) {

            case 'C': {
                translation = strcat(translation, "01000011 ");
                break;
            }

            case 'A': {
                translation = strcat(translation, "01000001 ");
                break;
            }

            case 'T': {
                translation = strcat(translation, "01010100 ");
                break;
            }

            case 'G': {
                translation = strcat(translation, "01000111 ");
                break;
            }

            case ' ': {
                translation = strcat(translation, "00100000 ");
                break;
            }

            default: {
                translation = strcat(translation, "Error: Invalid Character ");
                break;
            }
        }
    }

    return translation;
}