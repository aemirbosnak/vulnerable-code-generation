//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
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

#define BUFFER_SIZE 4096
#define FILE_SIZE 1024 * 1024 // 1 MB

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_address = argv[1];
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_exit("socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    if (inet_pton(AF_INET, server_address, &serv_addr.sin_addr) <= 0) {
        error_exit("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error_exit("Connection failed");
    }

    FILE *fp = fopen("testfile.bin", "wb");
    if (!fp) {
        error_exit("Failed to open the output file");
    }

    ssize_t bytes_received;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, elapsed_time, transfer_rate;

    start_time = time(NULL);

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, bytes_received, 1, fp);
    }

    if (bytes_received == -1) {
        error_exit("Error during receiving");
    }

    fclose(fp);
    close(sockfd);

    end_time = time(NULL);
    elapsed_time = end_time - start_time;

    transfer_rate = (double) FILE_SIZE / elapsed_time;

    printf("Transfer rate: %.2f bytes/second\n", transfer_rate);

    return EXIT_SUCCESS;
}