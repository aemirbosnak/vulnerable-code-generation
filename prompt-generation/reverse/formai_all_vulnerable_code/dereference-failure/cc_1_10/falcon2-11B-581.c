//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 21

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char host[256] = {0};
    strcpy(host, argv[1]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Create address struct
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    int n;

    // Send command
    printf("Sending command...\n");
    fgets(buffer, sizeof(buffer), stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // Read response
    printf("Reading response...\n");
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }

    // Print response
    printf("Response:\n%s", buffer);

    // Close socket
    printf("Closing socket...\n");
    close(sockfd);

    return 0;
}