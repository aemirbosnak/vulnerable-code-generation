//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <errno.h>

#define BUF_SIZE 256

int main(int argc, char *argv[]) {

    // check if correct number of arguments passed
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // setup socket
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_SIZE];
    int bytes_sent, bytes_received;
    struct timeval tv_start, tv_end;
    double total_time;

    // send data to server and time it
    bytes_sent = send(sockfd,"Hello, server!",strlen("Hello, server!"), 0);
    if (bytes_sent < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&tv_start, NULL);

    // receive data from server and time it
    bytes_received = recv(sockfd,buffer,BUF_SIZE-1, 0);
    if (bytes_received < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // add null terminator to buffer
    printf("%s\n",buffer);

    gettimeofday(&tv_end, NULL);

    // calculate time elapsed
    total_time = (double)(tv_end.tv_sec - tv_start.tv_sec) +
                 (double)(tv_end.tv_usec - tv_start.tv_usec) / 1000000.00;
    printf("Time taken: %f seconds\n", total_time);

    // close socket and exit
    close(sockfd);
    exit(EXIT_SUCCESS);
}