//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to convert a string to uppercase */
char* to_uppercase(char* str) {
    char* result = malloc(strlen(str) + 1);
    int i;
    for(i = 0; str[i]; i++) {
        result[i] = toupper(str[i]);
    }
    result[i] = '\0';
    return result;
}

/* Function to append a string to another string */
char* append_string(char* str1, char* str2) {
    char* result = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

/* Function to extract the domain from a URL */
char* extract_domain(char* url) {
    char* protocol;
    char* domain;
    char* path;
    
    /* If the URL has a protocol, skip it */
    if(strncmp(url, "http://", 7) == 0) {
        protocol = "http://";
        url += 7;
    } else if(strncmp(url, "https://", 8) == 0) {
        protocol = "https://";
        url += 8;
    } else {
        protocol = "";
    }
    
    /* Extract the domain */
    domain = strtok(url, "/");
    path = strtok(NULL, "");
    if(path != NULL) {
        domain = append_string(domain, "/");
        domain = append_string(domain, path);
    }
    
    return domain;
}

/* Function to print a message to the console */
void console_log(char* message) {
    printf("%s\n", message);
}

/* Function to handle a click event */
void handle_click(char* url) {
    char* domain = extract_domain(url);
    char* uppercase_domain = to_uppercase(domain);
    console_log(uppercase_domain);
    free(domain);
    free(uppercase_domain);
}

/* Function to handle a page load event */
void handle_load(char* url) {
    char* domain = extract_domain(url);
    console_log(domain);
    free(domain);
}

/* Main function */
int main() {
    char* url = "https://www.google.com/search?q=hello+world";
    
    handle_click(url);
    handle_load(url);
    
    return 0;
}