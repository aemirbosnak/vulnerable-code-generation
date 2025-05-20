//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>

static bool running = true;

static void sigint_handler(int signo)
{
    running = false;
}

static void *tcp_listener_thread(void *arg)
{
    int sockfd = (int)arg;

    while (running)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd < 0)
        {
            perror("accept");
            continue;
        }

        char buffer[1024];
        int bytes_read = read(client_sockfd, buffer, sizeof(buffer) - 1);
        if (bytes_read < 0)
        {
            perror("read");
            close(client_sockfd);
            continue;
        }

        buffer[bytes_read] = '\0';

        printf("Received message from client: %s\n", buffer);

        char *response = "Hello, world!";
        int bytes_written = write(client_sockfd, response, strlen(response));
        if (bytes_written < 0)
        {
            perror("write");
            close(client_sockfd);
            continue;
        }

        close(client_sockfd);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    if (port <= 0 || port > 65535)
    {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0)
    {
        perror("fcntl(F_GETFL)");
        close(sockfd);
        return EXIT_FAILURE;
    }

    flags |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, flags) < 0)
    {
        perror("fcntl(F_SETFL)");
        close(sockfd);
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind");
        close(sockfd);
        return EXIT_FAILURE;
    }

    if (listen(sockfd, 5) < 0)
    {
        perror("listen");
        close(sockfd);
        return EXIT_FAILURE;
    }

    signal(SIGINT, sigint_handler);

    pthread_t tcp_listener_thread_id;
    if (pthread_create(&tcp_listener_thread_id, NULL, tcp_listener_thread, (void *)sockfd) != 0)
    {
        perror("pthread_create");
        close(sockfd);
        return EXIT_FAILURE;
    }

    while (running)
    {
        sleep(1);
    }

    pthread_join(tcp_listener_thread_id, NULL);
    close(sockfd);

    return EXIT_SUCCESS;
}