//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
// POP3 Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define MAX_BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER_SIZE];
    if(argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    char user[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE];
    printf("Enter USER command: ");
    fgets(user, MAX_BUFFER_SIZE, stdin);
    user[strcspn(user, "\n")] = 0;

    n = write(sockfd, user, strlen(user));
    if(n < 0) {
        error("Failed to write to socket");
    }

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if(n < 0) {
        error("Failed to read from socket");
    }

    printf("%s\n", buffer);

    printf("Enter PASS command: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    n = write(sockfd, password, strlen(password));
    if(n < 0) {
        error("Failed to write to socket");
    }

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if(n < 0) {
        error("Failed to read from socket");
    }

    printf("%s\n", buffer);

    printf("Enter LIST command: ");
    char list_message[MAX_BUFFER_SIZE] = "LIST";
    n = write(sockfd, list_message, strlen(list_message));
    if(n < 0) {
        error("Failed to write to socket");
    }

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if(n < 0) {
        error("Failed to read from socket");
    }

    printf("%s\n", buffer);

    printf("Enter RETR command: ");
    char retr_message[MAX_BUFFER_SIZE] = "RETR ";
    char email_number[MAX_BUFFER_SIZE];
    fgets(email_number, MAX_BUFFER_SIZE, stdin);
    email_number[strcspn(email_number, "\n")] = 0;
    strcat(retr_message, email_number);

    n = write(sockfd, retr_message, strlen(retr_message));
    if(n < 0) {
        error("Failed to write to socket");
    }

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if(n < 0) {
        error("Failed to read from socket");
    }

    printf("%s\n", buffer);

    printf("Enter QUIT command: ");
    char quit_message[MAX_BUFFER_SIZE] = "QUIT";
    n = write(sockfd, quit_message, strlen(quit_message));
    if(n < 0) {
        error("Failed to write to socket");
    }

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if(n < 0) {
        error("Failed to read from socket");
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}