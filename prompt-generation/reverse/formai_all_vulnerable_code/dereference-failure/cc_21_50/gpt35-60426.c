//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_IP_SIZE 16
#define MAX_MAC_SIZE 18
#define MAX_PORT_SIZE 6

struct log_data {
    char timestamp[MAX_INPUT_SIZE];
    char ip[MAX_IP_SIZE];
    char mac[MAX_MAC_SIZE];
    char port[MAX_PORT_SIZE];
    char message[MAX_INPUT_SIZE];
};

int main(int argc, char *argv[]) {
    FILE *input_file;
    char input_line[MAX_INPUT_SIZE];
    struct log_data log_array[MAX_INPUT_SIZE];
    int array_size = 0;
    int i, j;
    int intrusions_found = 0;

    // Check arguments
    if (argc != 2) {
        printf("Usage: %s input_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    // Parse input file
    while (fgets(input_line, MAX_INPUT_SIZE, input_file) != NULL) {
        char *token;
        struct log_data log_entry;

        // Parse timestamp
        token = strtok(input_line, ",");
        strcpy(log_entry.timestamp, token);

        // Parse IP address
        token = strtok(NULL, ",");
        strcpy(log_entry.ip, token);
        if (strlen(log_entry.ip) != MAX_IP_SIZE - 1) {
            printf("Invalid IP address: %s\n", log_entry.ip);
            exit(EXIT_FAILURE);
        }

        // Parse MAC address
        token = strtok(NULL, ",");
        strcpy(log_entry.mac, token);
        if (strlen(log_entry.mac) != MAX_MAC_SIZE - 1) {
            printf("Invalid MAC address: %s\n", log_entry.mac);
            exit(EXIT_FAILURE);
        }

        // Parse port
        token = strtok(NULL, ",");
        strcpy(log_entry.port, token);
        if (strlen(log_entry.port) != MAX_PORT_SIZE - 1) {
            printf("Invalid port: %s\n", log_entry.port);
            exit(EXIT_FAILURE);
        }

        // Parse message
        token = strtok(NULL, "\n");
        strcpy(log_entry.message, token);

        // Add entry to array
        log_array[array_size++] = log_entry;
    }

    // Close input file
    fclose(input_file);

    // Detect intrusions
    for (i = 0; i < array_size; i++) {
        struct log_data log_entry = log_array[i];

        // Check for multiple failed login attempts from the same IP address
        if (strstr(log_entry.message, "Failed password") != NULL &&
            strstr(log_entry.message, "from invalid user") == NULL &&
            strstr(log_entry.message, "invalid user") == NULL) {
            int num_failed_attempts = 1;
            for (j = i+1; j < array_size; j++) {
                struct log_data next_log_entry = log_array[j];
                if (strcmp(next_log_entry.ip, log_entry.ip) == 0 &&
                    strstr(next_log_entry.message, "Failed password") != NULL &&
                    strstr(next_log_entry.message, "from invalid user") == NULL &&
                    strstr(next_log_entry.message, "invalid user") == NULL) {
                    num_failed_attempts++;
                }
            }
            if (num_failed_attempts >= 5) {
                printf("Intrusion detected: %s attempted to log in from %s more than 5 times\n", log_entry.ip, log_entry.timestamp);
                intrusions_found++;
            }
        }

        // Check for SSH connection attempts from unfamiliar MAC addresses
        if (strstr(log_entry.message, "Accepted") != NULL &&
            strstr(log_entry.message, "SSH") != NULL) {
            for (j = i+1; j < array_size; j++) {
                struct log_data next_log_entry = log_array[j];
                if (strcmp(next_log_entry.ip, log_entry.ip) == 0 &&
                    strcmp(next_log_entry.port, log_entry.port) == 0 &&
                    strcmp(next_log_entry.message, log_entry.message) != 0 &&
                    strcmp(next_log_entry.mac, log_entry.mac) != 0) {
                    printf("Intrusion detected: %s attempted to connect to SSH on %s from an unfamiliar device with MAC address %s\n", log_entry.ip, log_entry.timestamp, next_log_entry.mac);
                    intrusions_found++;
                }
            }
        }
    }

    // Print summary
    if (intrusions_found > 0) {
        printf("%d intrusions found.\n", intrusions_found);
    } else {
        printf("No intrusions detected.\n");
    }

    return 0;
}