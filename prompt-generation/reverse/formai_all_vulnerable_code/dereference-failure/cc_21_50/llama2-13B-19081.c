//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MIN_LENGTH 10

int main() {
    char *str;
    int length;
    int i, j;
    int vowels = 0;
    int consonants = 0;
    int special_chars = 0;

    // Get the user input string
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Trim the string
    length = strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            str[i] = '\0';
        }
    }

    // Count the number of vowels
    for (i = 0; i < length; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowels++;
        }
    }

    // Count the number of consonants
    for (i = 0; i < length; i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            consonants++;
        }
    }

    // Count the number of special characters
    for (i = 0; i < length; i++) {
        if (str[i] == '!' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == ' ' || str[i] == '\t') {
            special_chars++;
        }
    }

    // Print the analysis results
    printf("String Analysis:\n");
    printf("Length: %d\n", length);
    printf("Vowels: %d (%.2f%%)\n", vowels, (float)vowels / (float)length * 100);
    printf("Consonants: %d (%.2f%%)\n", consonants, (float)consonants / (float)length * 100);
    printf("Special Characters: %d (%.2f%%)\n", special_chars, (float)special_chars / (float)length * 100);

    return 0;
}