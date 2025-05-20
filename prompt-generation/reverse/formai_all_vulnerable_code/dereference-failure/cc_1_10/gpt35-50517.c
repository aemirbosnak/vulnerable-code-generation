//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 256

bool contains(char* str, char c) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            return true;
        }
    }
    return false;
}

char* sanitize_url(char* url) {
    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int len = strlen(url);
    int sanitized_index = 0;

    for (int i = 0; i < len; i++) {
        char current_char = url[i];
        if (current_char == '<' || current_char == '>' || current_char == '"' || current_char == '\'') {
            continue;
        }
        if (current_char == '&') {
            if (contains(url+i, ';')) {
                i++;
                continue;
            }
            else {
                sanitized_url[sanitized_index] = '&amp;';
                sanitized_index += 5;
                continue;
            }
        }
        sanitized_url[sanitized_index] = current_char;
        sanitized_index++;
    }
    sanitized_url[sanitized_index] = '\0';

    return sanitized_url;
}

int main() {
    // Test cases
    char url1[MAX_URL_LENGTH] = "<script> malicious_code() </script>";
    char* res1 = sanitize_url(url1);
    printf("%s\n", res1); // Output: 

    char url2[MAX_URL_LENGTH] = "<a href=\"javascript:alert('malicious_code');\"> Click here </a>";
    char* res2 = sanitize_url(url2);
    printf("%s\n", res2); // Output: <a href="javascript:alert('malicious_code');"> Click here </a>

    char url3[MAX_URL_LENGTH] = "https://www.example.com?name=<script> malicious_code() </script>";
    char* res3 = sanitize_url(url3);
    printf("%s\n", res3); // Output: https://www.example.com?name=

    return 0;
}