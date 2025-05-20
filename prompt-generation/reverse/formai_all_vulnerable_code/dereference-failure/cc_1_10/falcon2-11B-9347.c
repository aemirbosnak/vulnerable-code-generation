//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTS 10
#define MAX_LINE 100

void print_usage(const char *program_name) {
    printf("Usage: %s <ip_address>\n", program_name);
}

void print_host(const char *host, const char *ip) {
    printf("%s: %s\n", host, ip);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char line[MAX_LINE];
    char *host = NULL;
    char *ip = NULL;
    int num_hosts = 0;
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    portno = htons(80);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    while (1) {
        num_hosts++;
        host = (char *)malloc(MAX_HOSTS * sizeof(char));
        ip = (char *)malloc(MAX_LINE * sizeof(char));

        bzero(host, MAX_HOSTS * sizeof(char));
        bzero(ip, MAX_LINE * sizeof(char));

        if (recv(sockfd, line, MAX_LINE, 0) < 0) {
            perror("ERROR receiving");
            exit(EXIT_FAILURE);
        }

        strncpy(host, line, MAX_HOSTS);
        strncpy(ip, line + MAX_HOSTS + 1, MAX_LINE - (MAX_HOSTS + 1));

        print_host(host, ip);

        free(host);
        free(ip);
    }

    close(sockfd);
    return 0;
}