//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define MAX_CONNECTIONS 10

struct FirewallRule {
    char *name;
    char *action;
    char *protocol;
    char *source_ip;
    char *destination_ip;
    int source_port;
    int destination_port;
    time_t start_time;
    time_t end_time;
};

struct Firewall {
    struct FirewallRule rules[MAX_CONNECTIONS];
    int num_rules;
};

struct Firewall *firewall;

void init_firewall() {
    firewall = malloc(sizeof(struct Firewall));
    firewall->num_rules = 0;
}

void add_firewall_rule(char *name, char *action, char *protocol, char *source_ip, char *destination_ip, int source_port, int destination_port, time_t start_time, time_t end_time) {
    struct FirewallRule rule;
    
    rule.name = strdup(name);
    rule.action = strdup(action);
    rule.protocol = strdup(protocol);
    rule.source_ip = strdup(source_ip);
    rule.destination_ip = strdup(destination_ip);
    rule.source_port = source_port;
    rule.destination_port = destination_port;
    rule.start_time = start_time;
    rule.end_time = end_time;
    
    firewall->rules[firewall->num_rules++] = rule;
}

int check_firewall_rule(struct FirewallRule *rule, struct sockaddr_in *source_addr, struct sockaddr_in *destination_addr, int protocol, int source_port, int destination_port, time_t timestamp) {
    if (strcmp(rule->protocol, "TCP") != 0 && strcmp(rule->protocol, "UDP") != 0 && strcmp(rule->protocol, "ICMP") != 0) {
        return -1;
    }
    
    if (strcmp(rule->source_ip, "*") != 0 && strcmp(rule->source_ip, inet_ntoa(source_addr->sin_addr)) != 0) {
        return -1;
    }
    
    if (strcmp(rule->destination_ip, "*") != 0 && strcmp(rule->destination_ip, inet_ntoa(destination_addr->sin_addr)) != 0) {
        return -1;
    }
    
    if (rule->source_port != 0 && rule->source_port != source_port) {
        return -1;
    }
    
    if (rule->destination_port != 0 && rule->destination_port != destination_port) {
        return -1;
    }
    
    if (rule->start_time != 0 && rule->start_time > timestamp) {
        return -1;
    }
    
    if (rule->end_time != 0 && rule->end_time < timestamp) {
        return -1;
    }
    
    return 0;
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char buffer[1024];
    time_t timestamp;
    int i;
    
    init_firewall();
    
    add_firewall_rule("rule1", "allow", "TCP", "192.168.1.1", "192.168.1.2", 80, 80, 0, 0);
    add_firewall_rule("rule2", "deny", "UDP", "192.168.1.3", "192.168.1.4", 53, 53, 0, 0);
    add_firewall_rule("rule3", "allow", "ICMP", "*", "*", 0, 0, 0, 0);
    
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, MAX_CONNECTIONS);
    
    while (1) {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd < 0) {
            perror("accept");
            continue;
        }
        
        timestamp = time(NULL);
        
        recv(connfd, buffer, sizeof(buffer), 0);
        
        for (i = 0; i < firewall->num_rules; i++) {
            if (check_firewall_rule(&firewall->rules[i], &cliaddr, &servaddr, IPPROTO_TCP, 80, 80, timestamp) == 0) {
                if (strcmp(firewall->rules[i].action, "allow") == 0) {
                    send(connfd, "HTTP/1.1 200 OK\n\nHello, world!\n", strlen("HTTP/1.1 200 OK\n\nHello, world!\n"), 0);
                    close(connfd);
                    break;
                } else if (strcmp(firewall->rules[i].action, "deny") == 0) {
                    send(connfd, "HTTP/1.1 403 Forbidden\n\nYou are not allowed to access this resource.\n", strlen("HTTP/1.1 403 Forbidden\n\nYou are not allowed to access this resource.\n"), 0);
                    close(connfd);
                    break;
                }
            }
        }
        
        if (i == firewall->num_rules) {
            send(connfd, "HTTP/1.1 404 Not Found\n\nThe requested resource could not be found.\n", strlen("HTTP/1.1 404 Not Found\n\nThe requested resource could not be found.\n"), 0);
            close(connfd);
        }
    }
    
    close(listenfd);
    
    return 0;
}