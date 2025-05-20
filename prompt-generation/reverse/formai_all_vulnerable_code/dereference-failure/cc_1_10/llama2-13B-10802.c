//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate the longest common substring of two strings
int lcs(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int max = len1 > len2 ? len1 : len2;
    int i, j, k;
    char *lcs = malloc(max * sizeof(char));

    // Initialize the longest common substring with the first characters of both strings
    for (i = 0; i < len1; i++) {
        lcs[i] = s1[i];
    }

    // Iterate over the characters of both strings and calculate the longest common substring
    for (j = 0; j < len2; j++) {
        for (k = 0; k < len1; k++) {
            if (s2[j] == lcs[k]) {
                // Found a matching character, increment the length of the longest common substring
                lcs[k] = s2[j];
                break;
            }
        }
    }

    // Return the length of the longest common substring
    return strlen(lcs);
}

int main() {
    char *s1 = "banana";
    char *s2 = "anana";
    int len1 = strlen(s1), len2 = strlen(s2);
    int gcd_len = gcd(len1, len2);
    char *lcs_str = malloc(gcd_len * sizeof(char));

    // Calculate the greatest common divisor of the lengths of the two strings
    gcd_len = gcd(len1, len2);

    // Calculate the longest common substring of the two strings
    int lcs_len = lcs(s1, s2);

    // Print the length of the longest common substring and the greatest common divisor
    printf("Longest common substring length: %d\n", lcs_len);
    printf("Greatest common divisor: %d\n", gcd_len);

    return 0;
}