//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_PACKET_SIZE 1024

int main() {

    char hostname[256];
    int port;
    int sockfd, send_len, recv_len;
    struct sockaddr_in server_addr;
    struct hostent *hp;
    char buffer[MAX_PACKET_SIZE];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    hp = gethostbyname(hostname);

    if (hp == NULL) {
        perror("Error getting host information");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = hp->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter message: ");
    scanf("%s", buffer);

    send_len = send(sockfd, buffer, MAX_PACKET_SIZE, 0);

    if (send_len < 0) {
        perror("Error sending message");
        exit(1);
    }

    recv_len = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);

    if (recv_len < 0) {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received message: %s\n", buffer);

    close(sockfd);

    return 0;
}