//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compress a given string using a simple algorithm */
char * compress(char *input_str) {
    int len = strlen(input_str);
    int count = 1, cur = 0;
    char cur_char = input_str[0];
    char *compressed_str = (char*) malloc(len * sizeof(char));
    
    /* Loop through the string, counting consecutive occurrences of each character */
    for(int i = 1; i < len; i++) {
        if(input_str[i] != cur_char) {
            /* Add the compressed representation of the current character to the compressed string */
            compressed_str[cur++] = cur_char;
            char *count_str = (char*) malloc(10 * sizeof(char));
            sprintf(count_str, "%d", count);
            strcat(compressed_str, count_str);
            cur += strlen(count_str);
            free(count_str);
            
            /* Reset the count and current character */
            count = 1;
            cur_char = input_str[i];
        } else {
            count++;
        }
    }
    
    /* Add the final character to the compressed string */
    compressed_str[cur++] = cur_char;
    char *count_str = (char*) malloc(10 * sizeof(char));
    sprintf(count_str, "%d", count);
    strcat(compressed_str, count_str);
    cur += strlen(count_str);
    free(count_str);
    
    /* Add null terminator and return compressed string */
    compressed_str[cur] = '\0';
    return compressed_str;
}

int main() {
    char *input_str = "aaaabbbbccccdddd";
    char *compressed_str = compress(input_str);
    printf("Input string: %s\nCompressed string: %s\n", input_str, compressed_str);
    free(compressed_str);
    return 0;
}