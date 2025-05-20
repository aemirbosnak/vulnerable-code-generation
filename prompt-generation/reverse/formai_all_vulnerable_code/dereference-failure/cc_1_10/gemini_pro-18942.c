//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define BUFSIZE 1024
#define NUM_THREADS 4

typedef struct {
    int sockfd;
    char *hostname;
    int port;
} thread_args;

void *monitor_thread(void *args) {
    thread_args *t_args = (thread_args *)args;
    int sockfd = t_args->sockfd;
    char *hostname = t_args->hostname;
    int port = t_args->port;

    // Establish connection to the server
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Send and receive data in a loop
    while (1) {
        // Generate a random message
        char buf[BUFSIZE];
        sprintf(buf, "Hello from client %d at %ld!", sockfd, time(NULL));

        // Send the message to the server
        send(sockfd, buf, strlen(buf), 0);

        // Receive and print the response from the server
        int n = recv(sockfd, buf, BUFSIZE, 0);
        if (n > 0) {
            buf[n] = '\0';
            printf("Received from server %s: %s\n", hostname, buf);
        }
    }

    return NULL;
}

int main() {
    // Create a socket for each thread
    int sockfds[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        sockfds[i] = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfds[i] == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
    }

    // Specify the hosts and ports to connect to
    char *hostnames[] = {"localhost", "google.com", "facebook.com", "twitter.com"};
    int ports[] = {80, 443, 8080, 8443};

    // Create a thread for each host/port combination
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args *t_args = malloc(sizeof(thread_args));
        t_args->sockfd = sockfds[i];
        t_args->hostname = hostnames[i];
        t_args->port = ports[i];
        pthread_create(&threads[i], NULL, monitor_thread, (void *)t_args);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close the sockets
    for (int i = 0; i < NUM_THREADS; i++) {
        close(sockfds[i]);
    }

    return 0;
}