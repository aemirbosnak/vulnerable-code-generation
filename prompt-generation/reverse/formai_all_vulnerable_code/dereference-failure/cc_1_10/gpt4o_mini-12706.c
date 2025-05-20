//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

typedef struct {
    char *server_ip;
    char *username;
    char *password;
    char *file_path;
} FTPClientDetails;

void *ftp_connect(void *arg) {
    FTPClientDetails *details = (FTPClientDetails *)arg;
    int sockfd;
    struct sockaddr_in server_addr;
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, details->server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        pthread_exit(NULL);
    }

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        pthread_exit(NULL);
    }

    // Receive welcome message
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Send username
    send(sockfd, details->username, strlen(details->username), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Send password
    send(sockfd, details->password, strlen(details->password), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Send file to server
    FILE *file = fopen(details->file_path, "rb");
    if (file == NULL) {
        perror("File not found");
        close(sockfd);
        pthread_exit(NULL);
    }

    // Read file and send to server
    while (1) {
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
        if (bytes_read > 0) {
            send(sockfd, buffer, bytes_read, 0);
        }
        if (bytes_read < sizeof(buffer)) {
            if (feof(file)) {
                printf("File transfer complete.\n");
                break;
            }
            if (ferror(file)) {
                perror("Error reading file");
                break;
            }
        }
    }

    fclose(file);
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password> <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FTPClientDetails *details = malloc(sizeof(FTPClientDetails));
    details->server_ip = argv[1];
    details->username = argv[2];
    details->password = argv[3];
    details->file_path = argv[4];

    pthread_t ftp_thread;
    if (pthread_create(&ftp_thread, NULL, ftp_connect, (void *)details) != 0) {
        perror("Failed to create thread");
        free(details);
        exit(EXIT_FAILURE);
    }

    // Wait for the FTP thread to complete
    pthread_join(ftp_thread, NULL);
    free(details);
    return 0;
}