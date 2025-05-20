//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    char command[MAX_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server %s:%s\n", argv[1], argv[2]);

    // start login process
    printf("Enter Username: ");
    fgets(username, MAX_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter Password: ");
    fgets(password, MAX_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    sprintf(command, "LOGIN %s %s\r\n", username, password);
    write(sockfd, command, strlen(command));

    memset(buffer, 0, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    // enter command loop
    while (1) {
        printf("Enter Command: ");
        fgets(command, MAX_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;

        write(sockfd, command, strlen(command));

        memset(buffer, 0, MAX_SIZE);
        n = read(sockfd, buffer, MAX_SIZE-1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Server response: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}