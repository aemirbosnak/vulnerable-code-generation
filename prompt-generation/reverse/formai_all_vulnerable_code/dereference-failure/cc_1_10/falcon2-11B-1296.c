//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char command[256];
    char response[256];

    if (argc!= 3)
    {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    memset(buffer, '\0', sizeof(buffer));
    memset(command, '\0', sizeof(command));
    memset(response, '\0', sizeof(response));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting");
        exit(1);
    }

    printf("Username: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Password: ");
    fgets(buffer, sizeof(buffer), stdin);

    strcpy(command, "USER ");
    strcat(command, buffer);
    strcat(command, " ");
    strcat(command, argv[2]);

    if (send(sockfd, command, strlen(command), 0) < 0)
    {
        perror("Error sending command");
        exit(1);
    }

    if (recv(sockfd, response, sizeof(response), 0) < 0)
    {
        perror("Error receiving response");
        exit(1);
    }

    printf("Server response: %s\n", response);

    close(sockfd);
    return 0;
}