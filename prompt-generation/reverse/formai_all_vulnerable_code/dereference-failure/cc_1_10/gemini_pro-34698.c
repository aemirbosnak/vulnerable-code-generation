//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_RULES 100
#define MAX_RULE_SIZE 100
#define DEFAULT_PORT 80

struct rule {
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    int src_port;
    int dst_port;
    bool allow;
};

struct firewall {
    struct rule rules[MAX_RULES];
    int num_rules;
};

struct firewall *firewall_new() {
    struct firewall *firewall = malloc(sizeof(struct firewall));
    if (firewall == NULL) {
        return NULL;
    }

    firewall->num_rules = 0;

    return firewall;
}

void firewall_free(struct firewall *firewall) {
    free(firewall);
}

int firewall_add_rule(struct firewall *firewall, char *src_ip, char *dst_ip, int src_port, int dst_port, bool allow) {
    if (firewall->num_rules >= MAX_RULES) {
        return -1;
    }

    struct rule *rule = &firewall->rules[firewall->num_rules++];

    strcpy(rule->src_ip, src_ip);
    strcpy(rule->dst_ip, dst_ip);
    rule->src_port = src_port;
    rule->dst_port = dst_port;
    rule->allow = allow;

    return 0;
}

int firewall_check_rule(struct firewall *firewall, char *src_ip, char *dst_ip, int src_port, int dst_port) {
    for (int i = 0; i < firewall->num_rules; i++) {
        struct rule *rule = &firewall->rules[i];

        if (strcmp(rule->src_ip, src_ip) == 0 &&
            strcmp(rule->dst_ip, dst_ip) == 0 &&
            rule->src_port == src_port &&
            rule->dst_port == dst_port) {
            return rule->allow;
        }
    }

    return false;
}

int main() {
    // Create a new firewall
    struct firewall *firewall = firewall_new();

    // Add some rules to the firewall
    firewall_add_rule(firewall, "192.168.1.1", "192.168.1.2", 80, 80, true);
    firewall_add_rule(firewall, "192.168.1.2", "192.168.1.1", 80, 80, true);
    firewall_add_rule(firewall, "192.168.1.3", "192.168.1.4", 80, 80, false);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the default port
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(DEFAULT_PORT);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for connections
    if (listen(sock, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Accept connections and check the firewall rules
    while (true) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);

        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        int client_port = ntohs(client_addr.sin_port);

        if (firewall_check_rule(firewall, client_ip, "192.168.1.4", client_port, 80)) {
            // Allow the connection
            printf("Allowed connection from %s:%d\n", client_ip, client_port);
        } else {
            // Deny the connection
            printf("Denied connection from %s:%d\n", client_ip, client_port);
            close(client_sock);
        }
    }

    // Close the socket
    close(sock);

    // Free the firewall
    firewall_free(firewall);

    return 0;
}