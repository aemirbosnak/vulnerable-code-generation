//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sanitize(char* url) {

    char* sanitized_url = (char*)malloc(sizeof(char)*strlen(url)); // Allocate memory for sanitized URL
    int j = 0; // Counter variable for sanitized URL index
    int url_length = strlen(url); // Length of URL

    for(int i = 0; i < url_length; i++) {

        if(url[i] == '?' || url[i] == '#') { // Stop sanitizing further if query or fragment identifier is encountered
            break;
        }
        else if(url[i] == ' ') {  // Replace any spaces with %20
            sanitized_url[j++] = '%';
            sanitized_url[j++] = '2';
            sanitized_url[j++] = '0';
        }
        // Keep letters, digits, and safe characters unchanged
        else if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '*' || url[i] == '-' || url[i] == '_' || url[i] == '.' || url[i] == '/') {
            sanitized_url[j++] = url[i];
        }
        else { // Replace all unsafe characters with their hexadecimal representation
            char hex[3];
            sprintf(hex, "%02X", url[i]);
            sanitized_url[j++] = '%';
            sanitized_url[j++] = hex[0];
            sanitized_url[j++] = hex[1];
        }
    }

    sanitized_url[j] = '\0'; // Add null terminator 
    printf("%s\n", sanitized_url);

    free(sanitized_url); // Deallocate memory for sanitized URL
}

int main() {

    char url1[] = "http://example.com/path/to/file with spaces.html?param1=abc&param2=def#fragment";
    char url2[] = "FTP://username:password@host.com/path/to/file?param=value";
    char url3[] = "https://example.com/~username/";
    char url4[] = "file:///C:/Users/Username/Documents/file.txt";
    char url5[] = "http://example.com/path/to/file#fragment";
    char url6[] = "http://example.com/path/to/file?param=value&param2=value2";

    printf("Sanitized URL 1: ");
    sanitize(url1);
    printf("Sanitized URL 2: ");
    sanitize(url2);
    printf("Sanitized URL 3: ");
    sanitize(url3);
    printf("Sanitized URL 4: ");
    sanitize(url4);
    printf("Sanitized URL 5: ");
    sanitize(url5);
    printf("Sanitized URL 6: ");
    sanitize(url6);

    return 0;
}