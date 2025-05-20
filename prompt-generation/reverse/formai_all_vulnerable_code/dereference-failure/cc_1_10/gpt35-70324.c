//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {

    printf("Thank you for using this Morse code converter!\n");

    const char *alphabet[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    const char *numbers[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    char text[100];
    printf("Enter the text you wish to convert to Morse code: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0;

    char morse[100];
    memset(morse, 0, sizeof morse);

    int len = strlen(text);
    for(int i = 0; i < len; i++) {
        char current = text[i];
        // For upper case alphabets
        if(current >= 65 && current <= 90) {
            strcat(morse, alphabet[current - 65]);
            strcat(morse, " ");
        }
        // For lower case alphabets
        else if(current >= 97 && current <= 122) {
            strcat(morse, alphabet[current - 97]);
            strcat(morse, " ");
        }
        // For numbers
        else if(current >= 48 && current <= 57) {
            strcat(morse, numbers[current - 48]);
            strcat(morse, " ");
        }
        // For spaces
        else if(current == 32) {
            strcat(morse, "/ ");
        }
        // For other characters
        else {
            strcat(morse, current);
            strcat(morse, " ");
        }
    }

    printf("The Morse code for your text is:\n%s\n", morse);

    printf("Thank you for using this Morse code converter, come back soon!\n");

    return 0;
}