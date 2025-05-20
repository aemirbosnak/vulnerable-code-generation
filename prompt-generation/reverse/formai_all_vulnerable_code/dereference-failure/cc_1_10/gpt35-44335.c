//FormAI DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
// C Log Analysis Program
// Written in a Claude Shannon style by Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * Struct representing a log entry
 * Contains the IP address of the client and the timestamp of the request
 */
typedef struct LogEntry {
    char ip_address[16];
    char timestamp[20];
} LogEntry;

/**
 * Function to parse a log file and extract the IP addresses and timestamps
 * Returns an array of LogEntry structs
 */
LogEntry* parse_log_file(char* filename, int* num_entries) {
    FILE* log_file = fopen(filename, "r");

    if (!log_file) {
        perror("Error opening log file");
        return NULL;
    }

    // Count the number of entries in the file
    *num_entries = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        (*num_entries)++;
    }

    // Allocate memory for the array of entries
    LogEntry* entries = malloc(sizeof(LogEntry) * (*num_entries));

    // Reset the file position to the beginning of the file
    fseek(log_file, 0, SEEK_SET);

    // Loop through the file and extract the IP addresses and timestamps
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        char* token = strtok(line, " ");
        strncpy(entries[i].ip_address, token, 16);

        token = strtok(NULL, " ");
        token = strtok(NULL, " ");
        strncpy(entries[i].timestamp, token+1, 20);

        i++;
    }

    fclose(log_file);

    return entries;
}

/**
 * Function to count the number of requests from each IP address
 * Returns an array of integers representing the number of requests from each IP address
 */
int* count_ip_addresses(LogEntry* entries, int num_entries, int* num_unique) {
    int MAX_IP_ADDRESSES = num_entries;
    char** ip_addresses = malloc(sizeof(char*) * MAX_IP_ADDRESSES);

    // Loop through the list of entries and count the number of unique IP addresses
    *num_unique = 0;
    for (int i = 0; i < num_entries; i++) {
        int is_unique = 1;
        for (int j = 0; j < *num_unique; j++) {
            if (strcmp(entries[i].ip_address, ip_addresses[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            ip_addresses[*num_unique] = entries[i].ip_address;
            (*num_unique)++;
        }
    }

    // Allocate memory for the array of IP address counts
    int* ip_counts = calloc(*num_unique, sizeof(int));

    // Loop through the list of entries and count the number of requests from each IP address
    for (int i = 0; i < num_entries; i++) {
        for (int j = 0; j < *num_unique; j++) {
            if (strcmp(entries[i].ip_address, ip_addresses[j]) == 0) {
                ip_counts[j]++;
                break;
            }
        }
    }

    free(ip_addresses);

    return ip_counts;
}

/**
 * Function to calculate the Shannon entropy of a list of values
 * Used to measure the diversity of client IP addresses in the log file
 */
double shannon_entropy(int* values, int num_values) {
    double entropy = 0.0;

    // Calculate the total number of requests
    int total_requests = 0;
    for (int i = 0; i < num_values; i++) {
        total_requests += values[i];
    }

    // Loop through the list of values and calculate the entropy
    for (int i = 0; i < num_values; i++) {
        double p = (double) values[i] / total_requests;
        entropy -= p * log2(p);
    }

    return entropy;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: log_analyzer <log_file>\n");
        return 1;
    }

    // Parse the log file
    int num_entries;
    LogEntry* entries = parse_log_file(argv[1], &num_entries);

    // Count the number of requests from each IP address
    int num_unique;
    int* ip_counts = count_ip_addresses(entries, num_entries, &num_unique);

    // Calculate the Shannon entropy of the client IP addresses
    double entropy = shannon_entropy(ip_counts, num_unique);

    printf("Number of unique IP addresses: %d\n", num_unique);
    printf("Shannon entropy of IP addresses: %f\n", entropy);

    free(entries);
    free(ip_counts);

    return 0;
}