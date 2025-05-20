//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024
#define SAFE_URL "http://safe.link/"

void render_banner() {
    printf("============================================\n");
    printf("   Welcome to the Url Sanitizer of the\n");
    printf("     Great Kingdom of C Programming\n");
    printf("============================================\n");
}

void cleanse_url(char *url) {
    char *ptr = url;
    char *cleaned_url = (char *)malloc(MAX_LENGTH * sizeof(char));
    char *cleaned_ptr = cleaned_url;

    while (*ptr != '\0') {
        if (isalnum((unsigned char)*ptr) || 
            *ptr == '.' || 
            *ptr == '/' || 
            *ptr == ':' || 
            *ptr == '-' || 
            *ptr == '_' || 
            *ptr == '~') {
            *cleaned_ptr++ = *ptr;
        } else {
            printf("A foul character '%c' was thwarted!\n", *ptr);
        }
        ptr++;
    }
    *cleaned_ptr = '\0';

    // If the cleaned url is empty, revert to the safe site
    if (cleaned_url[0] == '\0') {
        strcpy(url, SAFE_URL);
        printf("No valid characters found! The brave knight redirected you to: %s\n", SAFE_URL);
    } else {
        strcpy(url, cleaned_url);
        printf("The url has been purified to: %s\n", url);
    }
    
    free(cleaned_url);
}

int main() {
    char url[MAX_LENGTH];

    render_banner();

    printf("Pray, enter the foreign URL to sanctify: ");
    fgets(url, sizeof(url), stdin);

    // Remove the newline character obtained from fgets
    size_t len = strlen(url);
    if (len > 0 && url[len - 1] == '\n') {
        url[len - 1] = '\0';
    }

    cleanse_url(url);

    printf("Thou may now proceed with thy clean link: %s\n", url);
    printf("Farewell, brave wanderer!\n");

    return 0;
}