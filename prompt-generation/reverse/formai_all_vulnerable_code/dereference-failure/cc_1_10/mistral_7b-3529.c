//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1000
#define NUM_STRINGS 10000
#define NUM_ITERATIONS 10000

typedef struct {
    char str[MAX_STRING_LENGTH];
    int len;
} String;

void generate_random_string(String *str) {
    int i;
    for (i = 0; i < MAX_STRING_LENGTH; i++) {
        str->str[i] = rand() % 26 + 'a';
        if (rand() % 2 == 0)
            str->str[i] = '\0';
    }
    str->len = rand() % (MAX_STRING_LENGTH / 2) + 1;
}

void print_string(String *str) {
    for (int i = 0; i < str->len; i++)
        printf("%c", str->str[i]);
    printf("\n");
}

void compare_strings(String *str1, String *str2) {
    if (str1->len != str2->len)
        return;

    for (int i = 0; i < str1->len; i++) {
        if (str1->str[i] != str2->str[i]) {
            printf("Strings '%s' and '%s' are not equal.\n", str1->str, str2->str);
            exit(1);
        }
    }

    printf("Strings '%s' and '%s' are equal.\n", str1->str, str2->str);
}

int main() {
    srand(time(NULL));

    String *strings = malloc(NUM_STRINGS * sizeof(String));

    for (int i = 0; i < NUM_STRINGS; i++) {
        generate_random_string(&strings[i]);
        printf("Generated string %d: '%s'\n", i, strings[i].str);
    }

    for (int i = 0; i < NUM_STRINGS; i++) {
        for (int j = i + 1; j < NUM_STRINGS; j++) {
            for (int k = 0; k < NUM_ITERATIONS; k++) {
                String str1 = strings[i];
                String str2 = strings[j];

                compare_strings(&str1, &str2);

                str1 = strings[j];
                str2 = strings[i];
            }
        }
    }

    free(strings);

    return 0;
}