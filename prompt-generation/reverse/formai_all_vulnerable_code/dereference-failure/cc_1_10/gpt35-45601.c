//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
// A FTP client program written in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAXSIZE 1024 // maximum buffer size

int main(int argc, char *argv[]) {
    if (argc != 4) { // should have 4 arguments
        printf("Usage: ./ftpclient <server_address> <port_number> <file_name>\n");
        exit(1);
    }

    char *server_address = argv[1]; // store server address
    int port_number = atoi(argv[2]); // store port number
    char *file_name = argv[3]; // store file name

    int sockfd, len;  
    struct sockaddr_in server_address_info;
    char buffer[MAXSIZE]; // buffer to read/write data

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if(sockfd == -1) {
        perror("Error in creating socket");
        exit(1);
    }

    server_address_info.sin_family = AF_INET; // internet address family
    server_address_info.sin_port = htons(port_number);
    server_address_info.sin_addr.s_addr = inet_addr(server_address); // store server address

    if(connect(sockfd, (struct sockaddr *) &server_address_info, sizeof(server_address_info)) == -1) { // connect to server
        perror("Error in connecting to the server");
        exit(1);
    }

    printf("Connected to server!\n");

    // send file name to server
    send(sockfd, file_name, strlen(file_name), 0);

    // open file for writing
    int fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if(fd == -1) { // error while opening file
        perror("Error opening file");
        exit(1);
    }

    // read data from server
    while((len = recv(sockfd, buffer, MAXSIZE, 0)) > 0) {
        if(write(fd, buffer, len) == -1) { // write received data to file
            perror("Error writing data to file");
            exit(1);
        }
    }

    close(fd); // close file

    printf("File received from server and saved as %s!\n", file_name);
    close(sockfd); // close socket

    return 0;
}