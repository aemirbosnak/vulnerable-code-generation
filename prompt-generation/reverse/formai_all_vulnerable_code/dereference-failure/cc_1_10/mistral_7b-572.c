//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SERVER_ADDRESS "8.8.8.8"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define NUM_PACKETS 10

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, i;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct timeval start, end;
    double elapsed_time, total_size, avg_speed;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("ERROR opening socket");

    if (gettimeofday(&start, NULL) == -1)
        error("ERROR getting start time");

    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    total_size = 0;
    for (i = 0; i < NUM_PACKETS; i++) {
        if (send(sockfd, "A", 1, 0) == -1)
            error("ERROR sending data");

        memset(buffer, 0, BUFFER_SIZE);
        int received_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (received_bytes <= 0)
            error("ERROR receiving data");

        total_size += received_bytes;
    }

    if (gettimeofday(&end, NULL) == -1)
        error("ERROR getting end time");

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    avg_speed = (total_size / elapsed_time) / NUM_PACKETS;

    printf("Downloaded %lld bytes in %.2f seconds.\n", (long long)total_size, elapsed_time);
    printf("Average speed: %.2f KB/s\n", avg_speed * 1024);

    close(sockfd);
    return 0;
}