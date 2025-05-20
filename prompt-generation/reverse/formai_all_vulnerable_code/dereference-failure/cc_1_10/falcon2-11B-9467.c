//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(80);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];
    printf("Enter data to send:\n");
    fgets(buffer, sizeof(buffer), stdin);

    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}