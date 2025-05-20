//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

char* compress(char* str, int len);

int main() {
    char input[MAX_SIZE];
    char* compressed;

    printf("Please enter a string:\n");
    fgets(input, MAX_SIZE, stdin);

    int len = strlen(input);
    
    //Replace newline character with null character
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    compressed = compress(input, len);
    printf("Compressed string: %s\n", compressed);

    free(compressed);

    return 0;
}

char* compress(char* str, int len) {
    char* result = (char*)malloc(sizeof(char) * (len*2 + 1));

    if (len <= 1) {
        strncpy(result, str, len+1);
        return result;
    }

    int count = 1;
    char* sub_result = compress(str + 1, len - 1);

    if (str[0] == sub_result[0]) {
        count = (int)sub_result[1] - '0' + 1;
        snprintf(result, 10, "%d%c%s", count + 1, str[0], sub_result + 2);
        free(sub_result);
        return result;
    }

    snprintf(result, 10, "%d%c%s", count, str[0], sub_result);
    free(sub_result);
    return result;
}