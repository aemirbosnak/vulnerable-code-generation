//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants
#define PORT 110
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    // Error handling
    int sockfd, optval, n;
    struct sockaddr_in server;
    struct hostent *server_host;
    char buf[1024];

    // Create socket and connect to server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server_host = gethostbyname("localhost");
    if (server_host == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(EXIT_FAILURE);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy((char *)&server.sin_addr.s_addr, (char *)server_host->h_addr, server_host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    // Send username and password
    n = sprintf(buf, "USER %s %s\r\n", "user", "pass");
    write(sockfd, buf, n);
    n = sprintf(buf, "PASS %s %s\r\n", "user", "pass");
    write(sockfd, buf, n);

    // Receive response
    n = read(sockfd, buf, 1024);
    if (n == 0) {
        perror("Socket read error");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Disconnect
    close(sockfd);
    return 0;
}