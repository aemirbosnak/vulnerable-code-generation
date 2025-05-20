//FormAI DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024     // buffer size
#define RULE_SIZE 100     // maximum number of firewall rules
#define IP_SIZE 16        // maximum length of an IP address string

struct firewall_rule {
    int protocol;         // "0" for all, "1" for TCP, "2" for UDP
    char source_ip[IP_SIZE];
    char destination_ip[IP_SIZE];
    int source_port;
    int destination_port;
    int allowed;          // "1" for allowed, "0" for denied
};

void parse_rule(char *line, struct firewall_rule *rule) {
    char *tok;
    tok = strtok(line, ",");
    rule->protocol = atoi(tok);
    tok = strtok(NULL, ",");
    strcpy(rule->source_ip, tok);
    tok = strtok(NULL, ",");
    strcpy(rule->destination_ip, tok);
    tok = strtok(NULL, ",");
    rule->source_port = atoi(tok);
    tok = strtok(NULL, ",");
    rule->destination_port = atoi(tok);
    tok = strtok(NULL, ",");
    rule->allowed = atoi(tok);
}

int compare_ip(char *ip1, char *ip2) {
    struct in_addr addr1, addr2;
    inet_aton(ip1, &addr1);
    inet_aton(ip2, &addr2);
    return memcmp(&addr1, &addr2, sizeof(struct in_addr));
}

int check_rule(struct firewall_rule rule, char *source_ip, char *destination_ip, int source_port, int destination_port, int protocol) {
    if (strcmp(rule.source_ip, "0.0.0.0/0") != 0) {
        if (rule.protocol == 0 || rule.protocol == protocol) {
            if (strcmp(rule.source_ip, source_ip) == 0 || strcmp(rule.source_ip, "*") == 0) {
                if (strcmp(rule.destination_ip, destination_ip) == 0 || strcmp(rule.destination_ip, "*") == 0) {
                    if (rule.source_port == 0 || rule.source_port == source_port) {
                        if (rule.destination_port == 0 || rule.destination_port == destination_port) {
                            return rule.allowed;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    struct firewall_rule firewall_rules[RULE_SIZE];
    char buffer[BUF_SIZE];
    int num_rules = 0;
    int socket_fd, recv_len;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));   // listen on port specified by command line argument
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // create socket
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // bind socket to server address
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        exit(1);
    }

    // read firewall rules from file
    FILE *fp = fopen("firewall_rules.txt", "r");
    if (fp == NULL) {
        printf("Failed to read firewall rules from file\n");
        exit(1);
    }
    while (fgets(buffer, BUF_SIZE, fp) != NULL && num_rules < RULE_SIZE) {
        parse_rule(buffer, &(firewall_rules[num_rules]));
        num_rules++;
    }
    fclose(fp);

    // main loop of program
    while (1) {
        // receive packet from client
        recv_len = recvfrom(socket_fd, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);
        if (recv_len == -1) {
            printf("Failed to receive packet\n");
            continue;
        }

        // extract source IP address
        char source_ip[IP_SIZE];
        memset(source_ip, 0, IP_SIZE);
        inet_ntop(AF_INET, &(client_addr.sin_addr), source_ip, IP_SIZE);

        // extract source and destination ports
        char *tok;
        tok = strtok(buffer, ",");
        int protocol = atoi(tok);
        tok = strtok(NULL, ",");
        int source_port = atoi(tok);
        tok = strtok(NULL, ",");
        int destination_port = atoi(tok);
        tok = strtok(NULL, ",");
        char destination_ip[IP_SIZE];
        strcpy(destination_ip, tok);

        // check if packet is allowed by firewall rules
        int allowed = 0;
        for (int i = 0; i < num_rules; i++) {
            int result = check_rule(firewall_rules[i], source_ip, destination_ip, source_port, destination_port, protocol);
            if (result == 1) {
                allowed = 1;
                break;
            } else if (result == 0) {
                allowed = 0;
                break;
            }
        }

        // send a response back to the client
        if (allowed == 1) {
            printf("Packet allowed: %s, %d, %d, %s\n", source_ip, source_port, destination_port, destination_ip);
            sendto(socket_fd, "ALLOWED", strlen("ALLOWED"), 0, (struct sockaddr *)&client_addr, client_addr_len);
        } else {
            printf("Packet denied: %s, %d, %d, %s\n", source_ip, source_port, destination_port, destination_ip);
            sendto(socket_fd, "DENIED", strlen("DENIED"), 0, (struct sockaddr *)&client_addr, client_addr_len);
        }
    }

    return 0;
}