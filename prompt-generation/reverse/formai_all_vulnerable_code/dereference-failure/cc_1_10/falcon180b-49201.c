//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <source_dir> <destination_dir> <port>\n", argv[0]);
        return 1;
    }

    char *source_dir = argv[1];
    char *dest_dir = argv[2];
    int port = atoi(argv[3]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buffer[BUF_SIZE];
    sprintf(buffer, "SYNC %s %s\n", source_dir, dest_dir);
    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);

    return 0;
}