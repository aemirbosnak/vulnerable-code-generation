//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int len;
    char *str;
} String;

String str_new(char *s) {
    String str = {0};
    str.len = strlen(s);
    str.str = malloc(str.len + 1);
    strcpy(str.str, s);
    return str;
}

void str_del(String *str) {
    free(str->str);
    free(str);
}

int levenshtein_distance(String str1, String str2) {
    int m = str1.len, n = str2.len;
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (str1.str[i - 1] == str2.str[j - 1]) ? 0 : 1;
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + cost);
        }
    }

    return dp[m][n];
}

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int main() {
    char *str1 = "kitten";
    char *str2 = "sitting";

    String str1_ = str_new(str1);
    String str2_ = str_new(str2);

    int dist = levenshtein_distance(str1_, str2_);

    printf("Levenshtein Distance: %d\n", dist);

    str_del(&str1_);
    str_del(&str2_);

    return 0;
}