//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portnum, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR: Unknown host %s\n", argv[1]);
        exit(2);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(3);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(4);
    }

    for (portnum = 1; portnum <= 65535; portnum++)
    {
        if (portnum == 80)
            continue;

        printf("Testing port %d... ", portnum);
        if (send(sockfd, "X", 1, 0) < 0)
        {
            perror("ERROR sending");
            exit(5);
        }

        n = recv(sockfd, "", 1, 0);
        if (n < 0)
        {
            perror("ERROR receiving");
            exit(6);
        }

        if (n == 0)
        {
            printf("PASSED\n");
            continue;
        }

        printf("FAILED\n");
        exit(7);
    }

    printf("All ports passed!\n");

    return 0;
}