//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LENGTH 1000
#define MAX_IP_LENGTH 16
#define THRESHOLD 5

typedef struct {
    char ip[MAX_IP_LENGTH];
    time_t timestamp;
    int count;
} LogEntry;

int main() {
    char input[MAX_LOG_LENGTH];
    LogEntry logs[100];
    int num_logs = 0;
    
    while (fgets(input, MAX_LOG_LENGTH, stdin) != NULL) {
        char* ip = strtok(input, " ");
        time_t current_time = time(NULL);
        int i;
        int found_matching_log_entry = 0;
        
        for (i = 0; i < num_logs; i++) {
            if (strcmp(logs[i].ip, ip) == 0) {
                if (current_time - logs[i].timestamp < 60) {
                    logs[i].count++;
                    found_matching_log_entry = 1;
                    break;
                }
                else {
                    logs[i].count = 1;
                    logs[i].timestamp = current_time;
                    found_matching_log_entry = 1;
                    break;
                }
            }
        }
        
        if (!found_matching_log_entry) {
            LogEntry new_log_entry;
            strcpy(new_log_entry.ip, ip);
            new_log_entry.timestamp = current_time;
            new_log_entry.count = 1;
            logs[num_logs] = new_log_entry;
            num_logs++;
        }
        
        for (i = 0; i < num_logs; i++) {
            if (logs[i].count >= THRESHOLD) {
                printf("Intrusion detected from %s\n", logs[i].ip);
                break;
            }
        }
    }
    
    return 0;
}