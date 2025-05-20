//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 1024

struct thread_data {
    int sockfd;
    struct sockaddr_in servaddr;
};

void *download_thread(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;

    int sockfd = data->sockfd;
    struct sockaddr_in servaddr = data->servaddr;

    uint8_t buf[BUF_SIZE];
    ssize_t bytes_recv;

    while ((bytes_recv = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&servaddr, (socklen_t *)sizeof(servaddr))) > 0) {
        // Process received data...
    }

    close(sockfd);
    free(data);
    return NULL;
}

void *upload_thread(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;

    int sockfd = data->sockfd;
    struct sockaddr_in servaddr = data->servaddr;

    uint8_t buf[BUF_SIZE];
    ssize_t bytes_sent;

    while ((bytes_sent = sendto(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&servaddr, (socklen_t)sizeof(servaddr))) > 0) {
        // Generate data to send...
    }

    close(sockfd);
    free(data);
    return NULL;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    // Create threads for downloading and uploading
    pthread_t download_thread_id, upload_thread_id;
    struct thread_data *download_data = malloc(sizeof(struct thread_data));
    download_data->sockfd = sockfd;
    download_data->servaddr = servaddr;
    struct thread_data *upload_data = malloc(sizeof(struct thread_data));
    upload_data->sockfd = sockfd;
    upload_data->servaddr = servaddr;

    pthread_create(&download_thread_id, NULL, download_thread, (void *)download_data);
    pthread_create(&upload_thread_id, NULL, upload_thread, (void *)upload_data);

    // Wait for threads to finish
    pthread_join(download_thread_id, NULL);
    pthread_join(upload_thread_id, NULL);

    close(sockfd);
    return EXIT_SUCCESS;
}