//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define DEFAULT_PORT 21
#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void ftp_send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        die("Failed to send command");
    }
}

void ftp_receive_response(int sockfd, char *response, size_t size) {
    int bytes_received = recv(sockfd, response, size - 1, 0);
    if (bytes_received < 0) {
        die("Failed to receive response");
    }
    response[bytes_received] = '\0'; // Null-terminate the response
    printf("Response: %s\n", response);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd, response, sizeof(response));

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd, response, sizeof(response));
}

void ftp_upload_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        die("Failed to open the file for upload");
    }

    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "STOR %s\r\n", filename);
    ftp_send_command(sockfd, command);
    ftp_receive_response(sockfd, response, sizeof(response));

    while (1) {
        size_t bytes_read = fread(response, 1, sizeof(response), file);
        if (bytes_read > 0) {
            send(sockfd, response, bytes_read, 0);
        }
        if (bytes_read < sizeof(response)) {
            break; // End of file
        }
    }

    fclose(file);
    printf("File uploaded successfully.\n");
}

void ftp_connect(const char *hostname, const char *username, const char *password, const char *filename) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        die("Failed to create socket");
    }

    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        die("Failed to resolve hostname");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(DEFAULT_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Failed to connect to server");
    }

    char response[BUFFER_SIZE];
    ftp_receive_response(sockfd, response, sizeof(response));

    ftp_login(sockfd, username, password);
    ftp_upload_file(sockfd, filename);

    snprintf(response, sizeof(response), "QUIT\r\n");
    ftp_send_command(sockfd, response);
    ftp_receive_response(sockfd, response, sizeof(response));

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *filename = argv[4];

    ftp_connect(hostname, username, password, filename);

    return 0;
}