//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define SERVER "mail.example.com"
#define PORT 25
#define CRLF "\r\n"

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;

    char buffer[1024];
    int n;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // get host address
    host = gethostbyname(SERVER);
    if (host == NULL) {
        perror("gethostbyname failed");
        exit(1);
    }

    // setup server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    // send SMTP command
    char* command = "EHLO example.com" CRLF;
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[n] = '\0';

    // print response
    printf("Response from server:\n%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}