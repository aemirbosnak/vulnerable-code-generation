//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 4
#define BUFFER_SIZE 1024

void* download_file(void* arg) {
    int* thread_id = (int*) arg;
    int fd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;
    struct hostent* host;
    int port;

    *thread_id = *thread_id + 1;

    if ((host = gethostbyname("www.example.com")) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    port = htons(80);

    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = port;
    server.sin_addr = *((struct in_addr*)host->h_addr);

    if (connect(fd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Downloading file...\n");

    while (1) {
        int bytes_read = read(fd, buffer, BUFFER_SIZE);

        if (bytes_read < 0) {
            perror("read");
            exit(1);
        } else if (bytes_read == 0) {
            break;
        }

        printf("Thread %d: Downloaded %d bytes\n", *thread_id, bytes_read);
    }

    printf("Thread %d: Download complete\n", *thread_id);

    return NULL;
}

int main(int argc, char** argv) {
    int server_fd, port_num, n;
    struct sockaddr_in serv_addr;
    int num_threads = 0;

    if (argc < 3) {
        printf("Usage: %s <server_ip> <file_size>\n", argv[0]);
        return 1;
    }

    port_num = atoi(argv[2]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    listen(server_fd, 5);

    while (1) {
        int client_fd;
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        char buffer[BUFFER_SIZE];
        int size = 0;

        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (recv(client_fd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            close(client_fd);
            continue;
        }

        size = atoi(buffer);

        if (size == 0) {
            printf("File size request\n");
            send(client_fd, buffer, BUFFER_SIZE, 0);
            continue;
        }

        pthread_t threads[MAX_THREADS];
        int i;

        printf("Creating %d threads...\n", MAX_THREADS);

        for (i = 0; i < MAX_THREADS; i++) {
            pthread_create(&threads[i], NULL, download_file, (void*)&i);
        }

        for (i = 0; i < MAX_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        send(client_fd, buffer, BUFFER_SIZE, 0);

        close(client_fd);
    }

    return 0;
}