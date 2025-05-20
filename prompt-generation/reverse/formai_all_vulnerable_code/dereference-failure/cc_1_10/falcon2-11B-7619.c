//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char recv_buffer[256];
    char url[100];
    struct timeval start, end;
    double elapsed;
    struct hostent *server;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    strcpy(url, argv[1]);
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    server = gethostbyname(url);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    gettimeofday(&start, NULL);
    while (1) {
        int n = read(sockfd, recv_buffer, 255);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        if (n == 0) {
            break;
        }
        gettimeofday(&end, NULL);
        elapsed = ((double) (end.tv_sec - start.tv_sec) + ((double) (end.tv_usec - start.tv_usec)) / 1000000);
        printf("Elapsed time: %lf seconds\n", elapsed);
    }

    close(sockfd);
    return 0;
}