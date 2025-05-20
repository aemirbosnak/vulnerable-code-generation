//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_STRING_LENGTH 100

void die(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        die("Usage: ./levenshtein_distance_post_apocalypse <string1> <string2>\n");
    }

    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > len2) {
        char temp[MAX_STRING_LENGTH];
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
        len1 = len2;
        len2 = strlen(str2);
    }

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, matrix[len1][len2]);

    return EXIT_SUCCESS;
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