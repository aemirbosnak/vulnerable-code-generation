//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define HOSTNAME "pop.cyberpunkmail.com"
#define PORT "110"

int main()
{
    struct addrinfo hints, *res;
    int sockfd, bytes_recv;
    char buffer[1024];

    memset(&hints, 0, sizeof hints); /* make sure the struct is empty */
    hints.ai_family = AF_UNSPEC; /* don't care IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* TCP stream sockets */
    hints.ai_flags = AI_PASSIVE; /* fill in my IP for me */

    /* get the address information for the server */
    getaddrinfo(HOSTNAME, PORT, &hints, &res);

    /* create a socket file descriptor */
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    /* connect to the server */
    connect(sockfd, res->ai_addr, res->ai_addrlen);

    /* receive the welcome message from the server */
    bytes_recv = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_recv == -1) {
        perror("recv");
        exit(1);
    }

    printf("Welcome message: %s\n", buffer);

    /* log in to the server */
    send(sockfd, "USER me@cyberpunkmail.com\r\n", strlen("USER me@cyberpunkmail.com\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    send(sockfd, "PASS mypassword\r\n", strlen("PASS mypassword\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    /* list the emails on the server */
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
    bytes_recv = recv(sockfd, buffer, sizeof(buffer), 0);
    buffer[bytes_recv] = '\0';
    printf("Emails on server:\n%s", buffer);

    /* quit the server */
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    close(sockfd);

    return 0;
}