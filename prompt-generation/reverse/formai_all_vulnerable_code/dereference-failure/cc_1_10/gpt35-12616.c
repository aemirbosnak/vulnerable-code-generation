//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *brave[] = {
    "    _____     ________  _______   _     _   _____   _____    _____   _       _   _____   _____   _____   ",
    "   / ____|   |  _____| |__   __| | \\   / | |_   _| |  __ \\  |  __ \\ | |     | | |  __ \\ |_   _| |_   _|  ",
    "  | |  __    | |            | |    | \\_/ |   | |   | |__) | | |  | || |     | | | |__) |  | |     | |    ",
    "  | | |_ |   | |            | |    |  _  |   | |   |  _  /  | |  | || |     | | |  _  /   | |     | |    ",
    "  | |__| |   | |____        | |    | | \\ |  _| |_  | | \\ \\  | |__| || |____ | | | | \\ \\  _| |_    | |    ",
    "   \\_____|   |______|       |_|    |_|  \\_\\|_____| |_|  \\_\\ |_____/ |______||_| |_|  \\_\\|_____|   |_|    ",
    "                                                                                                          ",
    "                                                                                                          "
};

/**
 * Convert Text to ASCII Art
**/
char* text_to_ascii(char* text) {
    int len = strlen(text);
    char* output = (char*) malloc(sizeof(char) * 708 * len);
    
    // loop through each line of the brave ascii art
    for (int i = 0; i < 7; i++) {
        // loop through each letter of the input text
        for (int j = 0; j < len; j++) {
            // check if the current character is a capital letter
            if (text[j] >= 'A' && text[j] <= 'Z') {
                // convert to lowercase
                char c = text[j] + 32;
                // calculate the index of the corresponding ascii art letter
                int index = (int) c - 97;
                // add the ascii art letter to the output
                strcat(output, brave[i] + (5 * index));
            } else if (text[j] >= 'a' && text[j] <= 'z') {
                // calculate the index of the corresponding ascii art letter
                int index = (int) text[j] - 97;
                // add the ascii art letter to the output
                strcat(output, brave[i] + (5 * index));
            } else {
                // add a space to the output
                strcat(output, "     ");
            }
        }
        // add a newline character to the output
        strcat(output, "\n");
    }
    return output;
}

int main() {
    printf("Enter text: ");
    char text[256];
    fgets(text, 256, stdin);
    // remove newline character from input
    text[strcspn(text, "\n")] = 0;
    char* output = text_to_ascii(text);
    printf("%s", output);
    free(output);
    return 0;
}