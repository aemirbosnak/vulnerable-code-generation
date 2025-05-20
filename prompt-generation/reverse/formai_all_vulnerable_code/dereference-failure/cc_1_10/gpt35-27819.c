//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define BUFSIZE 1024
#define MAXHOSTNAMELEN 256
#define QOS_NUM_PACKETS 10
#define QOS_PACKET_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in addr;
    struct hostent *host;
    char *hostname;
    char sendbuf[BUFSIZE];
    char recvbuf[BUFSIZE];
    int sentbytes, recvbytes;
    int i, j, count;
    double start, end, elapsed;
    double timings[QOS_NUM_PACKETS];
    
    if(argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    hostname = argv[1];
    
    /* Resolve host name */
    host = gethostbyname(hostname);
    if(!host) {
        fprintf(stderr, "Unknown host: %s\n", hostname);
        exit(1);
    }
    
    /* Create socket */
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0) {
        perror("socket");
        exit(1);
    }
    
    /* Set destination address */
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234); /* Arbitrary port number */
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    
    /* Send packets and measure response time */
    memset(sendbuf, 'A', QOS_PACKET_SIZE);
    start = clock();
    for(i = 0; i < QOS_NUM_PACKETS; i++) {
        sentbytes = sendto(sock, sendbuf, QOS_PACKET_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
        if(sentbytes < 0) {
            perror("sendto");
            continue;
        }
        memset(recvbuf, 0, BUFSIZE);
        recvbytes = recvfrom(sock, recvbuf, BUFSIZE, 0, NULL, NULL);
        if(recvbytes < 0) {
            perror("recvfrom");
            continue;
        }
        end = clock();
        elapsed = (end - start) / CLOCKS_PER_SEC;
        timings[i] = elapsed;
    }
    close(sock);
    
    /* Analyze results */
    count = 0;
    for(i = 0; i < QOS_NUM_PACKETS; i++) {
        if(timings[i] > 0.0) {
            count++;
            printf("Packet %d: Response Time = %f ms\n", i+1, timings[i]*1000);
        }
    }
    printf("%d/%d packets received.\n", count, QOS_NUM_PACKETS);
    
    return 0;
}