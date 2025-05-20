//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server;
    char *host, *port;
    char buffer[BUFFER_SIZE];
    int nbytes;
    FILE *fp;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <filename>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];
    fp = fopen(argv[3], "wb");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while ((nbytes = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, nbytes, fp);
    }

    printf("File transfer complete\n");

    close(sockfd);
    close(fp);

    return 0;
}