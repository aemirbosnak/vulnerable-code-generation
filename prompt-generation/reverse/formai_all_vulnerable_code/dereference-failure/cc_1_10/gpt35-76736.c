//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void sanitize(char* url) {
    // Convert the URL to lowercase
    int len = strlen(url);
    for (int i = 0; i < len; i++) {
        url[i] = tolower(url[i]);
    }

    // Remove any trailing whitespace
    int idx = len - 1;
    while (isspace(url[idx])) {
        url[idx] = '\0';
        idx--;
     }

    // Check if the URL begins with "https://" or "http://"
    if (strncmp(url, "https://", 8) != 0 && strncmp(url, "http://", 7) != 0) {
        printf("Error: Invalid URL. URL must begin with either 'http://' or 'https://'\n");
        return;
    }

    // Remove any script tags
    char* script_start = strstr(url, "<script>");
    while (script_start != NULL) {
        char* script_end = strstr(script_start, "</script>");
        if (script_end != NULL) {
            memmove(script_start, script_end+9, strlen(script_end+9)+1);
        }
        script_start = strstr(url, "<script>");
    }

    // Remove any inline styles
    char* style_start = strstr(url, "style=");
    while (style_start != NULL) {
        int i = 0;
        while (style_start[i] != '>' && style_start[i] != '\0') {
            i++;
        }
        if (style_start[i] == '>') {
            memmove(style_start, style_start+i+1, strlen(style_start+i+1)+1);
        }
        style_start = strstr(url, "style=");
    }
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}