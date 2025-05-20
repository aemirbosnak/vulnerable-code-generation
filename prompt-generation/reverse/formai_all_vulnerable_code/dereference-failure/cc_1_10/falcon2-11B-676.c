//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: immersive
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/tcp.h>

int main() {
    // Set up a socket to listen on
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname("localhost");
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;
    server_addr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    // Now we can accept connections
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
    if (client_fd < 0) {
        perror("accept");
        exit(1);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Read and print data from the client
    char buffer[1024];
    bzero(buffer, 1024);
    int bytes_read = read(client_fd, buffer, sizeof(buffer));
    if (bytes_read <= 0) {
        perror("read");
        exit(1);
    }
    printf("Received %d bytes: %s\n", bytes_read, buffer);

    // Close the socket
    close(client_fd);
    close(sockfd);

    return 0;
}