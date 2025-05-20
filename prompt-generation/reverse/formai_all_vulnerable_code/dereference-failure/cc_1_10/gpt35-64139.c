//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove unwanted characters from URL
char* sanitize_url(char* url){
    // Variables
    int i, j;
    int len = strlen(url);
    char *new_url = (char*)malloc((len+1) * sizeof(char));   // Allocating memory for new URL string
    
    // Removing leading and trailing whitespaces
    while(isspace((unsigned char)*url)) url++;
    if (*url == 0) return NULL;
    char *end = url + strlen(url) - 1;
    while(end > url && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    
    // Removing unwanted characters
    for(i=0, j=0; i<len; i++){
        if(url[i] == '/' && url[i+1] == '/'){     // Removing double slashes
            // Skip the following character
            i++;
            continue;
        }
        else if(url[i] == '/'){     // Removing extra slashes
            if(new_url[j-1] == '/') continue;
        }
        else if(url[i] == '#'){     // Removing fragment identifier
            break;
        }
        // Validating character is ASCII and non-control character
        // Only allowing characters that are allowed in URL schemes (Refer to RFC 3986)
        // Valid characters are low case letters, upper case letters, numbers, and special characters (.-_~)
        if(url[i] <= 127 && isgraph((unsigned char)url[i])){
            new_url[j++] = url[i];
        }
    }
    new_url[j] = '\0';      // Null terminating the new URL string
    return new_url;
}

int main(){
    // Input URL
    char url[1000];
    printf("Enter URL: ");
    fgets(url, 1000, stdin);
    url[strcspn(url, "\n")] = 0;    // Removing newline character from input
    
    // Sanitizing URL
    char *sanitized_url = sanitize_url(url);
    
    // Printing sanitized URL
    if(sanitized_url == NULL) printf("URL invalid.");
    else printf("Sanitized URL: %s", sanitized_url);
    
    return 0;
}