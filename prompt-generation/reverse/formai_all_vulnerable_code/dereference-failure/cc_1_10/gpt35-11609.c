//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(0);
    }
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }
    printf("Connected to SMTP server %s on port %d\n", argv[1], portno);

    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Enter your email address: ");
    char from[BUFFER_SIZE];
    fgets(from, BUFFER_SIZE - 1, stdin);

    printf("Enter email address of recipient: ");
    char to[BUFFER_SIZE];
    fgets(to, BUFFER_SIZE - 1, stdin);

    printf("Enter email subject: ");
    char subj[BUFFER_SIZE];
    fgets(subj, BUFFER_SIZE - 1, stdin);

    printf("Enter email body: ");
    char body[BUFFER_SIZE];
    fgets(body, BUFFER_SIZE - 1, stdin);

    sprintf(buffer, "From: %s\nTo: %s\nSubject: %s\n%s\n", from, to, subj, body);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    printf("Email sent successfully!\n");

    close(sockfd);
    return 0;
}