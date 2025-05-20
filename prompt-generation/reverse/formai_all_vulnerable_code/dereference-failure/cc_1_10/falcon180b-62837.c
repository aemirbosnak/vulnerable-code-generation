//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

void *scan_port(void *arg)
{
    int sock = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1)
    {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0)
        {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(sock);
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    int port;
    char *ip_address;
    int sock;
    int opt = 1;
    struct sockaddr_in server_addr;

    if (argc!= 3)
    {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return -1;
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        printf("Error creating socket\n");
        return -1;
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        close(sock);
        return -1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    while (thread_count < MAX_THREADS)
    {
        pthread_create(&threads[thread_count], NULL, scan_port, &sock);
        thread_count++;
    }

    for (int i = 0; i < thread_count; i++)
    {
        pthread_join(threads[i], NULL);
    }

    close(sock);

    return 0;
}