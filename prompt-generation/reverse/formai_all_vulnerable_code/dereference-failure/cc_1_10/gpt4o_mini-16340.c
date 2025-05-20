//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFFER 1024
#define URL_LENGTH 256

// Function prototypes
void load_web_page(const char *url);
void parse_page(const char *content);
void display_help();

int main(int argc, char *argv[]) {
    char url[URL_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        display_help();
        return EXIT_FAILURE;
    }
    
    // Copy provided URL and load the web page
    strncpy(url, argv[1], URL_LENGTH - 1);
    url[URL_LENGTH - 1] = '\0'; // Ensure null-termination
    
    printf("Fetching web page from: %s\n", url);
    load_web_page(url);

    return EXIT_SUCCESS;
}

void load_web_page(const char *url) {
    int pipe_fd[2]; // For creating a pipe
    pid_t pid;
    char buffer[MAX_BUFFER];
    ssize_t bytes_read;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process to run curl
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        // Close reading end of the pipe
        close(pipe_fd[0]);
        
        // Redirect STDOUT to the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]); // Close original descriptor
        
        // Execute the curl command to fetch the web page
        execlp("curl", "curl", "-s", url, NULL);
        
        // If exec fails
        perror("execlp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Close writing end of the pipe
        close(pipe_fd[1]);
        
        // Read from the pipe
        printf("Content of the web page:\n");
        while ((bytes_read = read(pipe_fd[0], buffer, MAX_BUFFER - 1)) > 0) {
            buffer[bytes_read] = '\0'; // Null-terminate the read buffer
            parse_page(buffer);
        }

        if (bytes_read == -1) {
            perror("read");
        }
        
        close(pipe_fd[0]); // Close reading end after done
        wait(NULL); // Wait for the child process to finish
    }
}

void parse_page(const char *content) {
    // A simple parser logic (very basic)
    // In a real plugin, you could use regex or HTML parsers
    printf("Incoming Content: \n%s\n", content);
    
    // Let's say we just want to count words
    int word_count = 0;
    const char *p = content;
    
    while (*p) {
        while (*p == ' ' || *p == '\n' || *p == '\t') {
            p++;
        }
        if (*p) {
            word_count++;
            while (*p && *p != ' ' && *p != '\n' && *p != '\t') {
                p++;
            }
        }
    }
    
    printf("Total words found: %d\n", word_count);
}

void display_help() {
    printf("Example usage:\n");
    printf("  ./browser_plugin http://example.com\n");
    printf("This command will fetch the web page and display its content along with word count.\n");
    printf("Make sure you have curl available on your system.\n");
}