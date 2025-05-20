//FormAI DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    // check for valid arguments
    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // set server address
    bzero((char*)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    // accept incoming connections
    newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    bzero(buffer, 1024);

    // receive message from client
    if (read(newsockfd, buffer, 1024) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // extract filename from request
    char* file_name = strtok(buffer, " ");
    file_name = strtok(NULL, " ");

    // open file
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        perror("ERROR opening file");
        exit(1);
    }

    // get file size
    struct stat st;
    fstat(fd, &st);
    int file_size = st.st_size;

    // send HTTP response header
    char* response_header = "HTTP/1.0 200 OK\nContent-Type: text/html\nConnection: close\n\n";
    if (write(newsockfd, response_header, strlen(response_header)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // send file
    char buffer2[file_size];
    int bytes_read = read(fd, buffer2, file_size);
    if (write(newsockfd, buffer2, bytes_read) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // close sockets and file
    close(newsockfd);
    close(sockfd);
    close(fd);

    return 0;
}