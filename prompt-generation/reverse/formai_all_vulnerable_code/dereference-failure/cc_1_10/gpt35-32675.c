//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    int sockfd, bytes, received_bytes;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    char filename[100];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s <hostname> <port> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("\n socket creation error \n");
        exit(EXIT_FAILURE);
    }

    memset(&address, '0', sizeof(address));

    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(argv[2]));

    if(inet_pton(AF_INET, argv[1], &address.sin_addr) <= 0) {
        printf("\n invalid address/ address not supported \n");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("\n connection failed \n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP Server!\n");

    // Send the filename to the server
    memset(filename, '0', 100);
    strcpy(filename, argv[3]);
    send(sockfd, filename, strlen(filename), 0);

    // Receive the file contents from the server
    memset(buffer, '0', BUFFER_SIZE);
    received_bytes = 0;
    while ((bytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        received_bytes += bytes;
        fwrite(buffer, sizeof(char), bytes, stdout);
    }

    printf("Received %d bytes from server.\n", received_bytes);

    close(sockfd);

    return 0;
}