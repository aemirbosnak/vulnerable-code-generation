//FormAI DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 2) {
       fprintf(stderr,"usage %s hostname\n", argv[0]);
       exit(0);
    }
    portno = 80;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    int i;
    struct timeval start, end;
    double time_elapsed;
    printf("Pinging %s, Please wait...\n", argv[1]);
    for(i = 1; i < 11; i++) {
        if (gettimeofday(&start, NULL)) {
            error("Error while getting start time.");
        }
        n = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        if (n < 0) {
            error("ERROR writing to socket");
        }
        bzero(buffer,256);
        n = recvfrom(sockfd, buffer, 255, 0, NULL, NULL);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        if (gettimeofday(&end, NULL)) {
            error("Error while getting end time.");
        }
        time_elapsed = (end.tv_sec - start.tv_sec) * 1000.0;
        time_elapsed += (end.tv_usec - start.tv_usec) / 1000.0;
        printf("ping %d, Response Time: %f ms\n", i, time_elapsed);
    }
    printf("Ping test completed successfully.\n");
    close(sockfd);
    return 0;
}