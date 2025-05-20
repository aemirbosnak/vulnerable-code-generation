//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    }
    else if (b < a && b < c) {
        return b;
    }
    else {
        return c;
    }
}

int levenshtein_distance(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    int **d = (int **) malloc(sizeof(int *) * (s_len + 1));
    for (int i = 0; i <= s_len; i++) {
        d[i] = (int *) malloc(sizeof(int) * (t_len + 1));
        d[i][0] = i;
    }
    for (int j = 0; j <= t_len; j++) {
        d[0][j] = j;
    }
    for (int j = 1; j <= t_len; j++) {
        for (int i = 1; i <= s_len; i++) {
            if (s[i - 1] == t[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1);
            }
        }
    }
    int distance = d[s_len][t_len];
    for (int i = 0; i <= s_len; i++) {
        free(d[i]);
    }
    free(d);
    return distance;
}

int main() {
    char s[100], t[100];
    printf("Enter first word: ");
    scanf("%s", s);
    printf("Enter second word: ");
    scanf("%s", t);
    int distance = levenshtein_distance(s, t);
    printf("Levenshtein Distance between %s and %s is %d.\n", s, t, distance);
    return 0;
}