//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 1024

void __print_string(const char* str) {
    char* p = str;
    while (*p != '\0') {
        putchar(*p);
        p++;
    }
}

int main() {
    char* str = "The quick brown fox jumps over the lazy dog";
    int len = strlen(str);

    // Shuffle the string
    for (int i = 0; i < len; i++) {
        int j = rand() % len;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Generate a random substring
    int start = rand() % len;
    int end = rand() % len;
    char* substr = str + start;
    int substr_len = end - start;

    // Print the original string
    __print_string(str);

    // Print the random substring
    printf("Random substring: %s\n", substr);

    // Print the shuffled string
    __print_string(str);

    // Check if the random substring is present in the shuffled string
    int found = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == substr[0]) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("The random substring %s is present in the shuffled string\n", substr);
    } else {
        printf("The random substring %s is not present in the shuffled string\n", substr);
    }

    return 0;
}