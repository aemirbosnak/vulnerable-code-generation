//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    struct hostent *server;
    struct in_addr *ip;

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buf[100];

    if ((server = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Hostname not found\n");
        return 1;
    }

    ip = *((struct in_addr **)server->h_addr_list);
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) ip, (char *) &serv_addr.sin_addr.s_addr, sizeof(struct in_addr));
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        return 1;
    }

    time_t t = time(NULL);
    sprintf(buf, "From: %s\nTo: %s\nSubject: Cryptic Email\n\n", argv[1], argv[1]);
    sprintf(buf, "%s", "This is a cryptic email sent from %s on %s.");
    write(sockfd, buf, strlen(buf));
    close(sockfd);

    return 0;
}