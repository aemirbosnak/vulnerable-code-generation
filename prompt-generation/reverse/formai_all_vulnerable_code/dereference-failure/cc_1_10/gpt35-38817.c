//FormAI DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 200

void print_usage() {
    printf("Usage: log_analysis filename.log\n");
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LENGTH];
    char *token;
    char method[MAX_LENGTH];
    char path[MAX_LENGTH];
    char protocol[MAX_LENGTH];

    int total_lines = 0;
    int get_requests = 0;
    int post_requests = 0;
    int put_requests = 0;
    int delete_requests = 0;
    int other_requests = 0;

    if (argc < 2 || argc > 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        total_lines++;

        // Get request method, path, and protocol
        token = strtok(line, " ");
        strncpy(method, token, MAX_LENGTH);
        token = strtok(NULL, " ");
        strncpy(path, token, MAX_LENGTH);
        token = strtok(NULL, " ");
        strncpy(protocol, token, MAX_LENGTH);

        // Determine number of requests by method
        if (strcmp(method, "GET") == 0) {
            get_requests++;
        } else if (strcmp(method, "POST") == 0) {
            post_requests++;
        } else if (strcmp(method, "PUT") == 0) {
            put_requests++;
        } else if (strcmp(method, "DELETE") == 0) {
            delete_requests++;
        } else {
            other_requests++;
        }
    }

    fclose(fp);

    printf("Total lines: %d\n", total_lines);
    printf("GET requests: %d\n", get_requests);
    printf("POST requests: %d\n", post_requests);
    printf("PUT requests: %d\n", put_requests);
    printf("DELETE requests: %d\n", delete_requests);
    printf("Other requests: %d\n", other_requests);

    return 0;
}