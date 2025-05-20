//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_PATH_LENGTH 256

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <command>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *command = argv[2];

    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        error("gethostbyname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("connect");
    }

    char buffer[256];
    memset(buffer, 0, sizeof(buffer));

    // Receive welcome message
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        error("recv");
    }
    printf("%s", buffer);

    // Send command
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("send");
    }

    // Receive response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        error("recv");
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}