//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Resolve the host name
    struct hostent *host_info = gethostbyname(host);
    if (!host_info) {
        fprintf(stderr, "Error resolving host %s\n", host);
        return EXIT_FAILURE;
    }

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr = *(struct in_addr *)host_info->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char recv_buff[BUFF_SIZE];
    recv(sockfd, recv_buff, BUFF_SIZE, 0);
    printf("%s", recv_buff);

    // Send the USER command
    sprintf(recv_buff, "USER %s\r\n", username);
    send(sockfd, recv_buff, strlen(recv_buff), 0);
    recv(sockfd, recv_buff, BUFF_SIZE, 0);
    printf("%s", recv_buff);

    // Send the PASS command
    sprintf(recv_buff, "PASS %s\r\n", password);
    send(sockfd, recv_buff, strlen(recv_buff), 0);
    recv(sockfd, recv_buff, BUFF_SIZE, 0);
    printf("%s", recv_buff);

    // Send the STAT command
    send(sockfd, "STAT\r\n", 6, 0);
    recv(sockfd, recv_buff, BUFF_SIZE, 0);
    printf("%s", recv_buff);

    // Send the LIST command
    send(sockfd, "LIST\r\n", 6, 0);
    while (1) {
        recv(sockfd, recv_buff, BUFF_SIZE, 0);
        printf("%s", recv_buff);
        if (strcmp(recv_buff, ".\r\n") == 0) {
            break;
        }
    }

    // Send the RETR command
    send(sockfd, "RETR 1\r\n", 9, 0);
    FILE *fp = fopen("email.txt", "w");
    while (1) {
        recv(sockfd, recv_buff, BUFF_SIZE, 0);
        fwrite(recv_buff, 1, strlen(recv_buff), fp);
        if (strcmp(recv_buff, ".\r\n") == 0) {
            break;
        }
    }
    fclose(fp);

    // Send the DELE command
    send(sockfd, "DELE 1\r\n", 8, 0);
    recv(sockfd, recv_buff, BUFF_SIZE, 0);
    printf("%s", recv_buff);

    // Send the QUIT command
    send(sockfd, "QUIT\r\n", 6, 0);
    recv(sockfd, recv_buff, BUFF_SIZE, 0);
    printf("%s", recv_buff);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}