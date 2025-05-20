//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A delightful function to reverse a string
void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

// A whimsical function to capitalize the first letter of each word
void capitalize_words(char *str) {
    int len = strlen(str);
    int in_word = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            in_word = 1;
        } else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            in_word = 0;
        } else if (in_word && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

// A jubilant function to remove duplicate characters from a string
void remove_duplicates(char *str) {
    int len = strlen(str);
    int *count = calloc(256, sizeof(int));
    int i, j;
    for (i = 0; i < len; i++) {
        count[str[i]]++;
    }
    j = 0;
    for (i = 0; i < len; i++) {
        if (count[str[i]] > 1) {
            continue;
        } else {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    free(count);
}

int main() {
    // Let's create a beautiful string to play with!
    char str[] = "TeXt PrOcEsSiNg iS fuN!";

    printf("Original string: %s\n", str);

    // Time to reverse this string like a magician's trick!
    reverse(str);
    printf("Reversed string: %s\n", str);

    // Now let's capitalize the first letter of each word like a proper noun!
    capitalize_words(str);
    printf("Capitalized string: %s\n", str);

    // Let's tidy up and remove those duplicate characters like a diligent housekeeper!
    remove_duplicates(str);
    printf("String with duplicates removed: %s\n", str);

    return 0;
}