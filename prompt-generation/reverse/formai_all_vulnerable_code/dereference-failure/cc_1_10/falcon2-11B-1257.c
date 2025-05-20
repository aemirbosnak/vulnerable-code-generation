//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 110
#define MAX_SERVER_NAME_LEN 64
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in server_addr;
    char hostname[MAX_SERVER_NAME_LEN];
    char buffer[MAX_BUF_SIZE];

    if (argc!= 2) {
        printf("Usage: pop3_client <hostname>\n");
        return 1;
    }

    strcpy(hostname, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    while ((n = read(sockfd, buffer, MAX_BUF_SIZE)) > 0) {
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("read");
        return 1;
    }

    close(sockfd);

    return 0;
}