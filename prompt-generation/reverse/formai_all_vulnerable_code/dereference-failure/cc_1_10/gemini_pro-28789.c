//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Macro to make our lives easier
#define HAPPY_FW_ERROR(msg) { perror(msg); exit(1); }

// Our happy firewall struct
typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
    char *rules;
} happy_firewall;

// Initialize our happy firewall
happy_firewall *happy_firewall_init(char *ip_address, int port, char *rules) {
    // Allocate memory for our happy firewall
    happy_firewall *fw = malloc(sizeof(happy_firewall));
    if (fw == NULL) HAPPY_FW_ERROR("malloc");

    // Create a socket for our happy firewall
    fw->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (fw->sockfd == -1) HAPPY_FW_ERROR("socket");

    // Set the server address for our happy firewall
    fw->server_addr.sin_family = AF_INET;
    fw->server_addr.sin_port = htons(port);
    fw->server_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Set the firewall rules for our happy firewall
    fw->rules = malloc(strlen(rules)+1);
    if (fw->rules == NULL) HAPPY_FW_ERROR("malloc");
    strcpy(fw->rules, rules);

    // Return our happy firewall
    return fw;
}

// Start our happy firewall
int happy_firewall_start(happy_firewall *fw) {
    // Connect our happy firewall to the server
    if (connect(fw->sockfd, (struct sockaddr *) &fw->server_addr, sizeof(fw->server_addr)) == -1) HAPPY_FW_ERROR("connect");

    // Send the firewall rules to the server
    if (send(fw->sockfd, fw->rules, strlen(fw->rules), 0) == -1) HAPPY_FW_ERROR("send");

    // Start listening for incoming connections
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(fw->sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd == -1) HAPPY_FW_ERROR("accept");

        // Get the client's IP address
        char *client_ip = inet_ntoa(client_addr.sin_addr);

        // Check the firewall rules to see if the client is allowed to connect
        int allowed = 0;
        char *rule = strtok(fw->rules, ",");
        while (rule != NULL) {
            if (strcmp(rule, client_ip) == 0) {
                allowed = 1;
                break;
            }
            rule = strtok(NULL, ",");
        }

        // If the client is not allowed to connect, send an error message
        if (!allowed) {
            char *error_msg_denied = "Connection denied: You are not allowed to connect to this server.\n";
            if (send(client_sockfd, error_msg_denied, strlen(error_msg_denied), 0) == -1) HAPPY_FW_ERROR("send");
            close(client_sockfd);
            continue;
        }

        // If the client is allowed to connect, send a welcome message
        char *welcome_msg = "Connection allowed: Welcome to the server.\n";
        if (send(client_sockfd, welcome_msg, strlen(welcome_msg), 0) == -1) HAPPY_FW_ERROR("send");

        // Close the client socket
        close(client_sockfd);
    }

    // Close our happy firewall
    close(fw->sockfd);

    // Return 0 if everything went well
    return 0;
}

// Stop our happy firewall
int happy_firewall_stop(happy_firewall *fw) {
    // Close our happy firewall
    close(fw->sockfd);

    // Free the memory for our happy firewall
    free(fw);

    // Return 0 if everything went well
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <ip_address> <port> <rules>\n", argv[0]);
        return 1;
    }

    // Initialize our happy firewall
    happy_firewall *fw = happy_firewall_init(argv[1], atoi(argv[2]), argv[3]);

    // Start our happy firewall
    if (happy_firewall_start(fw) != 0) {
        printf("Error starting the firewall.\n");
        return 1;
    }

    // Stop our happy firewall
    if (happy_firewall_stop(fw) != 0) {
        printf("Error stopping the firewall.\n");
        return 1;
    }

    // Return 0 if everything went well
    return 0;
}