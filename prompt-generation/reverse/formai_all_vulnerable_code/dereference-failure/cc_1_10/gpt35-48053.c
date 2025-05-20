//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s server-address username password\n", argv[0]);
        exit(1);
    }

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Failed to resolve hostname\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993);
    server_addr.sin_addr.s_addr = ((struct in_addr*)(host->h_addr))->s_addr;

    if (connect(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    sprintf(buffer, "%s login %s %s\n", "tag001", argv[2], argv[3]);
    write(socketfd, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(socketfd, buffer, sizeof(buffer)-1);
    printf("%s\n", buffer);

    sprintf(buffer, "%s select inbox\n", "tag002");
    printf("%s\n", buffer);
    write(socketfd, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(socketfd, buffer, sizeof(buffer)-1);
    printf("%s\n", buffer);

    sprintf(buffer, "%s fetch 1:5 body[header]\n", "tag003");
    printf("%s\n", buffer);
    write(socketfd, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(socketfd, buffer, sizeof(buffer)-1);
    printf("%s\n", buffer);

    close(socketfd);
    return 0;
}