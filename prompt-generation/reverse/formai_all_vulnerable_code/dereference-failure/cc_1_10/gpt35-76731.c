//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

#define PORT 80
#define MAX_HOSTNAME_LEN 200
#define MAX_IP_LEN 16
#define IP "192.168.0.1"
#define SUBNET "192.168.0."

void scan_network(int start, int end);
void get_ip_address(char *hostname, char *ip);

int main(void)
{
    scan_network(1, 255);

    return 0;
}

void scan_network(int start, int end)
{
    int i;

    for (i = start; i <= end; i++) {
        char ip[MAX_IP_LEN];
        char hostname[MAX_HOSTNAME_LEN];

        sprintf(hostname, "RP_%d.local", i);
        get_ip_address(hostname, ip);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("socket() error");
        }

        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);

        if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
            perror("inet_pton() error");
        }

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            close(sockfd);
        }
        else {
            printf("Device found: %s\n", hostname);
            close(sockfd);
        }
    }
}

void get_ip_address(char *hostname, char *ip)
{
    struct addrinfo hints, *res;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;

    if ((status = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(AF_INET, &(ipv4->sin_addr), ip, INET_ADDRSTRLEN);

    freeaddrinfo(res);
}