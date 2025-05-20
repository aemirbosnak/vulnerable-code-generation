//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: puzzling
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

char *arr;
size_t len;
size_t cap;
int *vowels;

int main(void) {
    FILE *file;
    int total_vowels = 0;
    char c;

    printf("Enter file name: ");
    scanf("%ms", &arr);

    file = fopen(arr, "r");
    if (!file) {
        puts("Error opening file.");
        exit(1);
    }

    cap = strlen(arr) + 1;
    arr = (char *)calloc(cap, sizeof(char));
    fgets(arr, cap, file);
    len = strlen(arr);
    vowels = (int *)calloc(26, sizeof(int));

    for (int i = len - 1; i >= 0; i--) {
        c = arr[i];
        if (isalpha(c)) {
            switch (tolower(c)) {
                case 'a': vowels[0]++; break;
                case 'e': vowels[1]++; break;
                case 'i': vowels[2]++; break;
                case 'o': vowels[3]++; break;
                case 'u': vowels[4]++; break;
                default: break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        total_vowels += vowels[i];
    }

    printf("Total vowels in file: %d\n", total_vowels);

    free(arr);
    free(vowels);
    fclose(file);

    return 0;
}