//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 25
#define MAX_LINE_LEN 1024

int main(int argc, char *argv[])
{
    // Create a socket
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("smtp.gmail.com");
    if (server == NULL)
    {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    int n;
    char line[MAX_LINE_LEN];
    char *p;
    int pos;

    // Sending EHLO command
    send(sockfd, "EHLO localhost\r\n", strlen("EHLO localhost\r\n"), 0);

    // Sending MAIL FROM command
    p = "MAIL FROM:<username>\r\n";
    send(sockfd, p, strlen(p), 0);

    // Sending RCPT TO command
    p = "RCPT TO:<recipient_email>\r\n";
    send(sockfd, p, strlen(p), 0);

    // Sending DATA command
    p = "DATA\r\n";
    send(sockfd, p, strlen(p), 0);

    printf("Send message to recipient\n");

    while ((n = recv(sockfd, line, MAX_LINE_LEN, 0)) > 0)
    {
        line[n] = '\0';
        pos = strcspn(line, "\r\n");
        if (pos == strlen(line))
            continue;
        else
            printf("%s", line);
    }

    // Send QUIT command
    p = "QUIT\r\n";
    send(sockfd, p, strlen(p), 0);

    close(sockfd);

    return 0;
}