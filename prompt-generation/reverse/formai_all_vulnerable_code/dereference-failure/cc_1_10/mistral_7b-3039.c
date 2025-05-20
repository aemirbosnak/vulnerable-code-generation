//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 128
#define MAX_STR 1024
#define MIN_LEN 5
#define MAX_LEN 50
#define MIN_PATTERN 1
#define MAX_PATTERN 5

char *patterns[MAX_PATTERN] = {
    "##.......#####........#####.......##",
    "###......######......######......###",
    "#####.....#######......#######.....##",
    "######....#########......#########..##",
    "########..#########......#########...."};

void print_ascii(char str[], int len, int pattern) {
    int i, j, k, l;
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(patterns[pattern]); j++) {
            if (j % 11 == 0) {
                k = i;
                if (str[i] == ' ') {
                    printf(" %s", &patterns[pattern][j]);
                    continue;
                }
                while (str[k] != '\0') {
                    if (str[k] == str[i]) {
                        printf("%s", &patterns[pattern][j]);
                        break;
                    }
                    k++;
                }
            }
            printf("%c", patterns[pattern][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    char str[MAX_STR];
    int len, pattern;

    if (argc != 3) {
        printf("Usage: %s <text> <pattern>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]);
    pattern = atoi(argv[2]);

    if (len < MIN_LEN || len > MAX_LEN || pattern < MIN_PATTERN || pattern > MAX_PATTERN) {
        printf("Invalid input. Text length should be between %d and %d. Pattern number should be between %d and %d.\n", MIN_LEN, MAX_LEN, MIN_PATTERN, MAX_PATTERN);
        return 1;
    }

    print_ascii(argv[1], len, pattern);

    return 0;
}