//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 80
#define BUF_SIZE 4096

struct thread_args {
    int sockfd;
    char *host;
    char *path;
};

void *client_thread(void *args) {
    struct thread_args *t_args = (struct thread_args *)args;
    char buf[BUF_SIZE];
    int n;

    // Send HTTP request
    sprintf(buf, "GET %s HTTP/1.1\nHost: %s\n\n", t_args->path, t_args->host);
    send(t_args->sockfd, buf, strlen(buf), 0);

    // Receive HTTP response
    while ((n = recv(t_args->sockfd, buf, BUF_SIZE, 0)) > 0) {
        printf("%s", buf);
    }

    // Close socket
    close(t_args->sockfd);
    free(t_args);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <path> <num_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_threads = atoi(argv[3]);
    pthread_t threads[num_threads];

    // Create a socket and connect to the server
    struct sockaddr_in server_addr;
    struct hostent *host_info = gethostbyname(argv[1]);
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Create threads and send HTTP requests
    for (int i = 0; i < num_threads; i++) {
        struct thread_args *t_args = malloc(sizeof(struct thread_args));
        t_args->sockfd = sockfd;
        t_args->host = argv[1];
        t_args->path = argv[2];

        pthread_create(&threads[i], NULL, client_thread, (void *)t_args);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}