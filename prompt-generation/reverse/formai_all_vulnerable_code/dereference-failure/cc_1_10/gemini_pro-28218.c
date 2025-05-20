//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_CONNECTIONS 10
#define MAX_DATA_SIZE 1024

typedef struct firewall_rule {
    char *source_ip;
    char *destination_ip;
    int source_port;
    int destination_port;
    char *protocol;
    char *action;
} firewall_rule;

typedef struct firewall {
    firewall_rule *rules;
    int num_rules;
} firewall;

firewall *create_firewall() {
    firewall *fw = malloc(sizeof(firewall));
    fw->rules = NULL;
    fw->num_rules = 0;
    return fw;
}

void add_rule(firewall *fw, firewall_rule rule) {
    fw->rules = realloc(fw->rules, (fw->num_rules + 1) * sizeof(firewall_rule));
    fw->rules[fw->num_rules++] = rule;
}

int check_rule(firewall *fw, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
    for (int i = 0; i < fw->num_rules; i++) {
        firewall_rule rule = fw->rules[i];
        if (strcmp(source_ip, rule.source_ip) == 0 && strcmp(destination_ip, rule.destination_ip) == 0 && source_port == rule.source_port && destination_port == rule.destination_port && strcmp(protocol, rule.protocol) == 0) {
            return strcmp(rule.action, "allow") == 0;
        }
    }
    return 0;
}

void process_connection(firewall *fw, int socket_fd) {
    char buffer[MAX_DATA_SIZE];
    int bytes_received = recv(socket_fd, buffer, MAX_DATA_SIZE, 0);
    if (bytes_received <= 0) {
        close(socket_fd);
        return;
    }

    char *source_ip = inet_ntoa(((struct sockaddr_in *) &socket_fd)->sin_addr);
    char *destination_ip = inet_ntoa(((struct sockaddr_in *) &socket_fd)->sin_addr);
    int source_port = ntohs(((struct sockaddr_in *) &socket_fd)->sin_port);
    int destination_port = ntohs(((struct sockaddr_in *) &socket_fd)->sin_port);
    char *protocol = "TCP";

    if (check_rule(fw, source_ip, destination_ip, source_port, destination_port, protocol)) {
        send(socket_fd, buffer, bytes_received, 0);
    } else {
        close(socket_fd);
    }
}

int main() {
    firewall *fw = create_firewall();

    firewall_rule rule1 = {
        .source_ip = "192.168.1.1",
        .destination_ip = "192.168.1.2",
        .source_port = 80,
        .destination_port = 80,
        .protocol = "TCP",
        .action = "allow"
    };

    firewall_rule rule2 = {
        .source_ip = "192.168.1.2",
        .destination_ip = "192.168.1.1",
        .source_port = 80,
        .destination_port = 80,
        .protocol = "TCP",
        .action = "allow"
    };

    add_rule(fw, rule1);
    add_rule(fw, rule2);

    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(80);

    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind() failed");
        return 1;
    }

    if (listen(server_socket_fd, MAX_CONNECTIONS) == -1) {
        perror("listen() failed");
        return 1;
    }

    while (1) {
        int client_socket_fd = accept(server_socket_fd, NULL, NULL);
        if (client_socket_fd == -1) {
            perror("accept() failed");
            continue;
        }

        process_connection(fw, client_socket_fd);
    }

    close(server_socket_fd);
    return 0;
}