//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];
    int n, bytes_sent;

    if(argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port_number> <file_name>\n");
        exit(0);
    }

    portno = atoi(argv[2]);
    strcpy(sendbuffer, argv[3]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    // Connect to server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    // Send file name to server
    bytes_sent = send(sockfd, sendbuffer, strlen(sendbuffer), 0);
    if (bytes_sent < 0) {
        printf("Error sending file name\n");
        exit(0);
    }

    // Receive file from server
    memset(recvbuffer, 0, BUFFER_SIZE);
    while((n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s", recvbuffer);
        memset(recvbuffer, 0, BUFFER_SIZE);
    }

    // Close socket
    close(sockfd);

    return 0;
}