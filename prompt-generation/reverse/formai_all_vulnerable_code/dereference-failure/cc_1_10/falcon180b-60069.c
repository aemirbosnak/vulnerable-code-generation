//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char msg[1024];
    int len;

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(errno);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(errno);
    }

    // Send message to server
    strcpy(msg, "Hello, World!");
    len = strlen(msg);
    send(sockfd, msg, len, 0);

    // Receive message from server
    memset(msg, 0, sizeof(msg));
    len = recv(sockfd, msg, sizeof(msg), 0);
    if (len == -1) {
        perror("recv failed");
        exit(errno);
    }
    printf("Received message: %s\n", msg);

    // Close connection
    close(sockfd);

    return 0;
}