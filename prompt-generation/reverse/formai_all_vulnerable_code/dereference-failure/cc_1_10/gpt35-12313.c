//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_error(char* error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){
    if(argc < 4) {
        printf("Usage: %s <ip_address> <port_number> <filename to download>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port_num = atoi(argv[2]);
    char* ip_address = argv[1];
    char* filename = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        print_error("Error creating socket!");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(port_num);

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        print_error("Connect failed!");
    }

    // sending filename to the server
    if(send(sockfd, filename, strlen(filename), 0) < 0) {
        print_error("Error in sending filename.");
    }

    // receive file size from server
    char server_msg[BUF_SIZE];
    int file_size;
    if(recv(sockfd, server_msg, BUF_SIZE, 0) < 0) {
        print_error("Receive failed!");
    }
    file_size = atoi(server_msg);

    // create file
    int fd;
    if((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        print_error("Failed to create file!");
    }

    // download file
    int bytes_received = 0;
    char buffer[BUF_SIZE];
    while(bytes_received < file_size) {
        int bytes = recv(sockfd, buffer, BUF_SIZE, 0);
        if(bytes < 0) {
            print_error("Error in receiving file");
        }
        if(write(fd, buffer, bytes) < 0) {
            print_error("Error writing to file!");
        }
        bytes_received += bytes;
    }

    // close the file
    if(close(fd) < 0) {
        print_error("Could not close the file!");
    }

    printf("File received successfully!\n");

    exit(EXIT_SUCCESS);
}