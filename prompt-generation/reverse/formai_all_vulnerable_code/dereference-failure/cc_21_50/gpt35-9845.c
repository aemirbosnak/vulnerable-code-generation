//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    if(argc < 4) {
        printf("Usage: %s <hostname> <port number> <from> <to> <subject> <text>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *from = argv[3];
    char *to = argv[4];
    char *subject = argv[5];
    char *text = argc > 6 ? argv[6] : "";

    char buffer[MAX];
    memset(buffer, 0, sizeof(buffer));

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get server info
    struct hostent *he = gethostbyname(hostname);
    if(he == NULL) {
        perror("Unknown host");
        exit(1);
    }

    // set server address
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *)he->h_addr);

    // connect to server
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // read greeting from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server greeting");
        exit(1);
    }
    printf("%s", buffer);

    // send EHLO or HELO
    sprintf(buffer, "EHLO %s\r\n", hostname);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // read response from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }
    printf("%s", buffer);

    // send MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // read response from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }
    printf("%s", buffer);

    // send RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // read response from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }
    printf("%s", buffer);

    // send DATA command
    sprintf(buffer, "DATA\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // read response from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }
    printf("%s", buffer);

    // send message header
    sprintf(buffer, "From: <%s>\r\n", from);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    sprintf(buffer, "To: <%s>\r\n", to);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    sprintf(buffer, "Subject: %s\r\n", subject);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }
    sprintf(buffer, "\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // send message body
    sprintf(buffer, "%s\r\n", text);
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // send dot to indicate end of message
    sprintf(buffer, ".\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // read response from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }
    printf("%s", buffer);

    // send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // read response from server
    if(read(sockfd, buffer, MAX) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }
    printf("%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}