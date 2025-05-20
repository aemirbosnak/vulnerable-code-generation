//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd, n, bytes_sent, bytes_recv;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[1024];

    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset((char *) &servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80); // Port 80 for HTTP
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to %s\n", inet_ntoa(servaddr.sin_addr));

    sprintf(buffer, "GET / HTTP/1.0\r\n\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending data");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error receiving data");
        return 1;
    }

    printf("Response: %s\n", buffer);

    close(sockfd);
    return 0;
}