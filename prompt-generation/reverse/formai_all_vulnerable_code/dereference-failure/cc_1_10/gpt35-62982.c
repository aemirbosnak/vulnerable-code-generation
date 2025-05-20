//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_MORSE_LENGTH 5000

char* morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","/"};
char* alphabet[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};

void toMorse(char*, char*);
void toText(char*, char*);

int main() {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_MORSE_LENGTH] = "";

    printf("Enter text to convert to morse code:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    toMorse(input, output);
    printf("Morse code:\n");
    printf("%s\n", output);

    char textOutput[MAX_INPUT_LENGTH] = "";
    toText(output, textOutput);
    printf("Converted back to text:\n");
    printf("%s\n", textOutput);
}

//Converts input text to morse code
void toMorse(char* input, char* output) {
    int i = 0;
    while(input[i] != '\0') {
        char c = toupper(input[i]);

        //Look up the morse code for the corresponding character
        for(int j = 0; j < 27; j++) {
            if(c == alphabet[j][0]) {
                strcat(output, morseCode[j]);
                strcat(output, " ");
                break;
            }
        }
        i++;
    }
}

//Convert morse code to text
void toText(char* input, char* output) {
    char* code;
    int i = 0;
    while(input[i] != '\0') {
        if(input[i] == ' ') {
            int j = 0;
            //Loop through the morse code to look up the corresponding character
            while(strcmp(code, morseCode[j]) != 0) {
                j++;
                if(j > 27) {
                    sprintf(output, "%s?", output);
                    code = "";
                    break;
                }
            }
            sprintf(output, "%s%s", output, alphabet[j]);
            code = "";
        }
        else {
            sprintf(code, "%s%c", code, input[i]);
        }
        i++;
    }
    //Process the final code
    if(code[0] != '\0') {
        int j = 0;
        while(strcmp(code, morseCode[j]) != 0) {
            j++;
            if(j > 27) {
                sprintf(output, "%s?", output);
                code = "";
                break;
            }
        }
        sprintf(output, "%s%s", output, alphabet[j]);
    }
}