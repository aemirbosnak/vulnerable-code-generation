//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send command
    char cmd[256];
    sprintf(cmd, "USER anonymous\r\n");
    send(sockfd, cmd, strlen(cmd), 0);
    sprintf(cmd, "PASS anonymous\r\n");
    send(sockfd, cmd, strlen(cmd), 0);

    // Receive response
    char resp[256];
    recv(sockfd, resp, 256, 0);
    printf("%s\n", resp);

    // Close socket
    close(sockfd);

    return 0;
}