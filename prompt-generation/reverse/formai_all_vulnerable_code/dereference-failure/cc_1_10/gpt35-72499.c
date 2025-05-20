//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Get host information
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, NULL, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *hostname_addr = (struct sockaddr_in *)res->ai_addr;
    char *ip = inet_ntoa(hostname_addr->sin_addr);
    printf("Hostname: %s\n", hostname);
    printf("IP Address: %s\n", ip);

    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof server_addr);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof server_addr) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char message[1000];

    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    if (send(sockfd, message, strlen(message) + 1, 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1000];
    memset(buffer, 0, sizeof buffer);

    if (recv(sockfd, buffer, sizeof buffer, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    close(sockfd);
    freeaddrinfo(res);

    return 0;
}