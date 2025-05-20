//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        return -1;
    }

    int sockfd, port;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    port = atoi(argv[2]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return -1;
    }

    char buffer[MAX_SIZE];
    int n;

    while (1) {
        printf("Enter command: ");
        memset(buffer, 0, MAX_SIZE);
        fgets(buffer, MAX_SIZE, stdin);

        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }

        if ((n = write(sockfd, buffer, strlen(buffer))) < 0) {
            perror("write");
            return -1;
        }

        memset(buffer, 0, MAX_SIZE);

        if ((n = read(sockfd, buffer, MAX_SIZE)) < 0) {
            perror("read");
            return -1;
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}