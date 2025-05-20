//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: recursive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN_LEN 10
#define MAX_LEN 100
#define REPS 5

void generate_string(char *str, int len);
void print_string(char *str);
int compare_strings(char *str1, char *str2, int len);

int main(void) {
    char *str1, *str2;
    int len1, len2, i, ret;
    clock_t start, end;

    start = clock();

    len1 = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
    len2 = len1;
    str1 = (char *)calloc(len1, sizeof(char));
    str2 = (char *)calloc(len2, sizeof(char));

    generate_string(str1, len1);
    generate_string(str2, len2);

    printf("String 1: ");
    print_string(str1);
    printf("\nString 2: ");
    print_string(str2);

    for (i = 0; i < REPS; i++) {
        start = clock();
        ret = compare_strings(str1, str2, len1);
        end = clock();

        if (ret == 1) {
            printf("\nCorrect!\n");
            free(str1);
            free(str2);
            return 0;
        } else if (ret == -1) {
            printf("\nIncorrect! Try again.\n");
            len2 = rand() % (MAX_LEN - MIN_LEN + 1) + MIN_LEN;
            str2 = (char *)realloc(str2, len2 * sizeof(char));
            generate_string(str2, len2);
        } else {
            printf("\nError occurred!\n");
            free(str1);
            free(str2);
            return 1;
        }

        printf("\nTime taken: %.10fs\n", (end - start) / CLOCKS_PER_SEC);
    }

    free(str1);
    free(str2);
    return 0;
}

void generate_string(char *str, int len) {
    int i;

    for (i = 0; i < len; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[len] = '\0';
}

void print_string(char *str) {
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
}

int compare_strings(char *str1, char *str2, int len) {
    int i;

    for (i = 0; i < len; i++) {
        if (str1[i] != str2[i]) {
            return i == len - 1 ? -1 : 0;
        }
    }

    return 1;
}