//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables for two lovers
    char* lover1 = "John";
    char* lover2 = "Jane";

    // Declare variables for their love letters
    char* letter1 = "My dearest Jane,\nI have been thinking of you all day.\nYour smile lights up my world,\nAnd your laughter makes my heart sing.\nI want to spend every moment with you,\nTo hold your hand and share our dreams.\nPlease be mine forever,\nAnd let our love shine bright like the stars.\nLove,\nJohn";
    char* letter2 = "My dearest John,\nYour words have touched my heart,\nAnd I feel the same way about you.\nYour kindness and compassion,\nAnd your passion for life,\nHave captured my soul.\nI want to be with you,\nTo share our adventures and joys,\nAnd to build a life together.\nPlease be my forever love,\nAnd let our love grow stronger with each day.\nYours always,\nJane";

    // Declare variables for their love letters' lengths
    int len1 = 0;
    int len2 = 0;

    // Find the length of the first love letter
    while (*lover1) {
        len1++;
        lover1++;
    }

    // Find the length of the second love letter
    while (*lover2) {
        len2++;
        lover2++;
    }

    // Print the lengths of the love letters
    printf("The length of Jane's love letter is %d characters.\n", len2);
    printf("The length of John's love letter is %d characters.\n", len1);

    // Declare variables for their love letter strings
    char* letter1_str = malloc(len1 * sizeof(char));
    char* letter2_str = malloc(len2 * sizeof(char));

    // Copy the love letters into the strings
    for (int i = 0; i < len1; i++) {
        letter1_str[i] = lover1[i];
    }
    for (int i = 0; i < len2; i++) {
        letter2_str[i] = lover2[i];
    }

    // Print the love letters
    printf("Jane's love letter:\n%s\n", letter2_str);
    printf("John's love letter:\n%s\n", letter1_str);

    // Free the memory for the love letter strings
    free(letter1_str);
    free(letter2_str);

    return 0;
}