//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error(char* message) {
    perror(message);
    exit(1);
}

void happyMessage() {
    printf("\nWelcome to the FTP client! Let's transfer some files happily!\n");
    printf("Make sure you enter the correct hostname, port number, username, and password.\n\n");
}

int main(int argc, char** argv) {
    int sockfd, filefd, len, bytes_recv, file_size;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    socklen_t addrlen = sizeof(serv_addr);

    if (argc != 5) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset(&serv_addr, 0, addrlen);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*) &serv_addr, addrlen) < 0) {
        error("ERROR connecting");
    }

    bytes_recv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_recv < 0) {
        error("ERROR receiving welcome message");
    }

    buffer[bytes_recv] = '\0';

    happyMessage();

    printf("Requesting to login as user %s ...\n", argv[3]);
    len = send(sockfd, argv[3], strlen(argv[3]), 0);
    if (len < 0) {
        error("ERROR sending username");
    }

    bytes_recv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_recv < 0) {
        error("ERROR receiving response from server");
    }

    buffer[bytes_recv] = '\0';

    printf("Response from server: %s", buffer);

    len = send(sockfd, argv[4], strlen(argv[4]), 0);
    if (len < 0) {
        error("ERROR sending password");
    }

    bytes_recv = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (bytes_recv < 0) {
        error("ERROR receiving response from server");
    }

    buffer[bytes_recv] = '\0';

    printf("Response from server: %s", buffer);

    // Example file transfer
    printf("Fetching file from server...\n");
    len = send(sockfd, "GET file.txt", strlen("GET file.txt"), 0);

    if (len < 0) {
        error("ERROR sending command");
    }

    bytes_recv = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[bytes_recv] = '\0';

    if (strncmp(buffer, "OK", 2) == 0) {
        len = sscanf(buffer, "OK %d", &file_size);
        if (len < 1) {
            error("ERROR parsing file size");
        }

        filefd = open("file.txt", O_WRONLY | O_CREAT, 0666);
        if (filefd < 0) {
            error("ERROR opening file");
        }

        while (file_size > 0) {
            bytes_recv = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_recv < 0) {
                error("ERROR reading data from socket");
            }

            len = write(filefd, buffer, bytes_recv);
            if (len < 0) {
                error("ERROR writing data to file");
            }

            file_size -= bytes_recv;
        }

        printf("File transfer successful! Check out your file.txt!\n");

        close(filefd);
    } else {
        printf("Error fetching file from server. Server response: %s\n", buffer);
    }

    close(sockfd);
    printf("Thank you for using the FTP client! Happy file transferring!\n");

    return 0;
}