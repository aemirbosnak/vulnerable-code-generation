//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *ip_address;
    int num_attempts;
} User;

int main() {
    User *users = malloc(100 * sizeof(User));
    int num_users = 0;
    
    // Read in the log file
    FILE *log_file = fopen("intrusion.log", "r");
    char line[256];
    while (fgets(line, sizeof(line), log_file)) {
        // Parse the line to obtain IP address and action
        char *ip_address_token = strtok(line, " ");
        char *action_token = strtok(NULL, " ");
        
        // Check if the IP address is already in the users array
        int user_index = -1;
        for (int i = 0; i < num_users; i++) {
            if (strcmp(users[i].ip_address, ip_address_token) == 0) {
                user_index = i;
                break;
            }
        }
        
        // If the IP address is not in the users array, add it
        if (user_index == -1) {
            User new_user;
            new_user.ip_address = malloc(strlen(ip_address_token) + 1);
            strcpy(new_user.ip_address, ip_address_token);
            new_user.num_attempts = 0;
            users[num_users] = new_user;
            num_users++;
            user_index = num_users - 1;
        }
        
        // Increment the number of attempts for the user
        if (strcmp(action_token, "success") != 0) {
            users[user_index].num_attempts++;
        }
        
        // Check if user has exceeded threshold number of attempts
        if (users[user_index].num_attempts >= 5) {
            printf("INTRUSION DETECTED: %s\n", users[user_index].ip_address);
        }
    }
    
    // Free memory for users' IP addresses
    for (int i = 0; i < num_users; i++) {
        free(users[i].ip_address);
    }
    
    // Free memory for users array
    free(users);
    
    return 0;
}