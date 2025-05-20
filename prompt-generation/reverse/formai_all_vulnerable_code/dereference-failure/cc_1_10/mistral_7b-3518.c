//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5000

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, transfer_time;
    long long file_size;
    unsigned long long total_received, total_expected;

    if (argc < 3) {
        printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send request for file size
    send(sockfd, "SIZE\0", 5, 0);
    recv(sockfd, &file_size, sizeof(file_size), 0);

    // Set up timer for transfer
    start_time = time(NULL);

    // Download file
    total_received = 0;
    while (total_received < file_size) {
        n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        send(sockfd, "ACK\0", 4, 0);
        printf("%ld bytes received: %s\n", total_received + n, buffer);
        total_received += n;
    }

    // Calculate transfer time
    end_time = time(NULL);
    transfer_time = end_time - start_time;

    printf("Total transfer time: %.2f seconds\n", transfer_time);
    printf("Transfer rate: %.2f KB/s\n", (total_received / transfer_time) * 0.001);

    close(sockfd);
    return 0;
}