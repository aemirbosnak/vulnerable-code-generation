//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, k;
    char str[MAX_SIZE];
    char *pattern;
    int *next;
    int len_pattern, len_text, len_longest;
    int count_longest = 0;
    char longest_substring[MAX_SIZE];

    printf("Enter the length of the pattern: ");
    scanf("%d", &n);

    printf("Enter the pattern: ");
    scanf("%s", str);

    pattern = str;
    len_pattern = strlen(pattern);

    // initialize the next array
    next = (int *)malloc(sizeof(int) * len_pattern);
    for (i = 0; i < len_pattern; i++) {
        next[i] = 0;
    }

    for (i = 0; i < len_pattern - 1; i++) {
        if (pattern[i] == pattern[i + 1]) {
            next[i + 1] = next[i] + 1;
        } else {
            next[i + 1] = next[i];
        }
    }

    // find the length of the longest repeating substring
    for (i = 0; i < len_pattern - 1; i++) {
        if (next[i] > count_longest) {
            count_longest = next[i];
            k = i;
        }
    }

    // find the longest repeating substring
    j = k - count_longest;
    for (i = 0; i < count_longest; i++) {
        longest_substring[i] = pattern[j];
        j++;
    }
    longest_substring[count_longest] = '\0';

    printf("Longest repeating substring: %s\n", longest_substring);

    return 0;
}