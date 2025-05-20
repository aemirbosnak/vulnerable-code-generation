//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int socket_fd, portno, newsockfd, chars_read;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Connection error");
        exit(1);
    }

    while (1) {
        printf("ftp> ");
        chars_read = read(0, buffer, sizeof(buffer));
        buffer[chars_read] = '\0';

        if (strcmp(buffer, "quit") == 0) {
            close(socket_fd);
            exit(0);
        }

        if (strcmp(buffer, "help") == 0) {
            printf("Usage: %s <host> <port>\n", argv[0]);
            continue;
        }

        if (strcmp(buffer, "ls") == 0) {
            char *filename = NULL;
            int filesize = 0;
            if (read(socket_fd, buffer, sizeof(buffer)) == -1) {
                perror("Error reading from socket");
                exit(1);
            }
            sscanf(buffer, "%s %d", filename, &filesize);
            printf("File: %s\nSize: %d\n", filename, filesize);
        } else if (strcmp(buffer, "get") == 0) {
            char *filename = NULL;
            int filesize = 0;
            if (read(socket_fd, buffer, sizeof(buffer)) == -1) {
                perror("Error reading from socket");
                exit(1);
            }
            sscanf(buffer, "%s %d", filename, &filesize);
            if ((newsockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("Socket creation error");
                exit(1);
            }
            if (connect(newsockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) == -1) {
                perror("Connection error");
                exit(1);
            }
            if ((chars_read = write(newsockfd, filename, strlen(filename)))!= strlen(filename)) {
                perror("Write error");
                exit(1);
            }
            if ((chars_read = write(newsockfd, " ", 1))!= 1) {
                perror("Write error");
                exit(1);
            }
            if ((chars_read = write(newsockfd, &filesize, sizeof(filesize)))!= sizeof(filesize)) {
                perror("Write error");
                exit(1);
            }
            if ((chars_read = read(newsockfd, buffer, sizeof(buffer))) == -1) {
                perror("Error reading from socket");
                exit(1);
            }
            printf("File: %s\nSize: %d\n", buffer, filesize);
        } else if (strcmp(buffer, "put") == 0) {
            char *filename = NULL;
            int filesize = 0;
            if (read(socket_fd, buffer, sizeof(buffer)) == -1) {
                perror("Error reading from socket");
                exit(1);
            }
            sscanf(buffer, "%s %d", filename, &filesize);
            if ((newsockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("Socket creation error");
                exit(1);
            }
            if (connect(newsockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) == -1) {
                perror("Connection error");
                exit(1);
            }
            if ((chars_read = write(newsockfd, filename, strlen(filename)))!= strlen(filename)) {
                perror("Write error");
                exit(1);
            }
            if ((chars_read = write(newsockfd, " ", 1))!= 1) {
                perror("Write error");
                exit(1);
            }
            if ((chars_read = write(newsockfd, &filesize, sizeof(filesize)))!= sizeof(filesize)) {
                perror("Write error");
                exit(1);
            }
            if ((chars_read = read(socket_fd, buffer, sizeof(buffer))) == -1) {
                perror("Error reading from socket");
                exit(1);
            }
            printf("File: %s\nSize: %d\n", buffer, filesize);
        }
    }

    return 0;
}