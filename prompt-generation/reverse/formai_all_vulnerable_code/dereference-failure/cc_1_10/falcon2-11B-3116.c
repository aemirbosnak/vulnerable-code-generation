//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 143

void medieval_client()
{
    int sockfd, portno;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    // connect to the server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // send the command
    char command[256];
    strcpy(command, "AUTH LOGIN username password");
    write(sockfd, command, strlen(command));

    // receive and print the response
    char response[1024];
    if (read(sockfd, response, sizeof(response)) < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    // close the socket
    close(sockfd);
}

int main()
{
    medieval_client();
    return 0;
}