//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

void reverse_string(char *str, int start, int end) {
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void process_string(char *input) {
    int len = strlen(input);
    int i, j, k;

    if (len % 2 == 0) {
        printf("Error: String length must be odd.\n");
        exit(1);
    }

    for (i = 0; i < len / 2; i++) {
        j = i;
        k = len - i - 1;
        if (isalpha(input[i]) && isalpha(input[k])) {
            reverse_string(input, i, k);
        }
    }

    printf("Processed string: %s\n", input);
}

int main(int argc, char *argv[]) {
    char input[MAX_LEN];

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    strcpy(input, argv[1]);
    process_string(input);

    return 0;
}