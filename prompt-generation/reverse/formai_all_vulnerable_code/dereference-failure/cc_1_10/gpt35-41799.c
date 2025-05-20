//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024
#define QOS_THRESHOLD 100

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFSIZE];
    int n, m, nbytes;
    float qos = 0.0;

    // check for correct usage
    if (argc != 3) {
        printf("usage: %s <server-ip-addr> <port>\n", argv[0]);
        exit(1);
    }

    // create a socket for the client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // specify the server address and port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // connect to the server
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        error("ERROR connecting");

    while(1) {

        // send a request to the server
        n = write(sockfd, "send", strlen("send"));
        if (n < 0)
            error("ERROR writing to socket");

        // receive the response from the server
        bzero(buffer, BUFSIZE);
        nbytes = read(sockfd, buffer, BUFSIZE);
        if (nbytes < 0)
            error("ERROR reading from socket");

        // calculate the QoS based on the response time
        qos = BUFSIZE / (float)nbytes * 100;
        printf("QoS: %f\n", qos);

        // check if the QoS is below threshold
        if(qos < QOS_THRESHOLD) {
            printf("Warning: Network QoS is below threshold!\n");
        }

        // sleep for a while to prevent spamming the server
        sleep(1);
    }

    // close the socket
    close(sockfd);

    return 0;
}