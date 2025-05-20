//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char email[100][100];
    char subject[100];
    char sender[100];
    char date[20];
    char temp[10];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = PORT;
    server = gethostbyname("example.com"); // Replace with your POP3 server

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    // USER command
    write(sockfd, "USER your_email@example.com\r\n", 17);
    read(sockfd, buffer, BUFFER_SIZE);

    // PASS command
    write(sockfd, "PASS your_password\r\n", 8);
    read(sockfd, buffer, BUFFER_SIZE);

    // TOP command to get number of messages
    write(sockfd, "TOP 1\r\n", 4);
    read(sockfd, buffer, BUFFER_SIZE);

    sscanf(buffer, "+OK %d messages %d octets\r\n", &n, NULL);

    for (int i = 1; i <= n; i++) {
        // RETR command to get message details
        sprintf(buffer, "RETR %d\r\n", i);
        write(sockfd, buffer, strlen(buffer));

        read(sockfd, buffer, BUFFER_SIZE);

        sscanf(buffer, "From %s\r\nSubject: %s\r\nDate: %s\r\n", sender, subject, date);
        strcpy(email[i - 1], sender);
        strcpy(temp, date);
        strcpy(email[i - 1] + strlen(email[i - 1]) + 1, subject);

        // Get message size and read message content
        read(sockfd, buffer, BUFFER_SIZE);
        sscanf(buffer, "+OK %d octets\r\n", &n);

        read(sockfd, buffer, n);

        printf("Subject: %s\nFrom: %s\nDate: %s\nContent:\n", email[i - 1], email[i - 1], temp);
        printf("%s\n\n", buffer);
    }

    close(sockfd);
    return 0;
}