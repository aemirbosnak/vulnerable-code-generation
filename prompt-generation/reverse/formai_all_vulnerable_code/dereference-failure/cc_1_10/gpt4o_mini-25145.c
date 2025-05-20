//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 21
#define MAX_RETRIES 3

void fatal_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        fatal_error("Could not resolve hostname");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fatal_error("Can't create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fatal_error("Connection failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        fatal_error("Failed to receive response");
    }
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);
}

void upload_file(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fatal_error("Could not open file");
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    int retries = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (send(sockfd, buffer, bytes_read, 0) < 0) {
            if (++retries < MAX_RETRIES) {
                printf("Retrying upload...\n");
                fseek(file, 0, SEEK_CUR);
            } else {
                fatal_error("Failed to send file");
            }
        } else {
            retries = 0; // reset retries after a successful send
        }
    }

    fclose(file);
}

void create_ftp_client(const char *hostname, const char *filename) {
    int sockfd = connect_to_server(hostname);
    receive_response(sockfd);

    send_command(sockfd, "USER anonymous");
    receive_response(sockfd);

    send_command(sockfd, "PASS anonymous");
    receive_response(sockfd);

    // Switch to PASV mode to obtain server IP and port
    send_command(sockfd, "PASV");
    receive_response(sockfd);

    // For simplicity, assume a server that uses a static IP:port after PASV
    printf("Connecting to server for data transfer...\n");
    int data_sockfd = connect_to_server("data.server.ip"); // Replace with actual data server IP

    // Send FILE command
    send_command(data_sockfd, "STOR ");
    send_command(data_sockfd, filename);
    receive_response(data_sockfd);

    // Start upload
    upload_file(data_sockfd, filename);
    send_command(data_sockfd, "QUIT");
    receive_response(data_sockfd);

    close(data_sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    create_ftp_client(argv[1], argv[2]);
    printf("Data successfully uploaded to the wasteland servers!\n");

    return 0;
}