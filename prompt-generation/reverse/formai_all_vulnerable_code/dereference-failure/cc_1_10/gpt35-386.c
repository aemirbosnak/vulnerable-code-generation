//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int sockfd, portno, data_len, i;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, total_time;
    struct timeval start, end;
    
    if (argc != 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    data_len = strlen(buffer);
    
    gettimeofday(&start, NULL);
    start_time = (double) start.tv_sec + (double) start.tv_usec / 1000000.0;
    
    if (send(sockfd, buffer, data_len, 0) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    bzero(buffer, BUFFER_SIZE);
    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0);
    
    gettimeofday(&end, NULL);
    end_time = (double) end.tv_sec + (double) end.tv_usec / 1000000.0;
    
    total_time = end_time - start_time;
    printf("Time taken to retrieve data: %.2f seconds\n", total_time);
    
    double speed = (double) data_len / total_time / 1000000.0 * 8;
    printf("Download speed: %.2f Mbps\n", speed);
    
    close(sockfd);
    return 0;
}