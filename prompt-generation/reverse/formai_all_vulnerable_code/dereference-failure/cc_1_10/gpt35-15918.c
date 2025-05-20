//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int connect_to_server(char* hostname, char* port);
void receive_file(int sockfd, char* filename);
void send_file(int sockfd, char* filename);

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [hostname] [port] [filename]\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    char* port = argv[2];
    char* filename = argv[3];

    int sockfd = connect_to_server(hostname, port);

    send_file(sockfd, filename);

    receive_file(sockfd, filename);

    close(sockfd);

    return 0;
}

int connect_to_server(char* hostname, char* port) {
    struct addrinfo hints, *result, *p;
    int sockfd, retval;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((retval = getaddrinfo(hostname, port, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
        exit(1);
    }

    for (p = result; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
            continue;

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server: %s\n", strerror(errno));
        exit(1);
    }

    freeaddrinfo(result);

    printf("Connected to server\n");

    return sockfd;
}

void receive_file(int sockfd, char* filename) {
    char buffer[BUFFER_SIZE];

    FILE* file_ptr = fopen(filename, "wb");

    if (file_ptr == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
        exit(1);
    }

    size_t bytes_received;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file_ptr);
    }

    fclose(file_ptr);
}

void send_file(int sockfd, char* filename) {
    char buffer[BUFFER_SIZE];

    FILE* file_ptr = fopen(filename, "rb");

    if (file_ptr == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
        exit(1);
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file_ptr)) > 0) {
        send(sockfd, buffer, bytes_read, 0);
    }

    fclose(file_ptr);
}