//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GRATITUDE_STRING "Gratitude is the memory of the heart"

void grateful_string_manipulation(char *str) {
    char *temp;
    int i, j, k;

    // Reverse the string
    for (i = 0; i < strlen(str); i++) {
        temp = str + i;
        for (j = 0; j < strlen(str); j++) {
            if (j < i) {
                str[j] = str[j + 1];
            } else {
                str[j] = temp[j - i];
            }
        }
    }

    // Capitalize each word
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            for (j = 0; j < strlen(str); j++) {
                if (str[j] == ' ' && isalpha(str[j - 1])) {
                    str[j] = toupper(str[j]);
                }
            }
        }
    }

    // Add a space between each word
    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            for (j = i + 1; j < strlen(str); j++) {
                if (isalpha(str[j]) && str[j - 1] != ' ') {
                    str[j] = ' ';
                }
            }
        }
    }

    // Remove all duplicates
    for (i = 0; i < strlen(str); i++) {
        for (j = i + 1; j < strlen(str); j++) {
            if (str[i] == str[j]) {
                str[j] = '\0';
            }
        }
    }

    // Print the modified string
    printf("Gratitude is the memory of the heart\n");
    for (i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }
}

int main() {
    char str[100];

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // Modify the string as desired
    grateful_string_manipulation(str);

    return 0;
}