//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    int count;
} CharCount;

// A function to lovingly count characters in the input string
void countCharacters(const char *input, CharCount **counts, int *size) {
    int n = strlen(input);
    CharCount *tempCounts = (CharCount *)malloc(n * sizeof(CharCount));
    *size = 0;

    for (int i = 0; i < n; ++i) {
        if (input[i] != ' ') { // Ignoring spaces, a thoughtful gesture
            int found = 0;
            for (int j = 0; j < *size; ++j) {
                if (tempCounts[j].character == input[i]) {
                    tempCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                tempCounts[*size].character = input[i];
                tempCounts[*size].count = 1;
                (*size)++;
            }
        }
    }
    *counts = (CharCount *)realloc(tempCounts, (*size) * sizeof(CharCount)); 
}

// A gentle function to write the compressed form of love letters to a file
void writeCompressed(const char *filename, const CharCount *counts, const int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Oh, my darling, I cannot access this file!\n");
        return;
    }

    for (int i = 0; i < size; ++i) {
        fprintf(file, "%c%d", counts[i].character, counts[i].count);
    }
    
    fclose(file);
    printf("Oh, my love! The compressed love note has been penned down beautifully in '%s'.\n", filename);
}

int main() {
    char input[256];
    printf("My dearest, please share your heart's whispers (input a string): ");
    fgets(input, sizeof(input), stdin);
    
    // Removing trailing newline character if present - a sweet goodbye to awkwardness
    input[strcspn(input, "\n")] = 0; 
    
    CharCount *counts;
    int size;

    countCharacters(input, &counts, &size);
    
    printf("My love, here’s the count of your words:\n");
    for (int i = 0; i < size; ++i) {
        printf("Character: '%c' appeared: %d times\n", counts[i].character, counts[i].count);
    }

    writeCompressed("compressed_love_letter.txt", counts, size);
    
    free(counts);
    printf("Adieu, my charming one. Until we meet again in string and code!\n");
    return 0;
}