//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
 
#define BUFFER_SIZE 1024

int create_socket(char *ip_addr, int port);
void handle_error(char *error_msg);
void send_file(int sockfd, char *filename);
void receive_file(int sockfd, char *filename);

int main(int argc, char *argv[]) {
    if(argc != 5) {
        printf("Usage: %s <server_ip> <server_port> <filename> <send/receive>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = create_socket(argv[1], atoi(argv[2]));
    char *filename = argv[3];
    char *action = argv[4];

    if(strcmp(action, "send") == 0) {
        send_file(sockfd, filename);
    } else if(strcmp(action, "receive") == 0) {
        receive_file(sockfd, filename);
    } else {
       printf("Invalid action specified. Please use either send or receive.\n");
       exit(EXIT_FAILURE);
    }

    close(sockfd);
    return 0;
}

int create_socket(char *ip_addr, int port) {
    int sockfd;
    struct sockaddr_in server_address;

    if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        handle_error("Error: Could not create socket");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if(inet_pton(AF_INET, ip_addr, &server_address.sin_addr) == -1) {
        handle_error("Error: IP address translation failed");
    }

    if(connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        handle_error("Error: Could not connect to server");
    }

    return sockfd;
}

void handle_error(char *error_msg) {
    perror(error_msg);
    exit(EXIT_FAILURE);
}

void send_file(int sockfd, char *filename) {
    int file_fd;
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes_read, num_bytes_sent;
    off_t total_bytes_sent = 0;

    if((file_fd = open(filename, O_RDONLY)) == -1) {
        handle_error("Error: Could not open file");
    }

    while((num_bytes_read = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
        if((num_bytes_sent = send(sockfd, buffer, num_bytes_read, 0)) == -1) {
            handle_error("Error: Could not send file");
        }
        total_bytes_sent += num_bytes_sent;
    }

    printf("%lld bytes sent successfully\n", (long long)total_bytes_sent);
    close(file_fd);
}

void receive_file(int sockfd, char *filename) {
    int file_fd;
    char buffer[BUFFER_SIZE];
    ssize_t num_bytes_received, num_bytes_written;
    off_t total_bytes_received = 0;

    if((file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
        handle_error("Error: Could not create file");
    }

    while((num_bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        if((num_bytes_written = write(file_fd, buffer, num_bytes_received)) != num_bytes_received) {
            handle_error("Error: Could not write to file");
        }
        total_bytes_received += num_bytes_received;
    }

    printf("%lld bytes received successfully\n", (long long)total_bytes_received);
    close(file_fd);
}