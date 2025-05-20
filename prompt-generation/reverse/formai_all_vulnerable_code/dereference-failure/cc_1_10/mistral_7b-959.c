//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SERVER_IP "192.168.1.1" // Change this to your server IP address
#define SERVER_PORT 8080 // Change this to your server port number
#define BUFFER_SIZE 1024
#define TIMEOUT 5000 // Timeout in milliseconds

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct timeval start, end;
    long long total_bytes = 0;
    double elapsed_time, download_speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    gettimeofday(&start, NULL);

    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0)
            break;
        total_bytes += bytes_received;
    }

    gettimeofday(&end, NULL);

    close(sockfd);

    elapsed_time = (end.tv_sec + end.tv_usec/1000000.0) -
                   (start.tv_sec + start.tv_usec/1000000.0);

    download_speed = (double) total_bytes / (elapsed_time * 1024.0);

    printf("Downloaded %lld bytes in %.2f seconds, download speed: %.2f Mbps\n",
           total_bytes, elapsed_time, download_speed/1024.0/1024.0);

    return 0;
}