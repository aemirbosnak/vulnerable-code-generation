//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct for storing character and its count
typedef struct char_count {
    char c;
    int count;
} char_count;

// Function to initialize an empty char_count struct
char_count init_char_count() {
    char_count cc;
    cc.c = '\0';
    cc.count = 0;
    return cc;
}

// Function to increment the count of a character in a char_count struct
void inc_char_count(char_count *cc, char c) {
    if (cc->c == c) {
        cc->count++;
    }
}

// Function to add the count of two char_count structs
void add_char_count(char_count *dest, char_count src) {
    dest->count += src.count;
}

// Function to create a new char_count struct for a given character
char_count new_char_count(char c) {
    char_count cc = init_char_count();
    cc.c = c;
    return cc;
}

// Function to count the occurrences of each character in a given string
char_count* count_chars(char *str) {
    int str_len = strlen(str);
    char_count *counts = malloc(sizeof(char_count) * (sizeof(char) + 1));

    // Initialize all char_count structures to zero
    for (int i = 0; i < sizeof(char) + 1; i++) {
        counts[i] = init_char_count();
    }

    for (int i = 0; i < str_len; i++) {
        inc_char_count(&counts[tolower(str[i])], tolower(str[i]));
    }

    return counts;
}

// Function to print the contents of a char_count struct
void print_char_count(char_count cc) {
    printf("%c : %d\n", cc.c, cc.count);
}

// Function to print the contents of all char_count structs in an array
void print_char_counts(char_count *counts, int size) {
    for (int i = 0; i < size; i++) {
        print_char_count(counts[i]);
    }
}

// Our star-crossed lovers: Romeo and Juliet
int main() {
    char *romeo = "Romeo, Romeo! wherefore art thou Romeo?";
    char *juliet = "Deny thy father and refuse thy name;";

    // Count the occurrences of each character in both strings
    char_count *romeo_counts = count_chars(romeo);
    char_count *juliet_counts = count_chars(juliet);

    // Combine the character count arrays
    int size = sizeof(char) + 1;
    char_count total_counts[size];
    for (int i = 0; i < size; i++) {
        total_counts[i] = init_char_count();
    }

    for (int i = 0; i < size; i++) {
        add_char_count(&total_counts[i], romeo_counts[i]);
        add_char_count(&total_counts[i], juliet_counts[i]);
    }

    // Print the combined character counts
    print_char_counts(total_counts, size);

    // Free memory
    free(romeo_counts);
    free(juliet_counts);

    return 0;
}