//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXLINE 1024
#define PORT 21

//Function to send data to FTP server
void send_data(int sockfd, char* message) {
    ssize_t n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
}

//Function to receive data from FTP server
void recv_data(int sockfd, char* message) {
    ssize_t n = recv(sockfd, message, MAXLINE, 0);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    message[n] = '\0';
}

int main(int argc, char** argv) {
    int sockfd, datafd, n, i = 0;
    struct sockaddr_in servaddr, dataaddr;
    char recvline[MAXLINE], command[MAXLINE];
    char* token;

    //Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    //Set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    servaddr.sin_port = htons(PORT);

    //Connect to server
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    //Receive welcome message from server
    recv_data(sockfd, recvline);
    printf("%s", recvline);

    //Login to server
    printf("Username: ");
    fgets(command, MAXLINE, stdin);
    strcat(command, "\r\n");
    send_data(sockfd, command);

    recv_data(sockfd, recvline);
    printf("%s", recvline);

    printf("Password: ");
    fgets(command, MAXLINE, stdin);
    strcat(command, "\r\n");
    send_data(sockfd, command);

    recv_data(sockfd, recvline);
    printf("%s", recvline);

    while (1) {
        printf("FTP Client> ");
        fgets(command, MAXLINE, stdin);
        command[strlen(command) - 1] = '\0';

        //Parse command
        token = strtok(command, " ");
        if (token == NULL) {
            continue;
        }

        //Handle quit command
        if (strcmp(token, "quit") == 0) {
            send_data(sockfd, "QUIT\r\n");
            recv_data(sockfd, recvline);
            printf("%s", recvline);
            break;
        }

        //Handle ls command
        if (strcmp(token, "ls") == 0) {
            //Open data connection
            send_data(sockfd, "PASV\r\n");
            recv_data(sockfd, recvline);

            int num1, num2, port;
            char* temp;
            temp = strchr(recvline, '(');
            sscanf(temp, "(%d,%d,%d,%d,%d,%d)", &num1, &num1, &num1, &num1, &num2, &port);

            datafd = socket(AF_INET, SOCK_STREAM, 0);
            if (datafd < 0) {
                perror("Error creating data socket");
                exit(1);
            }

            bzero(&dataaddr, sizeof(dataaddr));
            dataaddr.sin_family = AF_INET;
            inet_pton(AF_INET, argv[1], &dataaddr.sin_addr);
            dataaddr.sin_port = htons(256 * num2 + port);

            if (connect(datafd, (struct sockaddr*) &dataaddr, sizeof(dataaddr)) < 0) {
                perror("Error connecting to data socket");
                exit(1);
            }

            //Send LIST command to server
            send_data(sockfd, "LIST\r\n");
            recv_data(sockfd, recvline);
            printf("%s", recvline);

            //Receive directory listing from server
            while ((n = read(datafd, recvline, MAXLINE)) > 0) {
                write(STDOUT_FILENO, recvline, n);
            }

            close(datafd);
            recv_data(sockfd, recvline);
            printf("%s", recvline);
        }
    }

    close(sockfd);
    return 0;
}