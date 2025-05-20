//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define BACKLOG 5
#define MAX_CONNECTIONS 10
#define PORT 8080

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
    char *username;
    char *password;
};

struct firewall_rules {
    char *ip_address;
    int port;
    int protocol;
    char *action;
};

struct firewall_rule_node {
    struct firewall_rules rule;
    struct firewall_rule_node *next;
};

struct firewall_rule_list {
    struct firewall_rule_node *head;
    struct firewall_rule_node *tail;
};

// Function to create a new firewall rule
struct firewall_rules *new_firewall_rule(char *ip_address, int port, int protocol, char *action) {
    struct firewall_rules *rule = malloc(sizeof(struct firewall_rules));
    rule->ip_address = strdup(ip_address);
    rule->port = port;
    rule->protocol = protocol;
    rule->action = strdup(action);
    return rule;
}

// Function to create a new firewall rule node
struct firewall_rule_node *new_firewall_rule_node(struct firewall_rules *rule) {
    struct firewall_rule_node *node = malloc(sizeof(struct firewall_rule_node));
    node->rule = *rule;
    node->next = NULL;
    return node;
}

// Function to add a new firewall rule to the list
void add_firewall_rule(struct firewall_rule_list *list, struct firewall_rules *rule) {
    struct firewall_rule_node *node = new_firewall_rule_node(rule);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Function to check if a packet is allowed by the firewall
int is_packet_allowed(struct firewall_rule_list *list, struct sockaddr_in *addr, int port, int protocol) {
    struct firewall_rule_node *node = list->head;
    while (node != NULL) {
        if (strcmp(node->rule.ip_address, inet_ntoa(addr->sin_addr)) == 0 &&
            node->rule.port == port &&
            node->rule.protocol == protocol) {
            if (strcmp(node->rule.action, "allow") == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        node = node->next;
    }
    return 0;
}

// Function to start the firewall
void start_firewall(struct firewall_rule_list *list) {
    int sockfd, newsockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[1024];
    int n;

    // Create a new socket for the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (1) {
        // Accept a new connection
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Check if the packet is allowed by the firewall
        if (is_packet_allowed(list, &client_addr, PORT, IPPROTO_TCP)) {
            // If the packet is allowed, send a welcome message to the client
            n = sprintf(buffer, "Welcome to the server!\n");
            if (send(client_sockfd, buffer, n, 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }

            // Keep reading from the client until the client closes the connection
            while ((n = recv(client_sockfd, buffer, sizeof(buffer), 0)) > 0) {
                // Echo the data back to the client
                if (send(client_sockfd, buffer, n, 0) == -1) {
                    perror("send");
                    exit(EXIT_FAILURE);
                }
            }

            if (n == -1) {
                perror("recv");
                exit(EXIT_FAILURE);
            }
        } else {
            // If the packet is not allowed, send an error message to the client
            n = sprintf(buffer, "You are not allowed to access this server!\n");
            if (send(client_sockfd, buffer, n, 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        // Close the client socket
        close(client_sockfd);
    }

    // Close the server socket
    close(sockfd);
}

// Main function
int main() {
    // Create a new firewall rule list
    struct firewall_rule_list list;
    list.head = NULL;
    list.tail = NULL;

    // Add some firewall rules to the list
    add_firewall_rule(&list, new_firewall_rule("192.168.1.1", 80, IPPROTO_TCP, "allow"));
    add_firewall_rule(&list, new_firewall_rule("192.168.1.2", 443, IPPROTO_TCP, "allow"));
    add_firewall_rule(&list, new_firewall_rule("192.168.1.3", 22, IPPROTO_TCP, "deny"));

    // Start the firewall
    start_firewall(&list);

    return 0;
}