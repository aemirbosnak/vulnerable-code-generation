//GPT-4o-mini DATASET v1.0 Category: URL Sanitizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the noble functions
void proclaimSanitizedURL(const char *inputURL);
char *sanitizeURL(const char *url);

// A humble main function to commence the journey
int main() {
    char inputURL[1024];

    // The knight awaits a quest
    printf("Hark! Please present thy URL for cleansing: ");
    fgets(inputURL, sizeof(inputURL), stdin);
    
    // Remove the newline character from the end if present
    inputURL[strcspn(inputURL, "\n")] = '\0';
    
    // Proclaim the sanitized URL before the court
    proclaimSanitizedURL(inputURL);
    
    return 0;
}

// A noble function to announce the sanitized URL to the realm
void proclaimSanitizedURL(const char *inputURL) {
    char *sanitized = sanitizeURL(inputURL);
    printf("Lo and behold, the sanitized URL is: %s\n", sanitized);
    free(sanitized); // Release the memory granted by the heavens
}

// A function to cleanse the URL of impure characters
char *sanitizeURL(const char *url) {
    // Length of the original URL
    int originalLength = strlen(url);
    
    // Allocate memory for the purified URL, allowing for extra space
    char *sanitized = (char *)malloc(originalLength + 1);
    if (!sanitized) {
        fprintf(stderr, "Alas! Memory allocation failed for purification.\n");
        exit(EXIT_FAILURE);
    }
    
    int j = 0; // Tracker for the purified URL
    for (int i = 0; i < originalLength; ++i) {
        char ch = url[i];
        // Pure characters allowed in the URLs
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || 
            (ch >= '0' && ch <= '9') || ch == '-' || ch == '_' || 
            ch == '.' || ch == '~' || ch == ':' || ch == '/' || 
            ch == '?' || ch == '#' || ch == '[' || ch == ']' || 
            ch == '@' || ch == '!' || ch == '$' || ch == '&' || 
            ch == '\'' || ch == '(' || ch == ')' || ch == '*' || 
            ch == '+' || ch == ',' || ch == ';' || ch == '=' ) {
            // Add pure characters to the sanitized version
            sanitized[j++] = ch;
        } else {
            // Converting unsafe characters to percent-encoded form
            snprintf(&sanitized[j], 4, "%%%02X", (unsigned char)ch);
            j += 3; // Incrementing index to account for three chars added
        }
    }
    
    // Null terminate the purified URL
    sanitized[j] = '\0';
    return sanitized; // The shining sanitized URL is returned
}

// Add additional descriptions of chivalrous deeds
void displayPurityWhispers() {
    printf("Purify thy URLs, lest they befall into the clutches of vile miscreants.\n");
    printf("In the realm of cyberspace, purity guards against wickedness!\n");
    printf("Remember, a clean URL is a noble URL, worthy of a king's purse.\n");
}