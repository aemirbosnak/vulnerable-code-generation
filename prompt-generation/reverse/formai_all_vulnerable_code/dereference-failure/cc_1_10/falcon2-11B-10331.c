//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd, portno, nbytes, addrlen;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    // AF_INET address family (IPv4)
    serv_addr.sin_family = AF_INET;

    // Server's IP address (local machine)
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Port number (choose any available port)
    serv_addr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Send data to server
    char msg[100];
    sprintf(msg, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send failed");
        return 1;
    }

    // Receive data from server
    bzero(msg, 100);
    if (recv(sockfd, msg, 100, 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Close socket
    close(sockfd);

    printf("Received: %s\n", msg);

    return 0;
}