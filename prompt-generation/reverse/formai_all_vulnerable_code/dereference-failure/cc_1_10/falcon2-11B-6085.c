//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* input = "12345";
    char* output = "00001101 11101101";
    
    char* hex = strdup(input);

    char* result;
    int i, len;

    len = strlen(hex);
    for(i = 0; i < len; i += 2) {
        if(hex[i] == '0') {
            result = strcat(result, "0");
        } else {
            result = strcat(result, "1");
        }
        if(hex[i+1] == '0') {
            result = strcat(result, "0");
        } else {
            result = strcat(result, "1");
        }
    }

    result = strcat(result, " ");

    len = strlen(output);
    for(i = 0; i < len; i += 2) {
        if(output[i] == '0') {
            result = strcat(result, "0");
        } else {
            result = strcat(result, "1");
        }
        if(output[i+1] == '0') {
            result = strcat(result, "0");
        } else {
            result = strcat(result, "1");
        }
    }

    printf("%s\n", result);

    free(hex);
    free(output);
    free(result);
    return 0;
}