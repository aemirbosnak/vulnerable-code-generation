//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF_SIZE 1024

void sendFile(int sockfd, char *filename);
void receiveFile(int sockfd, char *filename);

int main(int argc, char *argv[]) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buf[MAX_BUF_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        perror("Connection with server failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // get command from user
        printf("Enter command: ");
        fgets(buf, MAX_BUF_SIZE, stdin);

        // check if user entered "send"
        if (strncmp(buf, "send", 4) == 0) {
            // extract filename
            char *filename = strtok(buf + 4, " \n");

            // send file
            sendFile(sockfd, filename);
        }
        // check if user entered "receive"
        else if (strncmp(buf, "receive", 7) == 0) {
            // extract filename
            char *filename = strtok(buf + 7, " \n");

            // receive file
            receiveFile(sockfd, filename);
        }
        // check if user entered "exit"
        else if (strncmp(buf, "exit", 4) == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    // close socket
    close(sockfd);

    return 0;
}

// send file to server
void sendFile(int sockfd, char *filename) {
    int fd;
    struct stat filestat;
    char buf[MAX_BUF_SIZE];

    // open file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File open failed");
        return;
    }

    // get file size
    if (fstat(fd, &filestat) < 0) {
        perror("File stat failed");
        return;
    }

    // send file size to server
    sprintf(buf, "%ld", filestat.st_size);
    if (send(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("Send failed");
        return;
    }

    // send file contents to server
    while (1) {
        int nbytes = read(fd, buf, MAX_BUF_SIZE);
        if (nbytes == -1) {
            perror("Read failed");
            return;
        }
        else if (nbytes == 0) {
            break;
        }

        if (send(sockfd, buf, nbytes, 0) == -1) {
            perror("Send failed");
            return;
        }
    }

    // close file
    close(fd);

    printf("File sent successfully\n");
}

// receive file from server
void receiveFile(int sockfd, char *filename) {
    int fd;
    char buf[MAX_BUF_SIZE];

    // open file
    fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd == -1) {
        perror("File open failed");
        return;
    }

    // receive file size from server
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("Receive failed");
        return;
    }

    // convert file size to integer
    int filesize = atoi(buf);

    // receive file contents from server
    while (filesize > 0) {
        int nbytes = recv(sockfd, buf, MAX_BUF_SIZE, 0);
        if (nbytes == -1) {
            perror("Receive failed");
            return;
        }

        write(fd, buf, nbytes);

        filesize -= nbytes;
    }

    // close file
    close(fd);

    printf("File received successfully\n");
}