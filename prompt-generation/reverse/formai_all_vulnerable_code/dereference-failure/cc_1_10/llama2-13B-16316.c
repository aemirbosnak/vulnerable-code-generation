//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: surprised
// Oh my gosh, I can't believe it! A C string manipulation program that's actually fun to use! 😱

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAGIC_WORD "surprised"

// Function to generate a random string
char *generate_random_string(int len) {
    static const char alph[] = "abcdefghijklmnopqrstuvwxyz";
    char *str = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        str[i] = alph[rand() % (sizeof(alph) - 1)];
    }
    return str;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int len = strlen(str);
    char *rev = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        rev[i] = str[len - i - 1];
    }
    return rev;
}

// Function to check if a string contains a magic word
int contains_magic_word(char *str) {
    return strstr(str, MAGIC_WORD) != NULL;
}

int main() {
    // Generate a random string
    char *str = generate_random_string(MAX_STR_LEN);
    printf("The random string is: %s\n", str);

    // Reverse the string
    char *rev_str = reverse_string(str);
    printf("The reversed string is: %s\n", rev_str);

    // Check if the string contains the magic word
    if (contains_magic_word(str)) {
        printf("Oh my gosh, I can't believe it! The string contains the magic word %s!\n", MAGIC_WORD);
    } else {
        printf("Wow, that's surprising! The string doesn't contain the magic word %s.\n", MAGIC_WORD);
    }

    // Free the memory
    free(str);
    free(rev_str);

    return 0;
}