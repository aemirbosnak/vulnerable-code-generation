//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_RULES 5
#define BUFFER_SIZE 1024

typedef struct {
    char ip_address[16];
    int allowed; // 1 for allowed, 0 for blocked
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void thank_user() {
    printf("Thank you for using this simple C Firewall program!\n");
    printf("We appreciate your efforts to keep your system safe!\n");
}

void initialize_rules() {
    strcpy(rules[0].ip_address, "192.168.1.1");
    rules[0].allowed = 1;
    strcpy(rules[1].ip_address, "192.168.1.2");
    rules[1].allowed = 1;
    strcpy(rules[2].ip_address, "10.0.0.3");
    rules[2].allowed = 0; // Blocked
    strcpy(rules[3].ip_address, "172.16.0.4");
    rules[3].allowed = 1;
    strcpy(rules[4].ip_address, "10.1.1.5");
    rules[4].allowed = 0; // Blocked
    rule_count = 5;
}

int check_rule(char *ip_address) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip_address, ip_address) == 0) {
            return rules[i].allowed;
        }
    }
    return 1; // Allow by default if no rules match
}

void log_access(char *ip_address, int allowed) {
    FILE *logFile = fopen("firewall_log.txt", "a");
    if (logFile == NULL) {
        printf("Failed to open log file. Please check permissions.\n");
        return;
    }
    if (allowed) {
        fprintf(logFile, "Allowed access from: %s\n", ip_address);
    } else {
        fprintf(logFile, "Blocked access from: %s\n", ip_address);
    }
    fclose(logFile);
}

void start_firewall(int port) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    thank_user();
    while (1) {
        printf("Waiting for a connection...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char *ip_address = inet_ntoa(address.sin_addr);
        int allowed = check_rule(ip_address);
        log_access(ip_address, allowed);

        if (allowed) {
            printf("Connection accepted from %s\n", ip_address);
            const char *response = "Connection allowed! Welcome!\n";
            send(new_socket, response, strlen(response), 0);
        } else {
            printf("Connection blocked from %s\n", ip_address);
            const char *response = "Connection blocked! Access denied!\n";
            send(new_socket, response, strlen(response), 0);
        }
        close(new_socket);
    }
}

int main() {
    initialize_rules();
    start_firewall(8080);
    return 0;
}