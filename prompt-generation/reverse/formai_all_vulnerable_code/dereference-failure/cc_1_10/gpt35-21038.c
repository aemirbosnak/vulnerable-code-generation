//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) { 
    if (a <= b && a <= c) return a; 
    else if (b <= a && b <= c) return b; 
    else return c; 
} 

int calc_levenshtein_distance(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    int** dist = (int**)malloc(sizeof(int*)*(len_a+1));
    for (int i=0; i<=len_a; i++) {
        dist[i] = (int*)malloc(sizeof(int)*(len_b+1));
        memset(dist[i], 0, sizeof(int)*(len_b+1));
    }
    
    for (int i=0; i<=len_a; i++) {
        for (int j=0; j<=len_b; j++) {
            if (i == 0) {
                dist[i][j] = j;
            } else if (j == 0) {
                dist[i][j] = i;
            } else if (a[i-1] == b[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = 1 + min(dist[i][j-1], dist[i-1][j], dist[i-1][j-1]);
            }
        }
    }
    
    int result = dist[len_a][len_b];
    
    for (int i=0; i<=len_a; i++) {
        free(dist[i]);
    }
    free(dist);
    
    return result;
}

int main() {
    char a[100], b[100];
    printf("Enter first string: ");
    scanf("%s", a);
    printf("Enter second string: ");
    scanf("%s", b);
    
    int distance = calc_levenshtein_distance(a, b);
    
    printf("The Levenshtein distance between '%s' and '%s' is: %d", a, b, distance);
    
    return 0;
}