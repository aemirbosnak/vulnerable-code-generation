//FormAI DATASET v1.0 Category: Firewall ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define MAX_IPS 100

typedef struct {
    int enabled;
    char ip[16];
} rule;

typedef struct {
    int num_rules;
    rule* rules;
} firewall;

firewall fw;

int load_config() {
    // Load configuration from file
    FILE* fp;
    fp = fopen("config.txt", "r");
    if (fp == NULL) {
        printf("Error opening config file: %s\n", strerror(errno));
        return -1;
    }

    char line[25];
    int rule_count = 0;
    while (fgets(line, 25, fp) != NULL) {
        if (rule_count == MAX_IPS) {
            printf("Error: too many rules specified in configuration file\n");
            return -1;
        }

        // Check if rule is enabled
        fw.rules[rule_count].enabled = atoi(strtok(line, " \n"));

        // Check IP
        char* ip = strtok(NULL, " \n");
        if (ip == NULL) {
            printf("Error: invalid IP specified in configuration file\n");
            return -1;
        }
        strcpy(fw.rules[rule_count].ip, ip);

        rule_count++;
    }

    fw.num_rules = rule_count;
    fclose(fp);
    return 0;
}

int is_blocked(char* ip) {
    // Check if IP matches a blocked rule
    for (int i = 0; i < fw.num_rules; i++) {
        if (fw.rules[i].enabled && strcmp(fw.rules[i].ip, ip) == 0) {
            // IP is blocked
            return 1;
        }
    }
    return 0;
}

int main() {
    // Load configuration
    fw.rules = malloc(MAX_IPS * sizeof(rule));
    memset(fw.rules, 0, MAX_IPS * sizeof(rule));
    if (load_config() < 0) {
        return 1;
    }

    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Bind to port 8080 and listen for incoming connections
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding to port: %s\n", strerror(errno));
        return 1;
    }
    if (listen(server_socket, 10) < 0) {
        printf("Error listening for incoming connections: %s\n", strerror(errno));
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket;
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket < 0) {
            printf("Error accepting incoming connection: %s\n", strerror(errno));
            continue;
        }

        // Get client IP
        char client_ip[16] = {0};
        inet_ntop(AF_INET, &(client_address.sin_addr), client_ip, sizeof(client_ip));

        if (is_blocked(client_ip)) {
            // Client IP is blocked, close connection and log message
            printf("Blocked connection from %s\n", client_ip);
            close(client_socket);
        } else {
            // Client is allowed, handle request
            // ...
        }
    }

    // Close socket and free firewall rules
    close(server_socket);
    free(fw.rules);

    return 0;
}