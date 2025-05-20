//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Constant variables for Morse code conversion
const char *morseCode[36] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };
const char *englishAlphabets[36] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
const int morseCodeLength = 5;

// Function to convert English Text to Morse Code
void englishToMorseCodeConversion(char *englishText) {
    int englishStringLength = strlen(englishText), index;
    char *morseString = (char*) malloc(morseCodeLength * englishStringLength * sizeof(char));
    
    if(morseString == NULL) {
        printf("Memory Allocation failed");
        exit(0);
    }
    
    for(int i=0; i<englishStringLength; i++) {
        if(englishText[i] == ' ')
            strcat(morseString, "      ");
        else {
            index = englishText[i] - 65;
            strcat(morseString, morseCode[index]);
            strcat(morseString, " ");
        }
    }
    printf("\nMorse Code: %s", morseString);
    free(morseString);
}

// Function to convert Morse Code to English Text
void morseCodeToEnglishConversion(char *morseCodeString) {
    int morseStringLength = strlen(morseCodeString), index = 0, morseCodeStringLength = morseCodeLength;
    char *englishAlphabet = (char*) malloc(morseStringLength * sizeof(char));
    
    if(englishAlphabet == NULL) {
        printf("Memory Allocation failed");
        exit(0);
    }
    
    for(int i=0; i<morseStringLength; i+=6) {
        if(morseCodeString[i+5] == ' ')
            morseCodeStringLength = 5;
        else
            morseCodeStringLength = morseCodeLength;
 
        for(int j=0; j<36; j++) {
            if(!strncmp(morseCode[j], (morseCodeString+i), morseCodeStringLength)) {
                englishAlphabet[index++] = englishAlphabets[j][0];
                break;
            }    
        }
    }
    englishAlphabet[index] = '\0';
    printf("\nConverted English Text: %s\n", englishAlphabet);
    free(englishAlphabet);
}

// Function to check whether the given Morse Code string is valid or not
int isMorseCodeValid(char *morseCodeString) {
    int morseStringLength = strlen(morseCodeString), count = 0;
    
    for(int i=0; i<morseStringLength; i++) {
        if(morseCodeString[i] == '-' || morseCodeString[i] == '.') {
            count++;
        } else if(morseCodeString[i] == ' ') {
            if(count == 0) 
                return 0;
            count = 0;    
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int choice;
    char inputString[100];
    printf("###############################################################################################");
    printf("######################## PARANOID MORSE CODE CONVERSION PROGRAM ###########################");
    printf("###############################################################################################\n\n");
    
    while(1) {
        printf("1. English Text to Morse Code Conversion\n");
        printf("2. Morse Code to English Text Conversion\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter English Text: ");
                getchar();
                fgets(inputString, 100, stdin);
                englishToMorseCodeConversion(inputString);
                break;
            case 2:
                printf("\nEnter Morse Code: ");
                getchar();
                fgets(inputString, 100, stdin);
                if(isMorseCodeValid(inputString))
                    morseCodeToEnglishConversion(inputString);
                else
                    printf("\nINVALID MORSE CODE\n");
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
        printf("\n###############################################################################################\n\n");    
    }
    return 0;
}