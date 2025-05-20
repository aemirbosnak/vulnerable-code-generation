//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

struct firewall_rule {
    char *src_ip;
    char *dst_ip;
    int src_port;
    int dst_port;
    char *protocol;
};

struct firewall {
    struct firewall_rule *rules;
    int num_rules;
};

struct firewall_state {
    struct firewall *firewall;
    int sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
};

void sigint_handler(int signum) {
    printf("Received SIGINT, exiting.\n");
    exit(0);
}

int main() {
    struct firewall_rule rules[] = {
        {"192.168.1.1", "192.168.1.2", 80, 80, "tcp"},
        {"192.168.1.2", "192.168.1.1", 80, 80, "tcp"},
        {"192.168.1.3", "192.168.1.1", 80, 80, "tcp"},
        {"192.168.1.4", "192.168.1.1", 80, 80, "tcp"},
        {"192.168.1.5", "192.168.1.1", 80, 80, "tcp"},
    };

    struct firewall firewall = {
        .rules = rules,
        .num_rules = sizeof(rules) / sizeof(struct firewall_rule),
    };

    struct firewall_state state = {
        .firewall = &firewall,
        .sockfd = -1,
        .server_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            .sin_addr = {
                .s_addr = htonl(INADDR_ANY),
            },
        },
        .client_addr = {
            .sin_family = AF_INET,
            .sin_port = 0,
            .sin_addr = {
                .s_addr = 0,
            },
        },
        .client_addr_len = sizeof(struct sockaddr_in),
    };

    // Register the SIGINT signal handler
    signal(SIGINT, sigint_handler);

    // Create a TCP socket
    state.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (state.sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the server address
    if (bind(state.sockfd, (struct sockaddr *)&state.server_addr, sizeof(state.server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(state.sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Firewall listening on port %d.\n", PORT);

    // Main loop
    while (1) {
        // Accept an incoming connection
        int new_sockfd = accept(state.sockfd, (struct sockaddr *)&state.client_addr, &state.client_addr_len);
        if (new_sockfd == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                exit(1);
            }
        }

        // Check the firewall rules to see if the connection is allowed
        int allowed = 0;
        for (int i = 0; i < state.firewall->num_rules; i++) {
            struct firewall_rule *rule = &state.firewall->rules[i];
            if (strcmp(state.client_addr.sin_addr.s_addr, inet_addr(rule->src_ip)) == 0 &&
                strcmp(inet_ntoa(state.client_addr.sin_addr), rule->dst_ip) == 0 &&
                state.client_addr.sin_port == htons(rule->src_port) &&
                ntohs(state.client_addr.sin_port) == rule->dst_port &&
                strcmp(rule->protocol, "tcp") == 0) {
                allowed = 1;
                break;
            }
        }

        // If the connection is not allowed, close the socket
        if (!allowed) {
            printf("Connection from %s:%d denied.\n", inet_ntoa(state.client_addr.sin_addr), ntohs(state.client_addr.sin_port));
            close(new_sockfd);
            continue;
        }

        // If the connection is allowed, handle it
        printf("Connection from %s:%d accepted.\n", inet_ntoa(state.client_addr.sin_addr), ntohs(state.client_addr.sin_port));
        // ...

        // Close the socket when we're done with it
        close(new_sockfd);
    }

    // Close the server socket
    close(state.sockfd);

    return 0;
}