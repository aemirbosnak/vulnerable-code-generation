//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 110
#define BUFFER_SIZE 1024
#define MAX_MESSAGE_SIZE 1024 * 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char username[64], password[64];
    FILE *fp;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname/IP> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("ERROR opening socket");

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
        die("ERROR connecting");

    printf("Connected to POP3 server\n");

    write(sockfd, "+OK POP3d/2.0.0 (C) University of Washington, Microsoft Corp.\r\n", 58);

    write(sockfd, "USER ", 5);
    write(sockfd, argv[2], strlen(argv[2]));
    write(sockfd, "\r\n", 2);

    read(sockfd, buffer, BUFFER_SIZE);
    if (strstr(buffer, "+OK")) {
        printf("Login successful\n");
    } else {
        fprintf(stderr, "Login failed\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    write(sockfd, "PASS ", 5);
    write(sockfd, argv[3], strlen(argv[3]));
    write(sockfd, "\r\n", 2);

    read(sockfd, buffer, BUFFER_SIZE);
    if (strstr(buffer, "+OK")) {
        printf("Password accepted\n");
    } else {
        fprintf(stderr, "Invalid password\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Retrieving messages...\n");

    while (1) {
        read(sockfd, buffer, BUFFER_SIZE);

        if (strstr(buffer, ".")) {
            int message_size = atoi(strtok(buffer, " "));
            if (message_size > MAX_MESSAGE_SIZE) {
                fprintf(stderr, "Message size exceeds maximum allowed\n");
                close(sockfd);
                exit(EXIT_FAILURE);
            }

            fp = fopen("message.txt", "wb");
            read(sockfd, buffer, message_size);
            fwrite(buffer, message_size, 1, fp);
            fclose(fp);

            printf("Message downloaded: message.txt\n");
        } else if (strstr(buffer, "+QUIT")) {
            printf("Received QUIT command from server\n");
            break;
        }
    }

    close(sockfd);
    printf("Disconnected from POP3 server\n");

    return EXIT_SUCCESS;
}