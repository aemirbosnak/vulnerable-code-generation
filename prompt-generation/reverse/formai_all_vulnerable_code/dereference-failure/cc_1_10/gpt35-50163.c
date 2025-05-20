//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 100

int main() {
    char url[MAX_URL_LENGTH];
    char safe[MAX_URL_LENGTH];
    char *p = url;
    char *q = safe;

    printf("Enter the URL:\n");
    fgets(url, MAX_URL_LENGTH, stdin);

    while (*p != '\0') {
        switch (*p) {
            case '<':
                *q = '&';
                *(q+1) = 'l';
                *(q+2) = 't';
                *(q+3) = ';';
                q += 4;
                break;
            case '>':
                *q = '&';
                *(q+1) = 'g';
                *(q+2) = 't';
                *(q+3) = ';';
                q += 4;
                break;
            case '&':
                *q = '&';
                *(q+1) = 'a';
                *(q+2) = 'm';
                *(q+3) = 'p';
                *(q+4) = ';';
                q += 5;
                break;
            case '\"':
                *q = '&';
                *(q+1) = 'q';
                *(q+2) = 'u';
                *(q+3) = 'o';
                *(q+4) = 't';
                *(q+5) = ';';
                q += 6;
                break;
            case '\'':
                *q = '&';
                *(q+1) = '#';
                *(q+2) = '3';
                *(q+3) = '9';
                *(q+4) = ';';
                q += 5;
                break;
            default:
                *q = *p;
                q++;
                break;
        }
        p++;
    }
    *q = '\0';

    printf("Sanitized URL: %s\n", safe);

    return 0;
}