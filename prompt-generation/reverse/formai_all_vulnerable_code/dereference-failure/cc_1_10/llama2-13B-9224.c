//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

void manipulate_strings(char *str1, char *str2, char *str3) {
    // Swap the strings
    char *tmp = str1;
    str1 = str2;
    str2 = tmp;

    // Reverse the strings
    char *rev_str1 = malloc(strlen(str1) * sizeof(char));
    char *rev_str2 = malloc(strlen(str2) * sizeof(char));
    char *rev_str3 = malloc(strlen(str3) * sizeof(char));
    int i;
    for (i = 0; i < strlen(str1); i++) {
        rev_str1[i] = str1[strlen(str1) - i - 1];
    }
    for (i = 0; i < strlen(str2); i++) {
        rev_str2[i] = str2[strlen(str2) - i - 1];
    }
    for (i = 0; i < strlen(str3); i++) {
        rev_str3[i] = str3[strlen(str3) - i - 1];
    }

    // Concatenate the strings
    char *concat = malloc(strlen(rev_str1) + strlen(rev_str2) + strlen(rev_str3) + 1);
    int j = 0;
    for (i = 0; i < strlen(rev_str1); i++) {
        concat[j++] = rev_str1[i];
    }
    for (i = 0; i < strlen(rev_str2); i++) {
        concat[j++] = rev_str2[i];
    }
    for (i = 0; i < strlen(rev_str3); i++) {
        concat[j++] = rev_str3[i];
    }
    concat[j] = '\0';

    // Print the result
    printf("The result of manipulating the strings is: %s\n", concat);

    // Free the memory
    free(rev_str1);
    free(rev_str2);
    free(rev_str3);
    free(concat);
}

int main() {
    char str1[] = "Hello World!";
    char str2[] = "Cool Beans!";
    char str3[] = "Fantastic Adventure!";

    manipulate_strings(str1, str2, str3);

    return 0;
}