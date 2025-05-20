//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int levenshtein_distance(const char *str1, const char *str2, int len1, int len2) {
    int cost = 1;
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int delete_op = matrix[i - 1][j] + 1;
            int insert_op = matrix[i][j - 1] + 1;
            int substitute_op = matrix[i - 1][j - 1];

            matrix[i][j] = min(delete_op, insert_op, substitute_op + cost);
        }
    }

    return matrix[len1][len2];
}

void print_string(const char *str) {
    printf("%s", str);
}

void print_int(int num) {
    printf("%d", num);
}

void print_ld(int len1, int len2, int dist) {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    strncpy(str1, (const char *) &str1 + sizeof(str1), len1);
    str1[len1] = '\0';

    strncpy(str2, (const char *) &str2 + sizeof(str2), len2);
    str2[len2] = '\0';

    print_string(str1);
    print_string(" -> ");
    print_string(str2);
    print_string(" : ");
    print_int(dist);
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

    if (len1 > MAX_LENGTH || len2 > MAX_LENGTH) {
        printf("Error: string length limit exceeded.\n");
        return EXIT_FAILURE;
    }

    int dist = levenshtein_distance(argv[1], argv[2], len1, len2);

    print_ld(len1, len2, dist);

    return EXIT_SUCCESS;
}