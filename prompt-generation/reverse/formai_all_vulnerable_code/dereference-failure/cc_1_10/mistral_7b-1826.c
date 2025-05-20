//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function to reverse a string in-place
void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to generate a random index for string manipulation
int random_index(int len) {
    return rand() % len;
}

int main() {
    char *str = "The quick brown fox jumps over the lazy dog.";
    int len = strlen(str);

    printf("Original String: %s\n", str);

    // Shuffle the string characters
    for (int i = 0; i < len * 3; i++) {
        int index = random_index(len);
        char temp = str[index];
        str[index] = str[rand() % len];
        str[rand() % len] = temp;
    }

    printf("Shuffled String: %s\n", str);

    // Reverse the string
    reverse_string(str);

    printf("Reversed String: %s\n", str);

    // Capitalize the first letter of each word
    for (int i = 0; i < len; i++) {
        if (isspace(str[i]) || str[i] == '\0') {
            if (i > 0) {
                str[i - 1] = toupper(str[i - 1]);
            }
            continue;
        }
        str[i] = toupper(str[i]);
    }

    printf("Capitalized String: %s\n", str);

    // Allocate memory for a new string and copy the capitalized string
    char *new_str = malloc(len + 1);
    strcpy(new_str, str);

    // Add an exclamation mark at the end
    new_str[len] = '!';

    printf("Exclamated String: %s\n", new_str);

    free(new_str);

    return 0;
}