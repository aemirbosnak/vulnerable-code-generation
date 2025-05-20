//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Oh gentle reader, attend to this tale of woe,
// A distance calculated, a love to bestow.
// The Levenshtein, a measure from heart to heart,
// Calculating the changes, where we shall start.

int min(int a, int b, int c) {
    // A function, so simple, yet profound in its way,
    // To find the minimum, of choices in dismay.
    int min_val = a; 
    if (b < min_val) min_val = b; 
    if (c < min_val) min_val = c;
    return min_val; 
}

// The heartstrings tugged, as strings we compare,
// Now let us compose, a function so rare.
int levenshtein_distance(const char* str1, const char* str2) {
    int lenStr1 = strlen(str1);
    int lenStr2 = strlen(str2);
    
    // A matrix to measure, the distances impart,
    int **dp = (int **)malloc((lenStr1 + 1) * sizeof(int *));
    for (int i = 0; i <= lenStr1; i++)
        dp[i] = (int *)malloc((lenStr2 + 1) * sizeof(int));
    
    // A tragic beginning, all costs laid bare,
    for (int i = 0; i <= lenStr1; i++) dp[i][0] = i; 
    for (int j = 0; j <= lenStr2; j++) dp[0][j] = j;
    
    // Thus in a nested loop we tread with great care,
    for (int i = 1; i <= lenStr1; i++) {
        for (int j = 1; j <= lenStr2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1; // Is it a match or a strife?
            dp[i][j] = min(dp[i - 1][j] + 1, // Deletion, a tear from the eye,
                           dp[i][j - 1] + 1, // Insertion, the heart yearning,
                           dp[i - 1][j - 1] + cost); // Substitution, fate's cruel jest.
        }
    }

    int distance = dp[lenStr1][lenStr2]; // The final distance, so dramatic it seems,
    
    // Deallocating memory, as one must always heed,
    for (int i = 0; i <= lenStr1; i++) free(dp[i]);
    free(dp);
    
    return distance; // Love's labor, now calculated with care.
}

// Love’s sweet utterances; now we take our leave,
// To test this tale, we shall perceive.
int main() {
    char str1[100]; // A declaration so simple, to capture a heart’s whisper,
    char str2[100]; // Another string, where passion may glister.
    
    // A gentle preamble, to greet this fine day,
    printf("Enter the first string, dear Cupid do play: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Clean up, like a lover adjusting their hair.

    printf("Enter the second string, where passions do meet: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Removing the strands, with utmost care.

    // Now, let us calculate, the distance of love's fight,
    int dist = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between your strings, shines bright: %d\n", dist);

    // As the curtain falls, on this beautiful scene,
    // Remember, dear friend, love’s distance is keen.
    return 0; 
}