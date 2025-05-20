//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate the longest common substring of two strings
int lcs(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int i, j, maxlen = 0;
    char *lcs = malloc(sizeof(char) * (len1 + len2));

    // Initialize the longest common substring to empty
    memset(lcs, 0, sizeof(char) * (len1 + len2));

    // Loop through both strings, finding the longest common substring
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                // Found a matching character, increment the length of the LCS
                lcs[maxlen++] = s1[i];
                j++;
                while (j < len2 && s2[j] == s1[i]) {
                    j++;
                }
                maxlen++;
                break;
            }
        }
    }

    // Return the length of the longest common substring
    return maxlen;
}

int main() {
    char *s1 = "GeeksforGeeks";
    char *s2 = "Gfg";

    // Calculate the length of the longest common substring
    int len = lcs(s1, s2);

    // Print the length of the longest common substring
    printf("The length of the longest common substring is %d\n", len);

    // Calculate the greatest common divisor of the lengths of the two strings
    int gcd_len = gcd(strlen(s1), strlen(s2));

    // Print the greatest common divisor of the lengths of the two strings
    printf("The greatest common divisor of the lengths of the two strings is %d\n", gcd_len);

    return 0;
}