//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to reverse a string
char *reverse(char *str) {
    int len = strlen(str);
    char *reversed = malloc(len + 1);
    int i, j;
    for (i = 0, j = len - 1; i < len; i++, j--) {
        reversed[i] = str[j];
    }
    reversed[len] = '\0';
    return reversed;
}

// A function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// A function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
    int len = strlen(str);
    int i, j, k, max_len = 0, start = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (is_palindrome(str + i) && j - i + 1 > max_len) {
                max_len = j - i + 1;
                start = i;
            }
        }
    }
    char *longest = malloc(max_len + 1);
    strncpy(longest, str + start, max_len);
    longest[max_len] = '\0';
    return longest;
}

// A function to find the shortest palindrome that can be made by adding characters to the beginning of a string
char *shortest_palindrome(char *str) {
    int len = strlen(str);
    int i, j, k, min_len = len, start = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (is_palindrome(str + i) && i + j - 1 < min_len) {
                min_len = i + j - 1;
                start = i;
            }
        }
    }
    char *shortest = malloc(min_len + 1);
    strncpy(shortest, str + start, min_len);
    shortest[min_len] = '\0';
    for (i = start - 1; i >= 0; i--) {
        shortest[min_len++] = str[i];
    }
    return shortest;
}

int main() {
    char *str = "Abracadabra";

    printf("The original string: %s\n", str);

    char *reversed = reverse(str);
    printf("The reversed string: %s\n", reversed);

    int palindrome = is_palindrome(str);
    printf("Is the string a palindrome? %s\n", palindrome ? "Yes" : "No");

    char *longest = longest_palindrome(str);
    printf("The longest palindrome in the string: %s\n", longest);

    char *shortest = shortest_palindrome(str);
    printf("The shortest palindrome that can be made by adding characters to the beginning of the string: %s\n", shortest);

    return 0;
}