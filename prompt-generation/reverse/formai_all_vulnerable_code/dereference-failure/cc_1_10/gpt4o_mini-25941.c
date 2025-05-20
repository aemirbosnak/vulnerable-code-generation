//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_PACKETS 1048576

struct firewall_rule {
    char *ipaddress;
    char *action; // "ALLOW" or "BLOCK"
    struct firewall_rule *next;
};

struct firewall_rule *rules = NULL;

void add_rule(const char *ip, const char *action) {
    struct firewall_rule *new_rule = (struct firewall_rule *)malloc(sizeof(struct firewall_rule));
    new_rule->ipaddress = strdup(ip);
    new_rule->action = strdup(action);
    new_rule->next = rules;
    rules = new_rule;
}

int check_rule(const char *ip) {
    struct firewall_rule *current = rules;
    while (current != NULL) {
        if (strcmp(current->ipaddress, ip) == 0) {
            return strcmp(current->action, "BLOCK") == 0 ? -1 : 1;
        }
        current = current->next;
    }
    return 0; // No rule found
}

void free_rules() {
    struct firewall_rule *current = rules;
    while (current != NULL) {
        struct firewall_rule *temp = current;
        current = current->next;
        free(temp->ipaddress);
        free(temp->action);
        free(temp);
    }
}

void process_packet(unsigned char *buffer, int size) {
    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct sockaddr_in source, dest;
    
    memset(&source, 0, sizeof(source));
    source.sin_addr.s_addr = ip_header->saddr;

    memset(&dest, 0, sizeof(dest));
    dest.sin_addr.s_addr = ip_header->daddr;

    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];
    
    inet_ntop(AF_INET, &(source.sin_addr), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(dest.sin_addr), dest_ip, INET_ADDRSTRLEN);

    int rule_check = check_rule(src_ip);
    if (rule_check == -1) {
        printf("Blocked packet from %s to %s\n", src_ip, dest_ip);
        return; // Block packet
    } else if (rule_check == 1) {
        printf("Allowed packet from %s to %s\n", src_ip, dest_ip);
    } else {
        printf("No rule found for packet from %s to %s. Allowed by default.\n", src_ip, dest_ip);
    }
}

int setup_socket() {
    int sockfd;
    struct sockaddr_in sockaddr_in;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Allow socket to receive all packets
    int opt = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)) < 0) {
        perror("Setting socket options failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    memset(&sockaddr_in, 0, sizeof(sockaddr_in));
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void run_firewall() {
    int sockfd = setup_socket();
    unsigned char *buffer = (unsigned char *)malloc(MAX_PACKETS);
    int data_size;

    while (1) {
        data_size = recv(sockfd, buffer, MAX_PACKETS, 0);
        if (data_size < 0) {
            perror("Failed to receive");
            break;
        }
        process_packet(buffer, data_size);
    }

    free(buffer);
    close(sockfd);
}

int main(int argc, char **argv) {
    // Adding firewall rules
    add_rule("192.168.1.100", "BLOCK");
    add_rule("10.0.0.1", "ALLOW");

    printf("Firewall is now running...\n");
    run_firewall();

    // Clean up
    free_rules();
    return 0;
}