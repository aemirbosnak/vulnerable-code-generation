//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line of input from the user
void read_line(char* line, int max_length) {
    printf("Enter thy words: ");
    fgets(line, max_length, stdin);
    line[strcspn(line, "\n")] = '\0';
}

// Function to print a message to the user
void print_message(const char* message) {
    printf("%s\n", message);
}

// Function to check if a string is a valid URL
int is_valid_url(const char* url) {
    char* protocol = strstr(url, "://");
    if (protocol == NULL || strstr(protocol, "http") == NULL) {
        return 0;
    }
    return 1;
}

// Function to open a URL in the default web browser
void open_url(const char* url) {
    char* command = malloc(strlen(url) + 20);
    sprintf(command, "xdg-open \"%s\"", url);
    system(command);
    free(command);
}

// Main function to run the program
int main() {
    char line[MAX_LINE_LENGTH];
    while (1) {
        read_line(line, MAX_LINE_LENGTH);
        if (strcmp(line, "exit") == 0) {
            break;
        }
        char* url = strtok(line, " ");
        if (is_valid_url(url)) {
            open_url(url);
        } else {
            print_message("Invalid URL");
        }
    }
    return 0;
}