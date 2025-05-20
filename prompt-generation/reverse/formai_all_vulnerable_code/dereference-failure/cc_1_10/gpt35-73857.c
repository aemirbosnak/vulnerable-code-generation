//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256
#define MAX_HEIGHT 17

/*
ASCII Art Generator in Futuristic Style
By: ChatbotAI
*/

char ascii_chars[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '+', ',', '-', '.', '/', 
                       '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', 
                       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
                       'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 
                       'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
                       'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~' };

char *convert_to_ascii_art(char input[]) {
    char *art = NULL;
    int input_len = strlen(input);
    if (input_len > MAX_INPUT) return art;

    art = calloc(MAX_HEIGHT * (input_len + 1), sizeof(char));
    int i, j, k;
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < input_len; j++) {
            int ascii_char_index = input[j] % 90;
            if (ascii_char_index < 0) ascii_char_index += 90;
            if (ascii_char_index < 9) ascii_char_index = 9;
            if (ascii_char_index > 80) ascii_char_index = 80;
            for (k = ascii_char_index - 9; k < ascii_char_index; k++) {
                art[i * input_len + j] = ascii_chars[k];
                if (k == ascii_char_index - 1) art[i * input_len + j] = ' ';
            }
        }
    }
    return art;
}

int main() {
    char input[MAX_INPUT];
    printf("Enter text to convert into ASCII art: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;

    char *art = convert_to_ascii_art(input);
    if (art == NULL) {
        printf("Input too long.");
        return 1;
    }

    printf("%s\n", art);
    free(art);
    return 0;
}