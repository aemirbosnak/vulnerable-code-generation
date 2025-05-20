//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_PATTERN_LEN 100

// Function to print a pattern
void print_pattern(char *pattern) {
    int i, j;

    for (i = 0; i < strlen(pattern); i++) {
        switch (pattern[i]) {
            case 'A':
                printf("A");
                break;
            case 'B':
                printf("B");
                sleep(1);
                break;
            case 'C':
                printf("C");
                system("cls");
                break;
            default:
                printf("%c", pattern[i]);
                break;
        }
    }
}

// Function to generate a random pattern
char *generate_pattern(int len) {
    char *pattern = malloc(len * sizeof(char));
    int i;

    for (i = 0; i < len; i++) {
        switch (rand() % 3) {
            case 0:
                pattern[i] = 'A';
                break;
            case 1:
                pattern[i] = 'B';
                break;
            case 2:
                pattern[i] = 'C';
                break;
        }
    }

    return pattern;
}

int main() {
    int pattern_len = 50;
    char *pattern = generate_pattern(pattern_len);

    printf("--- Pattern ---\n");
    print_pattern(pattern);

    free(pattern);

    return 0;
}