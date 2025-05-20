//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

// Thread function to download data
void *download_thread(void *arg) {
    int sockfd = *((int *)arg);
    char buffer[1024];
    long int bytes_received = 0;

    // While there is data to receive, receive it and increment the bytes received count
    while (true) {
        int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_read < 0) {
            perror("recv");
            break;
        } else if (bytes_read == 0) {
            break;
        }
        bytes_received += bytes_read;
    }

    // Close the socket and return the number of bytes received
    close(sockfd);
    return (void *)bytes_received;
}

// Thread function to upload data
void *upload_thread(void *arg) {
    int sockfd = *((int *)arg);
    char buffer[1024];
    long int bytes_sent = 0;

    // While there is data to send, send it and increment the bytes sent count
    while (true) {
        int bytes_written = send(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_written < 0) {
            perror("send");
            break;
        } else if (bytes_written == 0) {
            break;
        }
        bytes_sent += bytes_written;
    }

    // Close the socket and return the number of bytes sent
    close(sockfd);
    return (void *)bytes_sent;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Get the host and port from the command line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) < 0) {
        perror("inet_pton");
        close(sockfd);
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    // Create threads for downloading and uploading data
    pthread_t download_thread_id, upload_thread_id;
    if (pthread_create(&download_thread_id, NULL, download_thread, &sockfd) != 0) {
        perror("pthread_create");
        close(sockfd);
        return 1;
    }
    if (pthread_create(&upload_thread_id, NULL, upload_thread, &sockfd) != 0) {
        perror("pthread_create");
        close(sockfd);
        return 1;
    }

    // Wait for the threads to finish
    long int bytes_received = (long int)pthread_join(download_thread_id, NULL);
    long int bytes_sent = (long int)pthread_join(upload_thread_id, NULL);

    // Close the socket
    close(sockfd);

    // Print the results
    printf("Received: %ld bytes\n", bytes_received);
    printf("Sent: %ld bytes\n", bytes_sent);

    return 0;
}