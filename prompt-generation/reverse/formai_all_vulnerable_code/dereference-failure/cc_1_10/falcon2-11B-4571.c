//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    char *hostname = argv[1];
    char *port = argv[2];

    if (argc!= 3)
    {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(port);

    server = gethostbyname(hostname);

    if (server == NULL)
    {
        fprintf(stderr, "Unknown host: %s\n", hostname);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s:%s\n", hostname, port);

    while (1)
    {
        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);

        n = write(sockfd, buffer, strlen(buffer));
        if (n <= 0)
        {
            perror("ERROR writing to socket");
            exit(1);
        }

        printf("Sent: %s\n", buffer);

        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    return 0;
}