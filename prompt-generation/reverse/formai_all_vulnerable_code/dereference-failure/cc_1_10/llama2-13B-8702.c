//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a, b) (a < b ? a : b)

// Function to reverse a string
char *reverse_string(char *s) {
    int len = strlen(s);
    char *r = malloc(len * sizeof(char));
    int i, j;

    for (i = 0, j = len - 1; i < len; i++, j--) {
        r[i] = s[j];
    }

    return r;
}

// Function to remove duplicates from a string
char *remove_duplicates(char *s) {
    int len = strlen(s);
    char *r = malloc(len * sizeof(char));
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        if (j == 0 || s[i] != s[j - 1]) {
            r[j] = s[i];
            j++;
        }
    }

    return r;
}

// Function to replace all occurrences of a substring in a string
char *replace_all(char *s, char *find, char *replace) {
    int len_find = strlen(find);
    int len_s = strlen(s);
    char *r = malloc(len_s * sizeof(char));
    int i, j, k;

    for (i = 0, j = 0; i < len_s; i++) {
        if (strncmp(s + i, find, len_find) == 0) {
            r[j] = replace[0];
            j++;
            i += len_find - 1;
        } else {
            r[j] = s[i];
        }
    }

    return r;
}

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    char *rev_str = reverse_string(str);
    printf("Reversed string: %s\n", rev_str);

    char *no_dup_str = remove_duplicates(str);
    printf("String without duplicates: %s\n", no_dup_str);

    char *replaced_str = replace_all(str, "lazy", "fast");
    printf("String with replacements: %s\n", replaced_str);

    free(rev_str);
    free(no_dup_str);
    free(replaced_str);

    return 0;
}