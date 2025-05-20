//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000 // maximum length for input string

// Compression function that takes in input string and outputs compressed string
char* compress(char input[]) {
    int count, strlen_input;
    char current_char, *result;
    size_t i, j, result_size;

    result_size = strlen_input = strlen(input); // initialize result size and length of input string
    result = (char*)malloc(result_size + 1); // allocate memory for the compressed string

    for (i = 0, j = 0; i < strlen_input; i++) { // iterate through input string
        current_char = input[i]; // save current character
        count = 1; // initialize count to 1

        while (i + 1 < strlen_input && input[i + 1] == current_char) { // check if next character is same as current character
            count++; // increment count
            i++; // increment i
        }

        if (count == 1) { // if count is only 1, simply add character to result
            result[j] = current_char;
            j++;
        }
        else { // else add count followed by character to result
            result[j] = count + '0';
            j++;

            result[j] = current_char;
            j++;
        }
    }

    result[j] = '\0'; // add null character at the end of the compressed string

    return result; // return compressed string
}

int main() {
    char input[MAX_STRING_LEN], *compressed;

    printf("Enter a string to compress: ");
    fgets(input, MAX_STRING_LEN, stdin); // get input string

    input[strcspn(input, "\r\n")] = 0; // remove newline characters
    compressed = compress(input); // compress input string

    printf("Compressed string is: %s\n", compressed);

    free(compressed); // free memory allocated for compressed string

    return 0;
}