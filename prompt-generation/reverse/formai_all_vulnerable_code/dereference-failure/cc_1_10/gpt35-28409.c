//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold log details
struct LogDetails {
    char date[11];
    char time[9];
    char ip_address[16];
    char method[8];
    char url[256];
    int status_code;
};

int main() {
    // Open the log file
    FILE *log_file = fopen("example_access.log", "r");
    
    // If file could not be opened
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
    
    // Declare some counters and temporary variables
    int total_requests = 0, unique_ips = 0, successful_requests = 0, total_data_sent = 0;
    char current_date[11], current_ip[16];
    
    // Read each line of the file
    char line[1024];
    while (fgets(line, 1024, log_file)) {
        // Parse the log line into the LogDetails struct
        struct LogDetails info;
        sscanf(line, "%s %s %s %s %s %d", info.ip_address, "-", "-", info.date, info.time, &info.status_code);
        char *url = strtok(line, "\"");
        strcpy(info.method, strtok(url, " "));
        strcpy(info.url, strtok(NULL, " "));
        
        // Check if this is a new date
        if (strcmp(current_date, info.date) != 0) {
            // Print the stats for the previous day
            printf("Date: %s\n", current_date);
            printf("Total Requests: %d\n", total_requests);
            printf("Unique IPs: %d\n", unique_ips);
            printf("Successful Requests: %d\n", successful_requests);
            printf("Total Data Sent: %d bytes\n\n", total_data_sent);
            
            // Reset the counters for the new day
            total_requests = 0;
            unique_ips = 0;
            successful_requests = 0;
            total_data_sent = 0;
        }
        
        // Increment counters
        total_requests++;
        total_data_sent += 1000; // Simulate data sent
        
        // Check if this is a new IP address
        if (strcmp(current_ip, info.ip_address) != 0) {
            unique_ips++;
            
            // Update the current IP address
            strcpy(current_ip, info.ip_address);
        }
        
        // Check if the request was successful
        if (info.status_code >= 200 && info.status_code <= 299) {
            successful_requests++;
        }
        
        // Update the current date
        strcpy(current_date, info.date);
    }
    
    // Print the stats for the final day
    printf("Date: %s\n", current_date);
    printf("Total Requests: %d\n", total_requests);
    printf("Unique IPs: %d\n", unique_ips);
    printf("Successful Requests: %d\n", successful_requests);
    printf("Total Data Sent: %d bytes\n", total_data_sent);
    
    // Close the log file
    fclose(log_file);
    
    // Exit the program
    return 0;
}