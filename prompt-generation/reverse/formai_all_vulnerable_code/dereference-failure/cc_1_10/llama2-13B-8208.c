//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1024

int main() {
    char *str = "Hello, World!";
    char *new_str = "";
    size_t i, j;
    int len = strlen(str);

    // Step 1: Shuffle the string
    for (i = 0; i < len; i++) {
        j = rand() % len;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    // Step 2: Reverse the string
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    // Step 3: Remove consecutive duplicates
    for (i = 0; i < len; i++) {
        if (i < len - 1 && str[i] == str[i + 1]) {
            str[i] = '\0';
        }
    }

    // Step 4: Compress the string using run-length encoding
    for (i = 0; i < len; i++) {
        if (str[i] == str[i + 1]) {
            int count = 1;
            while (i < len && str[i] == str[i + 1]) {
                count++;
                i++;
            }
            str[i] = count + '0';
        } else {
            str[i] = str[i + 1] = '\0';
        }
    }

    // Step 5: Print the modified string
    printf("Modified string: %s\n", str);

    return 0;
}