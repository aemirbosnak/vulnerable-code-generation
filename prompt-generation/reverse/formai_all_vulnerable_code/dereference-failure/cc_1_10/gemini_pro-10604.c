//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A celestial tapestry of cosmic strings, where each thread is a character in a surrealist text.
typedef struct s_string {
    char *nucleotides;
    size_t length;
} string;

// The ethereal dance of the Levenshtein distance, traversing the cosmic tapestry of strings.
int levenshtein(string a, string b) {
    int **distances = malloc((a.length + 1) * sizeof(int *));
    for (size_t i = 0; i <= a.length; i++) {
        distances[i] = malloc((b.length + 1) * sizeof(int));
    }

    // The genesis of the Levenshtein distance matrix, a cosmic canvas of possibilities.
    for (size_t i = 0; i <= a.length; i++) {
        distances[i][0] = i;
    }
    for (size_t j = 0; j <= b.length; j++) {
        distances[0][j] = j;
    }

    // The celestial ballet of the Levenshtein algorithm, weaving a tapestry of transformations.
    for (size_t i = 1; i <= a.length; i++) {
        for (size_t j = 1; j <= b.length; j++) {
            int cost = (a.nucleotides[i - 1] == b.nucleotides[j - 1]) ? 0 : 1;
            distances[i][j] = fmin(
                distances[i - 1][j] + 1, // Insertion: A celestial brushstroke adding a character to the tapestry.
                fmin(distances[i][j - 1] + 1, // Deletion: A cosmic eraser removing a character from the tapestry.
                    distances[i - 1][j - 1] + cost) // Substitution: A celestial paintbrush replacing a character with another.
            );
        }
    }

    // The culmination of the cosmic dance, revealing the distance between two surrealist strings.
    int distance = distances[a.length][b.length];
    for (size_t i = 0; i <= a.length; i++) {
        free(distances[i]);
    }
    free(distances);
    return distance;
}

// The cosmic portal to a surrealist text, where words dance in ethereal patterns.
string generate_surrealist_text(size_t length) {
    string text;
    text.nucleotides = malloc(length * sizeof(char));
    text.length = length;

    for (size_t i = 0; i < length; i++) {
        // A celestial roulette wheel, spinning to select a surrealist character.
        int index = rand() % 26;
        text.nucleotides[i] = 'a' + index;
    }

    return text;
}

int main() {
    // The cosmic stage is set, where surrealist texts dance in the void.
    string a = generate_surrealist_text(10);
    string b = generate_surrealist_text(15);

    // The cosmic ballet of the Levenshtein distance, measuring the distance between surrealist realms.
    int distance = levenshtein(a, b);

    // The celestial chorus sings the distance between two realms of dreams.
    printf("The distance between the surrealist texts is: %d\n", distance);

    return 0;
}