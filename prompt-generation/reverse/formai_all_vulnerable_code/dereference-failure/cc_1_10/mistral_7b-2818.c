//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_RECURSION_DEPTH 5
#define DNS_UDP_PORT 53

void recursive_dns_lookup(char *domain_name, int recursion_depth) {
    int sockfd, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    struct hostent *host;

    if (recursion_depth > MAX_RECURSION_DEPTH) {
        printf("Max recursion depth exceeded\n");
        exit(1);
    }

    if ((host = gethostbyname(domain_name)) != NULL) {
        printf("%s: %s\n", domain_name, inet_ntoa(*(struct in_addr *)host->h_addr));
        return;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DNS_UDP_PORT);

    if (inet_aton("8.8.8.8", &server_addr.sin_addr) == 0) {
        perror("inet_aton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    snprintf(buffer, sizeof(buffer), "%s\x00", domain_name);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, sizeof(buffer), 0);

    if (n < 0) {
        perror("recv");
        exit(1);
    }

    close(sockfd);

    if (buffer[n - 1] != '\0') {
        printf("Error: truncated response\n");
        exit(1);
    }

    recursive_dns_lookup(strtok(buffer, "\x00"), recursion_depth + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s domain_name\n", argv[0]);
        exit(1);
    }

    recursive_dns_lookup(argv[1], 0);

    return 0;
}