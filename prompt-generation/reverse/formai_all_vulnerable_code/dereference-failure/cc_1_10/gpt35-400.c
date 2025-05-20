//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAXLINE 8192 /* Max text line length */
#define MAXSIZE 8192 /* Max response size*/

// Function to establish a secure connection with the server
int establish_connection(char *server, char *port)
{
    int sockfd;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(server, port, &hints, &servinfo);

    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd < 0)
        {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) != -1)
        {
            break;
        }
        close(sockfd);
    }

    if (p == NULL)
    {
        fprintf(stderr, "Connection failed\n");
        return -1;
    }

    freeaddrinfo(servinfo);

    return sockfd;
}

void send_request(int sockfd, char *request)
{
    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send error");
        exit(EXIT_FAILURE);
    }
}

void receive_response(int sockfd, char *response)
{
    int numbytes = recv(sockfd, response, MAXSIZE - 1, 0);
    if (numbytes == -1)
    {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    response[numbytes] = '\0';
}

int main()
{
    char server[] = "mail.example.com";
    char port[] = "993";

    int sockfd = establish_connection(server, port);
    if (sockfd < 0)
    {
        exit(EXIT_FAILURE);
    }

    char request[MAXLINE];
    char response[MAXSIZE];

    // Send login request
    sprintf(request, "%s\n", "login username password");
    send_request(sockfd, request);
    receive_response(sockfd, response);
    printf("%s", response);

    // Send select request
    sprintf(request, "%s\n", "select inbox");
    send_request(sockfd, request);
    receive_response(sockfd, response);
    printf("%s", response);

    // Send fetch request for all messages
    sprintf(request, "%s\n", "fetch 1:*");
    send_request(sockfd, request);
    receive_response(sockfd, response);
    printf("%s", response);

    // Send logout request
    sprintf(request, "%s\n", "logout");
    send_request(sockfd, request);
    receive_response(sockfd, response);
    printf("%s", response);

    // Close connection
    close(sockfd);

    return 0;
}