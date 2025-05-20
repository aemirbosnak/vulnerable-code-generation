//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Cyberpunk-styled function names
void hack_url(char *url);
bool is_safe(char *url);
void print_warning(char *url);
void print_safe(char *url);

int main() {
    // Declare variables
    char url[256];
    bool safe;

    // Get the URL from the user
    printf("Enter the URL to be scanned: ");
    scanf("%s", url);

    // Hack the URL
    hack_url(url);

    // Check if the URL is safe
    safe = is_safe(url);

    // Print the results
    if (safe) {
        print_safe(url);
    } else {
        print_warning(url);
    }

    return 0;
}

void hack_url(char *url) {
    // Convert the URL to lowercase
    for (int i = 0; i < strlen(url); i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any leading or trailing whitespace
    while (isspace(url[0])) {
        url++;
    }

    while (isspace(url[strlen(url) - 1])) {
        url[strlen(url) - 1] = '\0';
    }

    // Remove any double slashes
    while (strstr(url, "//") != NULL) {
        char *double_slash = strstr(url, "//");
        memmove(double_slash, double_slash + 1, strlen(double_slash));
    }

    // Remove any trailing slashes
    while (url[strlen(url) - 1] == '/') {
        url[strlen(url) - 1] = '\0';
    }
}

bool is_safe(char *url) {
    // Check for any known dangerous characters
    char *dangerous_chars = "<>&\"'";
    for (int i = 0; i < strlen(dangerous_chars); i++) {
        if (strchr(url, dangerous_chars[i]) != NULL) {
            return false;
        }
    }

    // Check for any known dangerous words
    char *dangerous_words[] = {"script", "alert", "eval", "javascript"};
    for (int i = 0; i < sizeof(dangerous_words) / sizeof(char *); i++) {
        if (strstr(url, dangerous_words[i]) != NULL) {
            return false;
        }
    }

    // The URL is safe
    return true;
}

void print_warning(char *url) {
    printf("WARNING: The URL '%s' is not safe.\n", url);
}

void print_safe(char *url) {
    printf("The URL '%s' is safe.\n", url);
}