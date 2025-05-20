//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32
#define MAX_BIN_LENGTH (MAX_NUM_LENGTH * 8)

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }

    char *num_str = argv[1];
    int num_len = strlen(num_str);
    if (num_len > MAX_NUM_LENGTH) {
        printf("Error: number is too long\n");
        return 1;
    }

    char *bin_str = malloc(MAX_BIN_LENGTH + 1);
    if (bin_str == NULL) {
        printf("Error: malloc failed\n");
        return 1;
    }

    int bin_len = 0;
    int i = 0;
    while (num_str[i]!= '\0') {
        if (num_str[i] == '.') {
            printf("Error: decimal numbers are not supported\n");
            free(bin_str);
            return 1;
        }

        if (num_str[i] >= '0' && num_str[i] <= '9') {
            bin_str[bin_len++] = '0' + (num_str[i] - '0');
        } else {
            printf("Error: invalid character in number\n");
            free(bin_str);
            return 1;
        }

        i++;
    }

    bin_str[bin_len] = '\0';
    printf("Binary: %s\n", bin_str);

    free(bin_str);
    return 0;
}