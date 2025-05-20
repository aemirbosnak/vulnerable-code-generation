//FormAI DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
/*
 *  This program parses Apache log files and calculates various statistics.
 *  Input: Apache log file.
 *  Output: Various statistics about the log file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to check if a character is a space or not.
bool is_space(char c) {
    return (c == ' ' || c == '\t');
}

int main(int argc, char *argv[]) {

    // Check if file argument was provided.
    if (argc != 2) {
        printf("Usage: ./log_parser <apache_log_file>\n");
        return EXIT_FAILURE;
    }

    // Open the file argument provided.
    FILE *log_file;
    log_file = fopen(argv[1], "r");

    // Check if file was opened successfully.
    if (log_file == NULL) {
        printf("Error opening file.\n");
        return EXIT_FAILURE;
    }

    // Initialize variables to store statistics.
    int total_requests = 0;
    int total_data_transferred = 0;
    int total_successful_requests = 0;
    int total_failed_requests = 0;
    int total_unique_visitors = 0;

    // Initialize variables for parsing log file.
    char line[1024];
    char ip_address[16];
    char request_status[4];
    char transfer_size[16];
    char request_method[16];
    char request_uri[1024];
    char *tok;

    // Parse log file line by line.
    while (fgets(line, sizeof(line), log_file) != NULL) {
        
        // Ignore comment lines.
        if (line[0] == '#') {
            continue;
        }

        // Increment total number of requests.
        total_requests++;

        // Parse IP address from log entry.
        tok = strtok(line, " ");
        strcpy(ip_address, tok);

        // Get request method and URI.
        tok = strtok(NULL, "\"");
        sscanf(tok, "%s %s", request_method, request_uri);

        // Get request status.
        tok = strtok(NULL, " ");
        strcpy(request_status, tok);

        // Get transfer size.
        tok = strtok(NULL, " ");
        strcpy(transfer_size, tok);

        // Handle failed requests separately.
        if (strcmp(request_status, "200") != 0) {
            total_failed_requests++;
        } else {
            // Increment total number of successful requests and data transferred.
            total_successful_requests++;
            total_data_transferred += atoi(transfer_size);
        }

        // Parse remaining line elements to ignore unnecessary information.
        tok = strtok(NULL, "\"");
        tok = strtok(NULL, "\n");

    }

    // Close log file.
    fclose(log_file);

    // Print statistics.
    printf("Total requests: %d\n", total_requests);
    printf("Total data transferred: %d bytes\n", total_data_transferred);
    printf("Total successful requests: %d\n", total_successful_requests);
    printf("Total failed requests: %d\n", total_failed_requests);

    // Parse log file again to find unique visitors.
    log_file = fopen(argv[1], "r");
    int unique_ips[total_successful_requests];
    int num_unique_ips = 0;

    while (fgets(line, sizeof(line), log_file) != NULL) {
        
        // Ignore comment lines.
        if (line[0] == '#') {
            continue;
        }

        // Parse IP address from log entry.
        tok = strtok(line, " ");
        strcpy(ip_address, tok);

        // Check if IP address has already been counted as a unique visitor.
        bool found = false;
        for (int i = 0; i < num_unique_ips; i++) {
            if (strcmp(unique_ips[i], ip_address) == 0) {
                found = true;
                break;
            }
        }

        // If IP address was not found, increment number of unique visitors and add IP address to list.
        if (!found) {
            unique_ips[num_unique_ips] = ip_address;
            num_unique_ips++;
        }

    }

    // Increment total number of unique visitors.
    total_unique_visitors = num_unique_ips;

    // Print total number of unique visitors.
    printf("Total unique visitors: %d\n", total_unique_visitors);

    // Exit the program.
    return EXIT_SUCCESS;
}