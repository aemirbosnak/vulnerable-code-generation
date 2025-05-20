//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: secure
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Struct to represent a log entry
typedef struct log_entry {
    char source_ip[16];
    char message[100];
} log_entry;

//Struct to represent a suspicious activity detected
typedef struct suspicious_activity {
    char source_ip[16];
    char message[100];
    int count;
} suspicious_activity;

//Function to check if an IP address is valid
bool is_valid_ip(char* ip) {
    int num;
    char *token, *ptr;
    char copy_ip[16];
    strncpy(copy_ip, ip, 16);

    //Iterate through each token separated by '.'
    token = strtok(copy_ip, ".");
    while (token != NULL) {

        //Check if token is a number
        num = strtol(token, &ptr, 10);
        if (ptr == token || num < 0 || num > 255) {
            return false;
        }

        token = strtok(NULL, ".");
    }

    return true;
}

int main() {
    FILE *fp;
    char current_log_line[120];
    log_entry current_log_entry;
    suspicious_activity suspicious_activities[10];
    int num_suspicious_activities = 0;

    //Open log file
    fp = fopen("log_file.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    //Loop through each line of the log file
    while (fgets(current_log_line, 120, fp)) {
        //Tokenize the current line to extract source IP and message
        char *token;
        token = strtok(current_log_line, " ");
        strncpy(current_log_entry.source_ip, token, 16);
        token = strtok(NULL, "\n");
        strncpy(current_log_entry.message, token, 100);

        //Check if source IP is valid
        if (!is_valid_ip(current_log_entry.source_ip)) {
            printf("Invalid IP: %s\n", current_log_entry.source_ip);
            continue;
        }

        bool found_match = false;
        int i;
        //Check if the current log entry matches any of the suspicious activities
        for (i = 0; i < num_suspicious_activities; i++) {
            if (strcmp(current_log_entry.source_ip, suspicious_activities[i].source_ip) == 0 &&
                strcmp(current_log_entry.message, suspicious_activities[i].message) == 0) {
                suspicious_activities[i].count++;
                found_match = true;
                break;
            }
        }

        //If the current log entry does not match any of the suspicious activities, add it to the list
        if (!found_match) {
            strncpy(suspicious_activities[num_suspicious_activities].source_ip, current_log_entry.source_ip, 16);
            strncpy(suspicious_activities[num_suspicious_activities].message, current_log_entry.message, 100);
            suspicious_activities[num_suspicious_activities].count = 1;
            num_suspicious_activities++;
        }

    }

    fclose(fp);

    //Print out any suspicious activities that were found
    printf("Suspicious activities detected:\n");
    int i;
    for (i = 0; i < num_suspicious_activities; i++) {
        if (suspicious_activities[i].count >= 3) {
            printf("Source IP: %s, Message: %s, Count: %d\n", suspicious_activities[i].source_ip,
                    suspicious_activities[i].message, suspicious_activities[i].count);
        }
    }

    return 0;
}