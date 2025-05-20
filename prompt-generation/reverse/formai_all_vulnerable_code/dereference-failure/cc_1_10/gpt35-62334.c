//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char filename[100];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Please enter file name: ");
    scanf("%s", filename);

    // Send filename to server
    n = write(sockfd, filename, strlen(filename));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    printf("Requesting file %s\n", filename);

    bzero(buffer, BUFFER_SIZE);

    // Receive file data from server and write to local file
    FILE *file = fopen(filename, "wb");

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        fwrite(buffer, 1, n, file);
        bzero(buffer, BUFFER_SIZE);
    }

    fclose(file);

    printf("File %s received successfully!\n", filename);
    close(sockfd);

    return 0;
}