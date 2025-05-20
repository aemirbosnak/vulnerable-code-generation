//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#define MAX_CHARS 1000

/* Function to check if two strings are equal */
int isEqual(char *str1, char *str2) {
    int i = 0;
    while(str1[i] != '\0' || str2[i] != '\0') {
        if(str1[i] != str2[i])
            return 0;
        i++;
    }
    return 1;
}

/* Function to translate a message in the Alien language */
char* translate(char *message) {
    char dictionary[][20] = {"kli", "env", "pin", "sto", "dir", "wab", "zes", "fyu", "tam"};
    char *translatedMessage = (char*) malloc(MAX_CHARS * sizeof(char));
    char temp[MAX_CHARS];
    int i, j, k, m, wordLength, foundWord;
    i = j = k = 0;
    while(message[i] != '\0') {
        if(message[i] == ' ') {
            translatedMessage[j++] = ' ';
            i++;
            continue;
        }
        m = i;
        foundWord = 0;
        while(message[m] != '\0' && message[m] != ' ') {
            temp[k++] = message[m++];
        }
        temp[k] = '\0';
        k = 0;
        wordLength = strlen(temp);
        for(m = 0; m < 9; m++) {
            if(isEqual(temp, dictionary[m])) {
                foundWord = 1;
                strcat(translatedMessage, temp);
                break;
            }
        }
        if(!foundWord) {
            strcat(translatedMessage, temp);
        }
        i += wordLength;
    }
    return translatedMessage;
}

int main() {
    char message[MAX_CHARS];
    printf("Enter a message in Alien language: ");
    fgets(message, MAX_CHARS, stdin);
    printf("Translated message: %s\n", translate(message));
    return 0;
}