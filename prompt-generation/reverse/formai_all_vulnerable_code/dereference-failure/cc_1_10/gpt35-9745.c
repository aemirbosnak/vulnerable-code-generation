//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

int main(int argc, char *argv[]) {
    if(argc != 5) {
        printf("Usage: ./smtpclient <from> <to> <server> <message>\n");
        return 1;
    }

    char *from = argv[1];
    char *to = argv[2];
    char *server = argv[3];
    char *message = argv[4];
    char *buffer = malloc(1024);
    memset(buffer, 0, 1024);

    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: Unable to create socket.\n");
        return 1;
    }

    host = gethostbyname(server);
    if(host == NULL) {
        printf("Error: Unable to resolve hostname.\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Unable to connect to server.\n");
        return 1;
    }

    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "HELO %s\r\n", server);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "RCPT TO: <%s>\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "%s\r\n", message);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "\r\n.\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s", buffer);
    memset(buffer, 0, 1024);

    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);
    printf("%s\n", buffer);
    memset(buffer, 0, 1024);

    close(sockfd);
    free(buffer);
    return 0;
}