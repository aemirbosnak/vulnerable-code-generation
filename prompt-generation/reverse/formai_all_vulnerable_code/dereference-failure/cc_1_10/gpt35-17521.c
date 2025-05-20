//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

int isConsonant(char c) {
    return !isVowel(c) && isalpha(c);
}

int isSpecialChar(char c) {
    return (!isalpha(c) && !isdigit(c));
}

int checkSpelling(char word[]) {
    int errors = 0;
    int len = strlen(word);
    char prev = '\0';

    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (isSpecialChar(c)) {
            printf("Error: '%c' is not an alphanumeric character\n", c);
            errors++;
        } else if (isConsonant(c) && isConsonant(prev)) {
            printf("Error: Double consonant at position %d\n", i);
            errors++;
        } else if (isVowel(c) && isVowel(prev)) {
            printf("Error: Double vowel at position %d\n", i);
            errors++;
        }
        prev = c;
    }

    if (isVowel(prev)) {
        printf("Error: Word ends with vowel\n");
        errors++;
    }

    return errors;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s word1 [word2] [word3] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char* word = argv[i];

        printf("Checking spelling of '%s'...\n", word);

        int errors = checkSpelling(word);

        if (errors > 0) {
            printf("Found %d error%s in '%s'\n", errors, errors == 1 ? "" : "s", word);
        } else {
            printf("No errors found in '%s'\n", word);
        }
    }

    return 0;
}