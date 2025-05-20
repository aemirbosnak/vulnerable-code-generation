//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 21
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unknown host %s.\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr,
         server->h_length);
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        die("ERROR connecting");
    }

    // Send USER command
    send(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0);

    // Send PASS command
    send(sockfd, "PASS mypassword\r\n", strlen("PASS mypassword\r\n"), 0);

    // Send LIST command
    send(sockfd, "PORT\r\n", strlen("PORT\r\n"), 0);
    printf("Enter IP address and port number of your FTP server: ");
    scanf("%s %d", buffer, &portno);
    send(sockfd, buffer, strlen(buffer), 0);
    send(sockfd, "\r\n", 2, 0);
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }

    if (n < 0) {
        die("ERROR receiving data");
    }

    close(sockfd);
    return 0;
}