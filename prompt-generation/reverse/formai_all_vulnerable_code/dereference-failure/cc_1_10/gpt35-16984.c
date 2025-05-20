//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes, imap_port;
    char buffer[MAX_BUFFER_SIZE], username[MAX_BUFFER_SIZE], password[MAX_BUFFER_SIZE], server[MAX_BUFFER_SIZE];
    struct hostent *he;
    struct sockaddr_in server_addr;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <IMAP port> <username>\n", argv[0]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    if ((he = gethostbyname(argv[1])) == NULL) {
        perror("Error: gethostbyname");
        exit(1);
    }

    imap_port = atoi(argv[2]);
    server_addr.sin_port = htons(imap_port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Error: connection");
        exit(1);
    }

    printf("Connection to %s:%d established.\n", argv[1], imap_port);

    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    sprintf(username, "%s\n", argv[3]);
    send(sockfd, username, strlen(username), 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    printf("Enter your password: ");
    fflush(stdout);
    fgets(password, MAX_BUFFER_SIZE, stdin);
    sprintf(password, "%s\n", password);
    send(sockfd, password, strlen(password), 0);
    numbytes = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}