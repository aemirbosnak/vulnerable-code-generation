//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024] = "Hello, World!";

    if (argc!= 2)
    {
        fprintf(stderr, "Usage %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    /* Create the socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(1);
    }

    memset(&servaddr, '0', sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(portno);

    /* Bind the socket to a local address */
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(1);
    }

    /* Listen for incoming connections */
    if (listen(sockfd, 5) < 0)
    {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", portno);

    while (1)
    {
        /* Accept the incoming connection */
        if ((n = accept(sockfd, (struct sockaddr *)&cliaddr, (socklen_t*)&servaddr)) < 0)
        {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s\n", inet_ntoa(cliaddr.sin_addr));

        /* Receive the data */
        bzero(buffer, 1024);
        n = recv(sockfd, buffer, 1024, 0);

        if (n < 0)
        {
            perror("recv");
            exit(1);
        }

        printf("%s\n", buffer);

        /* Send a response */
        send(sockfd, buffer, n, 0);

        /* Close the connection */
        close(sockfd);
    }

    return 0;
}