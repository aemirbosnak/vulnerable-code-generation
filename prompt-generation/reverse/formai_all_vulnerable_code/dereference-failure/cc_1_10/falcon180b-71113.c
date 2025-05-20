//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[MAX_RESPONSE_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    if (argc!= 4) {
        printf("Usage:./imap_client <server_ip> <username> <password>\n");
        return 1;
    }

    strcpy(command, "LOGIN ");
    strcat(command, argv[2]);
    strcat(command, " ");
    strcat(command, argv[3]);

    printf("Connecting to %s on port %d...\n", argv[1], IMAP_PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket.\n");
        return 1;
    }

    portno = htons(IMAP_PORT);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server.\n");
        return 1;
    }

    send(sockfd, command, strlen(command), 0);
    memset(buf, 0, MAX_RESPONSE_LENGTH);
    n = recv(sockfd, buf, MAX_RESPONSE_LENGTH, 0);

    if (n < 0) {
        printf("Failed to receive response from server.\n");
        return 1;
    }

    printf("Server response: %s\n", buf);

    close(sockfd);

    return 0;
}