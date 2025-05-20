//FormAI DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main() {

    char *str1, *str2, *str3;
    int len1 = 0, len2 = 0, len3 = 0;

    str1 = (char*) malloc(MAX_BUF_SIZE * sizeof(char));
    str2 = (char*) malloc(MAX_BUF_SIZE * sizeof(char));
    str3 = (char*) malloc(MAX_BUF_SIZE * sizeof(char));

    if (str1 == NULL || str2 == NULL || str3 == NULL) {
        printf("Memory allocation error!");
        exit(1);
    }

    printf("Enter string 1: ");
    fgets(str1, MAX_BUF_SIZE, stdin);
    len1 = strlen(str1);
    if (len1 > 0 && str1[len1-1] == '\n') {
        str1[--len1] = '\0';
    }

    printf("Enter string 2: ");
    fgets(str2, MAX_BUF_SIZE, stdin);
    len2 = strlen(str2);
    if (len2 > 0 && str2[len2-1] == '\n') {
        str2[--len2] = '\0';
    }

    printf("Enter string 3: ");
    fgets(str3, MAX_BUF_SIZE, stdin);
    len3 = strlen(str3);
    if (len3 > 0 && str3[len3-1] == '\n') {
        str3[--len3] = '\0';
    }

    printf("String 1: %s, Length: %d\n", str1, len1);
    printf("String 2: %s, Length: %d\n", str2, len2);
    printf("String 3: %s, Length: %d\n", str3, len3);

    free(str1);
    free(str2);
    free(str3);

    return 0;
}