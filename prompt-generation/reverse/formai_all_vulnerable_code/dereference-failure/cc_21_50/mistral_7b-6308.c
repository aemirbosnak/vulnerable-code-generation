//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *str;
    int i, j, len, pos;
    char temp, *new_str;

    if (argc < 2) {
        printf("Please provide a string as an argument.\n");
        return 1;
    }

    str = argv[1];
    len = strlen(str);

    // Invasive string manipulation starts here

    // Reverse the string
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Insert "Hello" before the first occurrence of "World"
    for (i = 0, pos = -1; i < len && pos == -1; i++) {
        if (str[i] == 'W' && str[i+1] == 'o' && str[i+2] == 'r' && str[i+3] == 'l' && str[i+4] == 'd') {
            pos = i;
        }
    }
    if (pos != -1) {
        new_str = (char *) malloc(len + 6);
        for (i = 0; i < pos; i++) {
            new_str[i] = str[i];
        }
        strncat(new_str, "Hello", 5);
        for (i = pos; i < len; i++) {
            new_str[i] = str[i];
        }
        free(str);
        str = new_str;
    }

    // Remove all occurrences of "Hello"
    for (i = 0, pos = 0; i < len; i++) {
        if (str[i] == 'H' && str[i+1] == 'e' && str[i+2] == 'l' && str[i+3] == 'l' && str[i+4] == 'o') {
            for (j = i; j < len; j++) {
                str[j] = str[j+1];
            }
            len--;
            i--;
            pos++;
        }
    }

    // Print the manipulated string
    printf("Manipulated string: %s\n", str);

    // Free memory if allocated
    if (new_str != NULL) {
        free(new_str);
    }

    return 0;
}