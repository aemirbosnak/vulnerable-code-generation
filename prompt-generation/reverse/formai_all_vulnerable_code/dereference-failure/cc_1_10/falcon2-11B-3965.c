//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to clean up a HTML string
char* cleanHTML(char* html) {
    // Find the first occurrence of the opening tag
    char* start_tag = strstr(html, "<html");
    if(start_tag == NULL) {
        return NULL;
    }
    
    // Find the last occurrence of the closing tag
    char* end_tag = strstr(html, "</html");
    if(end_tag == NULL) {
        return NULL;
    }
    
    // Find the opening tag
    char* open_tag = strstr(html, "<");
    if(open_tag == NULL) {
        return NULL;
    }
    
    // Find the closing tag
    char* close_tag = strstr(html, ">");
    if(close_tag == NULL) {
        return NULL;
    }
    
    // Get the length of the HTML string
    int len = strlen(html);
    
    // Initialize the result string
    char* result = (char*)malloc(len + 1);
    
    // Copy the HTML string to the result string
    strncpy(result, html, len);
    
    // Find the first opening tag
    int i = 0;
    while(i < len) {
        if(result[i] == '<') {
            break;
        }
        i++;
    }
    
    // Find the closing tag
    i = len - 1;
    while(i >= 0) {
        if(result[i] == '>') {
            break;
        }
        i--;
    }
    
    // Replace the opening tag with a newline character
    result[i] = '\n';
    
    // Replace the closing tag with a newline character
    i++;
    result[i] = '\n';
    
    // Replace the remaining content of the HTML string with newline characters
    for(int j = i + 1; j < len; j++) {
        if(result[j] == '<') {
            break;
        }
        result[j] = '\n';
    }
    
    // Append the closing tag to the result string
    strcat(result, "</html>");
    
    // Return the cleaned up HTML string
    return result;
}

int main() {
    char html[] = "<html><body><h1>Hello, World!</h1></body></html>";
    char* cleaned = cleanHTML(html);
    if(cleaned!= NULL) {
        printf("%s\n", cleaned);
        free(cleaned);
    } else {
        printf("Error cleaning HTML string\n");
    }
    return 0;
}