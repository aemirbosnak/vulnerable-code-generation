//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_RULES 100

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int allowed; // 1 for allow, 0 for deny
} FirewallRule;

FirewallRule rules[MAX_RULES];
int rule_count = 0;

void add_rule(const char *ip, int allowed) {
    if (rule_count < MAX_RULES) {
        strcpy(rules[rule_count].ip, ip);
        rules[rule_count].allowed = allowed;
        rule_count++;
    } else {
        printf("Max rule count reached.\n");
    }
}

int check_rule(const char *ip) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].ip, ip) == 0) {
            return rules[i].allowed;
        }
    }
    return -1; // No matching rule found
}

void load_rules() {
    add_rule("192.168.1.10", 1); // Example allow rule
    add_rule("192.168.1.20", 0); // Example deny rule
    // More rules can be added here
}

void handle_connection(int new_socket, struct sockaddr_in address) {
    char buffer[BUFFER_SIZE] = {0};
    char *ip = inet_ntoa(address.sin_addr);
    printf("Connection attempt from %s\n", ip);

    int rule_status = check_rule(ip);
    if (rule_status == 1) {
        printf("Allowing connection from %s\n", ip);
        const char *welcome_message = "Welcome to the server!\n";
        send(new_socket, welcome_message, strlen(welcome_message), 0);
    } else if (rule_status == 0) {
        printf("Denying connection from %s\n", ip);
        const char *deny_message = "Access denied!\n";
        send(new_socket, deny_message, strlen(deny_message), 0);
    } else {
        printf("No specific rule for %s, denying by default\n", ip);
        const char *deny_message = "Access denied!\n";
        send(new_socket, deny_message, strlen(deny_message), 0);
    }
    
    close(new_socket);
}

int main() {
    load_rules();

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Firewall server listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            continue;
        }
        handle_connection(new_socket, address);
    }

    close(server_fd);
    return 0;
}