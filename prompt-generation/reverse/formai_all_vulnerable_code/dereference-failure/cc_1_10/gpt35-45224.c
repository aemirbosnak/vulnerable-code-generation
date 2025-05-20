//FormAI DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 12543
#define BUF_SIZE    1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    
    int i, sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    struct timeval start_time, end_time;
    double time_diff;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = ((struct in_addr *)(server->h_addr))->s_addr;
    server_addr.sin_port = htons(SERVER_PORT);

    for (i = 0; i < 4; i++) {
        memset(buffer, 0, BUF_SIZE);
        gettimeofday(&start_time, NULL);
        sprintf(buffer, "PING %d %d\n", i, (int)time(NULL));
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("ERROR in sendto");
            exit(1);
        }

        memset(buffer, 0, BUF_SIZE);
        socklen_t server_len = sizeof(server_addr);
        if (recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &server_len) < 0) {
            perror("ERROR in recvfrom");
            exit(1);
        }
        
        gettimeofday(&end_time, NULL);
        time_diff = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000;
        
        printf("PING %d %d bytes from %s: time=%.2f ms\n", i, (int)strlen(buffer), argv[1], time_diff * 1000);
        sleep(1);
    }
    
    close(sockfd);
    return 0;
}