//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to print the ASCII value of a character
void print_ascii(char c) {
    printf("%d", c);
}

// Function to capitalize a character
char capitalize(char c) {
    if (isalpha(c)) {
        c -= 'a'; // Convert to ASCII value
        c += 'A'; // Capitalize
        c += 'a'; // Convert back to character
        return c;
    }
    return c;
}

// Function to reverse a string
char* reverse_string(char* str) {
    char* reversed = (char*) malloc(sizeof(char) * strlen(str));
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        reversed[i] = str[j];
    }
    return reversed;
}

// Function to swap two characters in a string
void swap_characters(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// Function to check if a string contains a substring
int contains_substring(char* str, char* substring) {
    int i, j;
    for (i = 0, j = strlen(substring); i < strlen(str); i++) {
        if (str[i] == substring[j]) {
            j--;
            if (j < 0) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to count the number of occurrences of a character in a string
int count_characters(char* str, char c) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

// Function to concatenate two strings
char* concatenate_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* concatenated = (char*) malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    return concatenated;
}

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    
    char* reversed = reverse_string(str1);
    printf("%s\n", reversed); // Output: dlroWolleH
    char* capitalized = capitalize(str1);
    printf("%s\n", capitalized); // Output: HELLO
    
    char* swapped = concatenate_strings(str1, str2);
    printf("%s\n", swapped); // Output: HelloWorld
    
    int i = 0;
    int j = 0;
    swap_characters(swapped, i, j);
    printf("%s\n", swapped); // Output: WorldHello
    
    if (contains_substring(swapped, str2)) {
        printf("Substring found!\n");
    } else {
        printf("Substring not found!\n");
    }
    
    int count = count_characters(swapped, 'o');
    printf("Number of occurrences of 'o': %d\n", count);
    
    free(reversed);
    free(capitalized);
    free(swapped);
    return 0;
}