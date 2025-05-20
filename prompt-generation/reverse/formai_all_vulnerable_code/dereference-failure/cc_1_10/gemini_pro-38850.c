//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom string manipulation functions
char *str_replace(char *str, const char *old, const char *new) {
    char *pos, *ret;
    int len = strlen(old);
    if (strlen(new) != len) {
        return NULL;  // Replacement lengths must match
    }
    ret = malloc(strlen(str) + 1);
    if (!ret) {
        return NULL;  // Memory allocation failed
    }
    strcpy(ret, str);
    while ((pos = strstr(ret, old))) {
        memcpy(pos, new, len);
        pos += len;
    }
    return ret;
}

int str_count(const char *str, const char *substr) {
    int count = 0;
    const char *ptr = str;
    while ((ptr = strstr(ptr, substr))) {
        count++;
        ptr += strlen(substr);
    }
    return count;
}

char *str_reverse(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return str;
}

char *str_shuffle(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int j = rand() % len;
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return str;
}

// Example usage
int main() {
    char str[] = "This is an example string";

    // Replace "is" with "was"
    char *new_str = str_replace(str, "is", "was");
    printf("Replaced \"is\" with \"was\": %s\n", new_str);
    free(new_str);

    // Count the number of occurrences of "an"
    int count = str_count(str, "an");
    printf("Number of occurrences of \"an\": %d\n", count);

    // Reverse the string
    char *reversed_str = str_reverse(strdup(str));
    printf("Reversed string: %s\n", reversed_str);
    free(reversed_str);

    // Shuffle the string
    char *shuffled_str = str_shuffle(strdup(str));
    printf("Shuffled string: %s\n", shuffled_str);
    free(shuffled_str);

    return 0;
}