//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include<stdio.h>
#include<string.h>

char* urlSanitizer(char* url) {

    int i = 0, j = 0;
    char* sanitizedUrl = malloc(strlen(url) + 1);
  
    while (url[i] != '\0') {
        
        if (url[i] == '\\' && url[i + 1] == 'x') { // handle hex encoding
            int hexChars = 0;
            char hexValue[3] = {'\0', '\0', '\0'}; // initialize with null
            while (hexChars < 2) { // gather hex digits
                hexValue[hexChars] = url[i + hexChars + 2];
                hexChars++;
            }
            sanitizedUrl[j++] = (char)strtol(hexValue, NULL, 16); //convert hex to ascii value
            i += 4; // jump to next character after hex value
        }
        else if (url[i] == '&') { // handle html encoding
            if (strncmp(url+i+1, "amp;", 4) == 0) { // check for &amp;
                sanitizedUrl[j++] = '&';
                i += 5;
            } else if (strncmp(url+i+1, "lt;", 3) == 0) { // check for &lt;
                sanitizedUrl[j++] = '<';
                i += 4;
            } else if (strncmp(url+i+1, "gt;", 3) == 0) { // check for &gt;
                sanitizedUrl[j++] = '>';
                i += 4;
            } else if (strncmp(url+i+1, "quot;", 5) == 0) { // check for &quot;
                sanitizedUrl[j++] = '"';
                i += 6;
            } else if (strncmp(url+i+1, "apos;", 5) == 0) { // check for &apos;
                sanitizedUrl[j++] = '\'';
                i += 6;
            } else {
                sanitizedUrl[j++] = '&'; // if no match found, append & and continue from next character
                i++;
            }
        }
        else {
            sanitizedUrl[j++] = url[i++]; //append the character
        }
    }

    sanitizedUrl[j] = '\0'; // null terminate the sanitized Url
    return sanitizedUrl;
}

int main() {

    printf("Enter the Url to sanitize: ");
    char url[2048];
    fgets(url, 2048, stdin); //get the url from stdin

    char* sanitizedUrl = urlSanitizer(url); //iteratively sanitize the url    

    printf("\nOriginal Url: %s", url);
    printf("\nSanitized Url: %s\n", sanitizedUrl);

    free(sanitizedUrl); //free the memory
    return 0;
}