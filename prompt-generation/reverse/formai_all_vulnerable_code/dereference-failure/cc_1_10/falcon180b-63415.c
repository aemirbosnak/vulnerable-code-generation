//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables
char *text;
int len;
int max_palindromes;
int num_palindromes;
int *palindromes;

// Function declarations
void read_text();
void count_palindromes();
void print_palindromes();
void free_memory();

int main() {
    read_text();
    count_palindromes();
    print_palindromes();
    free_memory();
    return 0;
}

void read_text() {
    printf("Enter the text:\n");
    fgets(text, 1000000, stdin);
    len = strlen(text);
    text[len-1] = '\0'; // Remove newline character
}

void count_palindromes() {
    int i, j, k;
    max_palindromes = 1000;
    palindromes = malloc(max_palindromes * sizeof(int));
    num_palindromes = 0;

    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            if (isalnum(text[j])) {
                k = 0;
                while (isalnum(text[j]) && text[j] == text[i+k]) {
                    k++;
                }
                if (k > 1 && text[i+k-1] == text[j]) {
                    palindromes[num_palindromes++] = i;
                }
            }
        }
    }

    if (num_palindromes == max_palindromes) {
        printf("Maximum number of palindromes reached.\n");
    }
}

void print_palindromes() {
    int i;
    for (i = 0; i < num_palindromes; i++) {
        printf("%d ", palindromes[i]);
    }
}

void free_memory() {
    free(palindromes);
}