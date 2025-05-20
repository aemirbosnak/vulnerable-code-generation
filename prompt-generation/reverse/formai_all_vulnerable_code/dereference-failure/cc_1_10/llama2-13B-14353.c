//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define CHAR_SET "abcdefghijklmnopqrstuvwxyz"

int main() {
    int len = 0;
    char *str = NULL;
    char *challenge = "This is a challenge for you!";

    // Create a random string
    srand(time(NULL));
    for (int i = 0; i < MAX_LENGTH; i++) {
        char random_char = CHAR_SET[rand() % strlen(CHAR_SET)];
        str = realloc(str, len + 1);
        str[len] = random_char;
        len++;
    }

    // Encrypt the string
    for (int i = 0; i < len; i++) {
        char current_char = str[i];
        char next_char = current_char;
        if (current_char == 'a') {
            next_char = 'b';
        } else if (current_char == 'b') {
            next_char = 'a';
        }
        str[i] = next_char;
    }

    // Decrypt the string (or so it seems)
    for (int i = 0; i < len; i++) {
        char current_char = str[i];
        char next_char = current_char;
        if (current_char == 'a') {
            next_char = 'z';
        } else if (current_char == 'z') {
            next_char = 'a';
        }
        str[i] = next_char;
    }

    // Print the final string
    printf("The challenge is: %s\n", str);

    return 0;
}