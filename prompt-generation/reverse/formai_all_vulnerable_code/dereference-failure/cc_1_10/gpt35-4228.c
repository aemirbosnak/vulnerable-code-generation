//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAX_BUF_SIZE];
    
    // Check if the input is correct
    if(argc != 4) {
        printf("Usage: %s <IP Address> <Port> <File Path>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    
    // Fill in server details
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=inet_addr(argv[1]);
    servaddr.sin_port=htons(atoi(argv[2]));

    // Connect to the server
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("Connection Failed");
        exit(1);
    }

    // Send the filename to the server
    char* file_name = argv[3];
    if(send(sockfd, file_name, strlen(file_name) + 1, 0) == -1) {
        perror("Sending file name failed");
        close(sockfd);
        exit(1);
    }

    // Receive the file from the server
    int bytes_recv = 0;
    FILE* fp = fopen(file_name, "wb");
    while((bytes_recv = recv(sockfd, buf, MAX_BUF_SIZE, 0)) > 0) {
        fwrite(buf, 1, bytes_recv, fp);
    }
    fclose(fp);
    if(bytes_recv == -1) {
        perror("Error receiving file from server");
        close(sockfd);
        exit(1);
    }

    // Close the socket
    close(sockfd);
    
    return 0;
}