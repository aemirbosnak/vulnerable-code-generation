//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port number>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];

    while (1) {
        printf("ftp> ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        } else if (strncmp(buffer, "ls", 2) == 0) {
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            printf("%s\n", buffer);
        } else if (strncmp(buffer, "get", 3) == 0) {
            char* filename = strtok(buffer, " ");
            filename = strtok(NULL, " ");
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, sizeof(buffer), 0);
            FILE* fp = fopen(filename, "w");
            fwrite(buffer, strlen(buffer), 1, fp);
            fclose(fp);
            printf("File downloaded successfully.\n");
        } else {
            printf("Invalid command.\n");
        }
    }

    close(sockfd);

    return 0;
}