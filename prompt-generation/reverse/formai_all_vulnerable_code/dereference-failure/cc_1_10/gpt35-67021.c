//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096
#define MAX_FILENAME_LENGTH 256

int connect_to_server(const char *hostname, const char *port);
bool send_command(int sockfd, const char *command, char *response, size_t max_response_len);
bool receive_data(int sockfd, const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <filename>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *filename = argv[3];

    int sockfd = connect_to_server(hostname, port);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to connect to server\n");
        return 1;
    }

    char response[MAX_RESPONSE_LENGTH];
    if (!send_command(sockfd, "USER anonymous\r\n", response, sizeof(response))) {
        fprintf(stderr, "Failed to send USER command\n");
        return 1;
    }

    if (!send_command(sockfd, "PASS guest\r\n", response, sizeof(response))) {
        fprintf(stderr, "Failed to send PASS command\n");
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    if (!send_command(sockfd, command, response, sizeof(response))) {
        fprintf(stderr, "Failed to send RETR command\n");
        return 1;
    }

    if (!receive_data(sockfd, filename)) {
        fprintf(stderr, "Failed to receive data\n");
        return 1;
    }

    close(sockfd);
    return 0;
}

int connect_to_server(const char *hostname, const char *port) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *result;
    if (getaddrinfo(hostname, port, &hints, &result) != 0) {
        return -1;
    }

    int sockfd = -1;
    struct addrinfo *rp;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }

        close(sockfd);
    }

    freeaddrinfo(result);
    return sockfd;
}

bool send_command(int sockfd, const char *command, char *response, size_t max_response_len) {
    if (write(sockfd, command, strlen(command)) == -1) {
        return false;
    }

    ssize_t num_bytes = read(sockfd, response, max_response_len);
    if (num_bytes == -1) {
        return false;
    }

    response[num_bytes] = '\0';
    return true;
}

bool receive_data(int sockfd, const char *filename) {
    FILE *output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        return false;
    }

    char buffer[MAX_FILENAME_LENGTH];
    ssize_t num_bytes;
    while ((num_bytes = read(sockfd, buffer, sizeof(buffer))) > 0) {
        if (fwrite(buffer, 1, num_bytes, output_file) != num_bytes) {
            fclose(output_file);
            return false;
        }
    }

    fclose(output_file);
    return num_bytes == 0;
}