//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    int sockfd, n;
    struct sockaddr_in server;
    char buffer[1024];
    struct hostent *host;

    if (argc!= 3) {
        fprintf(stderr, "usage: %s host port\n", argv[0]);
        exit(1);
    }

    /* create a socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    /* get host info */
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "no such host\n");
        exit(1);
    }

    /* connect to the host */
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);
    if ((n = connect(sockfd, (struct sockaddr *)&server, sizeof(server))) < 0) {
        perror("connect");
        exit(1);
    }

    /* measure the network latency */
    printf("Network Latency: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    printf("%d bytes\n", strlen(buffer));

    /* close socket */
    close(sockfd);

    return 0;
}