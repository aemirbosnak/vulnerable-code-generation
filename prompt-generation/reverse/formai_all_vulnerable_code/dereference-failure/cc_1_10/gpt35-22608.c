//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct log_entry { // Define a struct to hold the logged messages
    char timestamp[20];
    char ip_address[20];
    char message[100];
};

struct log_entry parse_log_entry(char *line) { // Function to parse a log entry
    struct log_entry entry;
    char *token;

    token = strtok(line, " "); // Parse timestamp
    strcpy(entry.timestamp, token);

    token = strtok(NULL, " "); // Parse IP address
    strcpy(entry.ip_address, token);

    token = strtok(NULL, " "); // Parse message
    while (*token == ' ') { // Ignore excess spaces at the beginning of the message
        token++;
    }
    strcpy(entry.message, token);

    return entry;
}

int main() {
    FILE *logfile;
    char line[150];
    struct log_entry entry;
    int count = 0;

    logfile = fopen("logfile.txt", "r"); // Open log file for reading
    if (logfile == NULL) {
        perror("Unable to open logfile");
        return 1;
    }

    while (fgets(line, sizeof(line), logfile) != NULL) { // Read each line of the log file
        entry = parse_log_entry(line); // Parse the log entry

        // Check for an attack
        if (strstr(entry.message, "Unauthorized access attempt") != NULL) {
            printf("Possible intrusion detected at %s from %s\n", entry.timestamp, entry.ip_address);
            count++;
        }
    }

    if (count == 0) { // No intrusions detected
        printf("No intrusion attempts found\n");
    }

    fclose(logfile); // Close log file

    return 0;
}