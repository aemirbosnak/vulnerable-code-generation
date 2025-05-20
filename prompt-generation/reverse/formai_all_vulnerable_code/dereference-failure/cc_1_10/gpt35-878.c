//FormAI DATASET v1.0 Category: Simple Web Server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

void send_file(int socket, char* file_path) {
    char buffer[BUFFER_SIZE];
    int fd = open(file_path, O_RDONLY);

    if (fd < 0) {
        printf("Error: Unable to open file.\n");
        return;
    }

    struct stat stat_buf;
    fstat(fd, &stat_buf);
    int file_size = stat_buf.st_size;

    sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", file_size);
    send(socket, buffer, strlen(buffer), 0);

    while(1) {
        int bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0) {
            break; // End of file
        }
        if (bytes_read < 0) {
            error("Error: Unable to read file.\n");
        }
        if (send(socket, buffer, bytes_read, 0) < 0) {
            error("Error: Unable to send file data.\n");
        }
    }

    close(fd);
}

void handle_request(int socket, char* root_dir) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received < 0) {
        error("Error: Unable to receive request.\n");
    }

    // Parse the request
    char method[10], path[50];
    sscanf(buffer, "%s %s", method, path);

    // If the request is for the root directory, serve index.html
    if (strcmp(path, "/") == 0) {
        strcpy(path, "/index.html");
    }

    // Build the file path based on the root directory
    char file_path[50];
    sprintf(file_path, "%s%s", root_dir, path);

    send_file(socket, file_path);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s <port> <root_dir>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    char* root_dir = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error: Unable to open socket.\n");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error: Unable to bind address.\n");
    }

    listen(sockfd, 5);

    while(1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Error: Unable to accept connection.\n");
        }

        handle_request(newsockfd, root_dir);

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}