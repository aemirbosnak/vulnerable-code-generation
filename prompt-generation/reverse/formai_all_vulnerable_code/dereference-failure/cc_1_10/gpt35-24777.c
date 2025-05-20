//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int **m = (int **) malloc((s1_len + 1) * sizeof(int *));
    
    for (int i = 0; i <= s1_len; i++) {
        m[i] = (int*) malloc((s2_len + 1) * sizeof(int));
        m[i][0] = i;
    }
    
    for (int j = 0; j <= s2_len; j++) {
        m[0][j] = j;
    }
    
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                m[i][j] = m[i - 1][j - 1];
            } else {
                m[i][j] = min(
                    m[i - 1][j] + 1,
                    m[i][j - 1] + 1,
                    m[i - 1][j - 1] + 1
                );
            }
        }
    }
    
    int result = m[s1_len][s2_len];
    
    for (int i = 0; i <= s1_len; i++) {
        free(m[i]);
    }
    
    free(m);
    return result;
}

int main() {
    char *s1 = "kitten";
    char *s2 = "sitting";
    
    printf("Levenshtein Distance between '%s' and '%s' is : %d\n", s1, s2, levenshtein(s1, s2));
    return 0;
}