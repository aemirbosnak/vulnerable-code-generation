//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 4096
#define INTERVAL 10
#define THRESHOLD 50

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(0);
    }
    
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR: no such host\n");
        exit(1);
    }
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"ERROR: cannot open socket\n");
        exit(1);
    }
    
    struct sockaddr_in serveraddr;
    bzero(&serveraddr, sizeof(serveraddr));
    
    serveraddr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr,"ERROR: cannot connect\n");
        exit(1);
    }
    
    char buf[BUFSIZE];
    int total_bytes = 0;
    int interval_bytes = 0;
    int duration = 0;
    
    while (1) {
        bzero(buf, BUFSIZE);
        
        int n = read(sockfd, buf, BUFSIZE-1);
        if (n <= 0) {
            fprintf(stderr,"ERROR: reading from socket\n");
            exit(1);
        }
        
        total_bytes += n;
        interval_bytes += n;
        duration += INTERVAL;
        
        if (duration == INTERVAL) {
            int qos = (interval_bytes * 100) / (BUFSIZE * INTERVAL);
            if (qos < THRESHOLD) {
                printf("Network Quality of Service Warning: %d%% QoS\n", qos);
            }
            interval_bytes = 0;
            duration = 0;
        }
    }
    
    close(sockfd);
    return 0;
}