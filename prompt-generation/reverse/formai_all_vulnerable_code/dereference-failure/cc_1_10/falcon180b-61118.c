//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char hostname[100];
    double start_time, end_time;
    double total_time;
    int bytes_received = 0;

    if (argc < 3) {
        printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    start_time = clock();

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        bytes_received += n;
        printf("%s", buffer);
    }

    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTotal time taken: %lf seconds\n", total_time);
    printf("Bytes received: %d\n", bytes_received);

    close(sockfd);
    return 0;
}