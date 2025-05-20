//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char input[100];
    char output[200];
    int i, j, k, len;
    char *p;
    char *q;

    // Prompt user to enter a string
    printf("Enter a string: ");
    scanf("%s", input);

    // Copy input string to output string
    strcpy(output, input);

    // Reverse the input string
    p = input;
    q = output + strlen(output) - 1;
    while (p < q) {
        *p ^= *q;
        *q ^= *p;
        *p ^= *q;
        p++;
        q--;
    }

    // Reverse the output string
    p = output;
    q = output + strlen(output) - 1;
    while (p < q) {
        *p ^= *q;
        *q ^= *p;
        *p ^= *q;
        p++;
        q--;
    }

    // Remove all spaces from the input string
    len = strlen(input);
    for (i = 0, j = 0; i < len; i++) {
        if (!isspace(input[i])) {
            output[j++] = input[i];
        }
    }

    // Remove all vowels from the input string
    for (i = 0, j = 0; i < strlen(output); i++) {
        if (!isalpha(output[i])) {
            output[j++] = output[i];
        } else if (isalpha(output[i])) {
            if (output[i]!= 'a' && output[i]!= 'e' && output[i]!= 'i' && output[i]!= 'o' && output[i]!= 'u') {
                output[j++] = output[i];
            }
        }
    }

    // Print the modified output string
    printf("Modified string: %s\n", output);

    return 0;
}