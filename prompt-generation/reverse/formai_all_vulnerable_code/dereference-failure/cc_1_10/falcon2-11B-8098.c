//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Define the maximum buffer size
#define MAX_BUFF 1024

// Structure to store the IP address and port number
struct ip_info {
    char ip[16];
    int port;
};

// Function to parse the IP address from the string
struct ip_info* parse_ip(char* ip_str) {
    struct ip_info* ip_info = (struct ip_info*)malloc(sizeof(struct ip_info));
    strncpy(ip_info->ip, ip_str, 15);
    ip_info->port = atoi(strtok(NULL, ":"));
    return ip_info;
}

// Function to check if the IP address is valid
int is_valid_ip(struct ip_info* ip_info) {
    char* ip_address = ip_info->ip;
    char* end_of_ip = ip_address + 15;
    char* dot;

    if (inet_pton(AF_INET, ip_address, &end_of_ip) <= 0) {
        return 0;
    }

    for (dot = ip_address; dot!= end_of_ip; dot++) {
        if (*dot!= '.') {
            return 0;
        }
    }

    return 1;
}

// Function to check if the port number is valid
int is_valid_port(int port) {
    if (port < 0 || port > 65535) {
        return 0;
    }
    return 1;
}

// Function to send a TCP packet to the given IP address and port
int send_packet(int sockfd, struct ip_info* ip_info) {
    char packet[MAX_BUFF];
    int n;

    if (is_valid_ip(ip_info) && is_valid_port(ip_info->port)) {
        memset(packet, 0, MAX_BUFF);
        snprintf(packet, MAX_BUFF, "GET / HTTP/1.1\r\nHost: %s:%d\r\n\r\n", ip_info->ip, ip_info->port);
        n = send(sockfd, packet, strlen(packet), 0);
        if (n < 0) {
            perror("send");
            return -1;
        }
        return 0;
    }

    return -1;
}

// Function to create a TCP socket and connect to the given IP address and port
int create_and_connect(struct ip_info* ip_info) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(ip_info->port);
    serv_addr.sin_addr.s_addr = inet_addr(ip_info->ip);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    return sockfd;
}

// Function to handle the incoming TCP packets
void handle_packet(int sockfd, struct ip_info* ip_info) {
    char buffer[MAX_BUFF];
    int n;

    while ((n = recv(sockfd, buffer, MAX_BUFF, 0)) > 0) {
        if (strstr(buffer, "HTTP/1.1 200 OK")) {
            printf("Packet received from %s:%d\n", ip_info->ip, ip_info->port);
            return;
        }

        memset(buffer, 0, MAX_BUFF);
    }

    printf("Packet not received from %s:%d\n", ip_info->ip, ip_info->port);
    return;
}

// Function to create and send packets to multiple IP addresses
int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    struct ip_info* ip_info = parse_ip(argv[1]);
    if (is_valid_ip(ip_info) && is_valid_port(atoi(argv[2]))) {
        int sockfd = create_and_connect(ip_info);
        if (sockfd >= 0) {
            handle_packet(sockfd, ip_info);
            close(sockfd);
        }
    }

    return 0;
}