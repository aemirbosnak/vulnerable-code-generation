//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define MAX_THREADS 5

typedef struct {
    char *hostname;
    int port;
    char *username;
    char *password;
    char *filename;
    char *operation; // "upload" or "download"
} FTPRequest;

void *ftp_transfer(void *arg) {
    FTPRequest *request = (FTPRequest *)arg;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Establish a connection
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(request->port);
    inet_pton(AF_INET, request->hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return NULL;
    }

    // Read server response
    recv(sock, buffer, sizeof(buffer), 0);
    printf("[FTP Client] %s\n", buffer);

    // Send username
    sprintf(buffer, "USER %s\r\n", request->username);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("[FTP Client] %s\n", buffer);

    // Send password
    sprintf(buffer, "PASS %s\r\n", request->password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("[FTP Client] %s\n", buffer);

    // Handle upload or download
    if (strcmp(request->operation, "upload") == 0) {
        FILE *file = fopen(request->filename, "rb");
        if (!file) {
            perror("File open failed");
            close(sock);
            return NULL;
        }

        sprintf(buffer, "STOR %s\r\n", request->filename);
        send(sock, buffer, strlen(buffer), 0);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("[FTP Client] %s\n", buffer);

        while (!feof(file)) {
            size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
            send(sock, buffer, bytes_read, 0);
        }
        fclose(file);
    } else if (strcmp(request->operation, "download") == 0) {
        sprintf(buffer, "RETR %s\r\n", request->filename);
        send(sock, buffer, strlen(buffer), 0);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("[FTP Client] %s\n", buffer);

        FILE *file = fopen(request->filename, "wb");
        if (!file) {
            perror("File open failed");
            close(sock);
            return NULL;
        }

        while (1) {
            ssize_t bytes_received = recv(sock, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) break;
            fwrite(buffer, 1, bytes_received, file);
        }
        fclose(file);
    }

    // Close the connection
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 6) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password> <filename> <operation>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *filename = argv[4];
    char *operation = argv[5];

    FTPRequest request = {hostname, PORT, username, password, filename, operation};
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Create a thread for the FTP transfer
    if (pthread_create(&threads[thread_count++], NULL, ftp_transfer, (void *)&request)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Join threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("[FTP Client] Operation complete.\n");
    return 0;
}