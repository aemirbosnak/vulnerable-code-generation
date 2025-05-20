//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compress a string using the Shannon method
void compress_string(char* input_str, char* output_str) {
    int count[26] = {0};
    int index = 0;
    int length = strlen(input_str);

    for (int i = 0; i < length; i++) {
        count[input_str[i] - 'a']++;
    }

    for (int i = 0; i < length; i++) {
        char ch = input_str[i];

        if (count[ch - 'a'] > 1) {
            count[ch - 'a']--;
            output_str[index] = '(';
            index++;

            for (int j = 0; j < count[ch - 'a']; j++) {
                output_str[index] = ch;
                index++;
            }

            output_str[index] = ')';
            index++;
        } else {
            output_str[index] = ch;
            index++;
        }
    }

    output_str[index] = '\0';
}

int main() {
    char input_str[] = "aaabccccdddd";
    char output_str[strlen(input_str) + 2];

    compress_string(input_str, output_str);

    printf("Input string: %s\n", input_str);
    printf("Compressed string: %s\n", output_str);

    return 0;
}