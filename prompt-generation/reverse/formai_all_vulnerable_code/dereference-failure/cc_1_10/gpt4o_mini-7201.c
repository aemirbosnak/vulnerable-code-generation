//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lamentation of two strings, yearning to be one.
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = malloc((len_s1 + 1) * sizeof(int*));

    for (int i = 0; i <= len_s1; i++) {
        d[i] = malloc((len_s2 + 1) * sizeof(int));
        d[i][0] = i; // The cost of deletion
    }

    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j; // The cost of insertion
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1]; // Characters match, no cost
            } else {
                // Choose the least cost among deletion, insertion, and substitution.
                d[i][j] = 1 + fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]);
            }
        }
    }

    int dist = d[len_s1][len_s2]; // The final cost
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);
    
    return dist;
}

// A sonnet to the lovers, showing their trials.
void print_distance(const char *s1, const char *s2) {
    printf("Oh, fickle fate! For these names hold weight!\n");
    printf("Between the fair Juliet and the bold Romeo,\n");
    int dist = levenshtein_distance(s1, s2);
    printf("The distance of love, 'twixt '%s' and '%s': %d\n", s1, s2, dist);
    printf("A number that doth tell of all that doth ache,\n");
    printf("A measure of longing, of hearts that do break.\n");
}

// A triumph to the lovers, the play shall unfold and reveal.
int main() {
    char romeo[] = "Romeo";
    char juliet[] = "Juliet";

    // The chorus speaks, as we measure the distance in heart.
    print_distance(romeo, juliet);

    char more_distanced_romeo[] = "Romeos";
    char more_distanced_juliet[] = "Juliett";

    // The audience gasps, for they expect a greater distance still.
    print_distance(more_distanced_romeo, more_distanced_juliet);

    char opposing_fates_1[] = "Capulet";
    char opposing_fates_2[] = "Montague";

    // The stage set for conflict, the familial feud shall calculate.
    print_distance(opposing_fates_1, opposing_fates_2);

    // Perchance to dream of musings yet unfurled,
    printf("Yet love remains, where distances may stray,\n");
    printf("For in each name whispered, affection does play.\n");

    return 0;
}