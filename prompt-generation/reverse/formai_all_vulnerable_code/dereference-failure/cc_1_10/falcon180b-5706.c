//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 21

int main(int argc, char *argv[])
{
    int sockfd;
    char *host;
    int port;
    char buffer[MAX_LINE];
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Error resolving host\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, MAX_LINE, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        memset(buffer, 0, MAX_LINE);
        if (recv(sockfd, buffer, MAX_LINE, 0) == 0) {
            printf("Disconnected from server\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}