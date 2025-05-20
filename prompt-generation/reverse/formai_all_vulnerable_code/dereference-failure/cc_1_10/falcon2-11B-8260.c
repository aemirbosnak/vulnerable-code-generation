//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
    // Get the hostname of the POP3 server
    char *hostname = "pop.gmail.com";
    struct addrinfo *servinfo, *p;
    int yes = 1;
    int rv;
    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;

    if ((server = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Resolve the hostname and get the service information
    if ((rv = getaddrinfo(hostname, "pop3", &servinfo, &yes))!= 0) {
        fprintf(stderr, "ERROR: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("ERROR opening socket");
            exit(1);
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("ERROR connecting");
            exit(1);
        }

        // Read the email message from the server
        char line[1000];
        int n;

        while ((n = getline(&line, sizeof(line), sockfd))!= -1) {
            printf("%s\n", line);
        }

        // Close the socket
        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}