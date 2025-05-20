//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Palindrome {
    int length;
    char *data;
} Palindrome;

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

Palindrome read_word(FILE *file) {
    Palindrome palindrome;
    char ch;
    int length = 0;

    while ((ch = fgetc(file)) != EOF && isalpha(ch)) {
        palindrome.data[length] = tolower(ch);
        length++;
        palindrome.data = (char *) realloc(palindrome.data, sizeof(char) * (length + 1));
    }

    palindrome.data[length] = '\0';
    palindrome.length = length;

    return palindrome;
}

int is_palindrome(const Palindrome palindrome) {
    int start = 0;
    int end = palindrome.length - 1;

    while (start < end) {
        if (palindrome.data[start] != palindrome.data[end]) {
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

int main() {
    FILE *file = fopen("words.txt", "r");
    Palindrome word;

    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fscanf(file, "%*s") != EOF) {
        word = read_word(file);
        if (is_palindrome(word)) {
            printf("%s is a palindrome\n", word.data);
        } else {
            free(word.data);
        }
    }

    fclose(file);
    return 0;
}