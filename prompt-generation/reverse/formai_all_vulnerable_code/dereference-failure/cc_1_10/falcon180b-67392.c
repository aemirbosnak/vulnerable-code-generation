//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int opt = 1;
    long int bytes_received = 0;
    long int bytes_sent = 0;
    double speed = 0;

    if (argc!= 2) {
        printf("Usage:./client <file_name>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    rewind(fp);

    char *file_buffer = (char *) malloc(file_size);

    if (file_buffer == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    fread(file_buffer, file_size, 1, fp);

    send(sockfd, file_buffer, file_size, 0);

    free(file_buffer);
    fclose(fp);

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            break;
        }

        bytes_received += n;
    }

    speed = (double) bytes_received / (double) file_size;

    printf("File transfer complete.\n");
    printf("Speed: %.2f bytes/sec\n", speed);

    close(sockfd);

    return 0;
}