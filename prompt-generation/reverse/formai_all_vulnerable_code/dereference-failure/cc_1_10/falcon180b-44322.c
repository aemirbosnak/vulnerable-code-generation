//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 256
#define MAX_NUM_STRINGS 100

// structure to hold string and its length
typedef struct {
    char *str;
    int len;
} string_t;

// function to initialize a string
void init_string(string_t *str, char *s) {
    str->str = malloc(strlen(s) + 1);
    strcpy(str->str, s);
    str->len = strlen(s);
}

// function to compare two strings
int compare_strings(const void *a, const void *b) {
    string_t *str_a = (string_t *)a;
    string_t *str_b = (string_t *)b;
    return strcmp(str_a->str, str_b->str);
}

// function to sort an array of strings
void sort_strings(string_t *strs, int num_strs) {
    qsort(strs, num_strs, sizeof(string_t), compare_strings);
}

// function to print an array of strings
void print_strings(string_t *strs, int num_strs) {
    for (int i = 0; i < num_strs; i++) {
        printf("%s\n", strs[i].str);
    }
}

// main function
int main() {
    int num_strs;
    printf("Enter the number of strings: ");
    scanf("%d", &num_strs);

    if (num_strs > MAX_NUM_STRINGS) {
        printf("Error: Too many strings.\n");
        return 1;
    }

    string_t *strs = malloc(num_strs * sizeof(string_t));
    if (strs == NULL) {
        printf("Error: Out of memory.\n");
        return 1;
    }

    for (int i = 0; i < num_strs; i++) {
        char s[MAX_STRING_LENGTH];
        printf("Enter string %d: ", i + 1);
        scanf("%s", s);
        init_string(&strs[i], s);
    }

    sort_strings(strs, num_strs);
    printf("Sorted strings:\n");
    print_strings(strs, num_strs);

    for (int i = 0; i < num_strs; i++) {
        free(strs[i].str);
    }
    free(strs);

    return 0;
}