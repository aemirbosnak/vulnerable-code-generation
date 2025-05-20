//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_PACKET_SIZE 4096
#define MAX_THREADS 100
#define TIMEOUT 5
#define QOS_THRESHOLD 100

int g_total_size = 0;
int g_threads = 0;
int g_exit_threads = 0;
float g_qos = 0;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int id;
    char* ip;
    int port;
    int timeout;
} ThreadArgs;

void* thread_function(void* arg) {
    
    ThreadArgs* args = (ThreadArgs*) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(args->port);
    if (inet_pton(AF_INET, args->ip, &server_address.sin_addr) <= 0) {
        perror("Error setting server IP address");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }

    struct timeval timeout;
    timeout.tv_sec = args->timeout;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting receive timeout");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Error setting send timeout");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }

    if (connect(sock, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }

    char buffer[MAX_PACKET_SIZE];
    memset(buffer, 0, MAX_PACKET_SIZE);
    int bytes_send = send(sock, buffer, MAX_PACKET_SIZE, 0);
    if (bytes_send < 0) {
        perror("Error sending packet");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }
    char response[MAX_PACKET_SIZE];
    memset(response, 0, MAX_PACKET_SIZE);
    int bytes_received = recv(sock, response, MAX_PACKET_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving packet");
        g_exit_threads = 1;
        pthread_exit(NULL);
    }
    g_exit_threads = 1;

    pthread_mutex_lock(&g_mutex);
    g_total_size += bytes_received;
    float qos = (float)bytes_received / (float)args->timeout;
    g_qos += qos;
    printf("Thread ID %d: Received %d bytes in %d seconds. QoS: %.2f\n", args->id, bytes_received, args->timeout, qos);
    pthread_mutex_unlock(&g_mutex);

    close(sock);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {

    if (argc < 4) {
        printf("usage: %s <ip> <port> <threads> [timeout]\n", argv[0]);
        exit(-1);
    }

    char* ip = argv[1];
    int port = atoi(argv[2]);
    int threads = atoi(argv[3]);
    int timeout = TIMEOUT;
    if (argc >= 5) {
        timeout = atoi(argv[4]);
    }

    printf("Starting %d threads to monitor QoS of %s:%d...\n", threads, ip, port);

    ThreadArgs args[MAX_THREADS];
    pthread_t tid[MAX_THREADS];

    for (int i = 0; i < threads; i++) {
        args[i].id = i + 1;
        args[i].ip = ip;
        args[i].port = port;
        args[i].timeout = timeout;
        if (pthread_create(&tid[i], NULL, thread_function, &args[i]) != 0) {
            perror("Error creating thread");
            exit(-1);
        }
        g_threads++;
    }

    while (g_threads > 0) {
        if (g_exit_threads) {
            g_threads--;
            g_exit_threads = 0;
        }
    }

    g_qos /= threads;
    if (g_qos > QOS_THRESHOLD) {
        printf("Overall QoS is good: %.2f\n", g_qos);
    } else {
        printf("Overall QoS is poor: %.2f\n", g_qos);
    }

    printf("Total received data: %d bytes\n", g_total_size);

    return 0;
}