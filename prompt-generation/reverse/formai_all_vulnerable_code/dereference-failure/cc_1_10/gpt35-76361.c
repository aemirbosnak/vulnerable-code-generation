//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, port;
    struct sockaddr_in servaddr;
    struct hostent *he;
    char server_name[20], sender[30], rcpt[30], message[100];

    printf("Enter the name of the SMTP server: ");
    scanf("%s", server_name);

    he = gethostbyname(server_name);

    if (he == NULL) {
        printf("Error getting host information.\n");
        exit(1);
    }

    printf("Enter the port number: ");
    scanf("%d", &port);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Connected to SMTP server.\n");

    printf("Enter sender email address: ");
    scanf("%s", sender);

    printf("Enter recipient email address: ");
    scanf("%s", rcpt);
    
    printf("Enter message: ");
    scanf("%s", message);

    char buffer[1024];

    sprintf(buffer, "HELO %s\r\n", server_name);
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "RCPT TO:<%s>\r\n", rcpt);
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "%s\r\n", message);
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, ".\r\n");
    write(sockfd, buffer, strlen(buffer));

    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));

    printf("Message sent successfully.\n");
    close(sockfd);

    return 0;
}