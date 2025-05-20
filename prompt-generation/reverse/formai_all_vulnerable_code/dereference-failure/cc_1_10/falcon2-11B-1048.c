//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip_address> <file_name>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server;
    struct sockaddr_in client;
    int sockfd, newsockfd;
    int n;
    char buffer[1024];
    char file_name[1024];
    FILE *fp;

    strcpy(file_name, argv[2]);

    printf("Connecting to %s...\n", argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&client, &n);
        printf("Connection accepted from %s\n", inet_ntoa(client.sin_addr));

        fp = fopen(file_name, "rb");
        if (fp == NULL) {
            fprintf(stderr, "Error opening file\n");
            continue;
        }

        send(newsockfd, file_name, strlen(file_name) + 1, 0);
        send(newsockfd, "File contents begin...\n", 24, 0);

        while ((n = read(fp, buffer, sizeof(buffer))) > 0) {
            send(newsockfd, buffer, n, 0);
        }

        send(newsockfd, "File contents end\n", 24, 0);

        fclose(fp);
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}