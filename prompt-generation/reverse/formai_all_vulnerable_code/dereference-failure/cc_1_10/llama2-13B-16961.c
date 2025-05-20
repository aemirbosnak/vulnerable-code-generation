//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 50

// Function to reverse a string
void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to remove duplicates from a string
void remove_dups(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] != str[j]) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

// Function to replace all occurrences of a substring in a string
void replace_substrings(char *str, char *find, char *replace) {
    int i, j;
    char temp;

    for (i = 0, j = 0; i < strlen(str); i++) {
        if (str[i] == find[0]) {
            j = 0;
            while (str[i + j] == find[j]) {
                j++;
            }
            temp = str[i];
            for (int k = 0; k < j; k++) {
                str[i + k] = replace[k];
            }
            str[i + j] = temp;
        }
    }
}

int main() {
    char str1[] = "The quick brown fox jumps over the lazy dog";
    char str2[] = "The quick brown fox jumps over the lazy dog";
    char str3[] = "The quick brown fox jumps over the lazy dog";

    // Reverse the string
    reverse_str(str1);
    printf("Reversed string: %s\n", str1);

    // Remove duplicates from the string
    remove_dups(str2);
    printf("String without duplicates: %s\n", str2);

    // Replace all occurrences of 'brown' with 'green'
    replace_substrings(str3, "brown", "green");
    printf("String with replaced 'brown' with 'green': %s\n", str3);

    return 0;
}