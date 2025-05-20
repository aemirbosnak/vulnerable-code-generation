//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_IP_LEN 15
#define START_PORT 1
#define END_PORT 65535

bool is_port_open(char* ip, int port) {
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    client.sin_addr.s_addr = inet_addr(ip);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {return false;}
    if (connect(sock, (struct sockaddr*)&client, sizeof(client)) == 0) {
        close(sock);
        return true;
    } else {
        close(sock);
        return false;
    }
}

void* scan_ports(void* arg) {
    char* ip = (char*)arg;
    for (int port = START_PORT; port <= END_PORT; port++) {
        if (is_port_open(ip, port)) {
            printf("%s : %d\n", ip, port);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc < 2){
        printf("Usage: a.exe IP\n");
        return 0;
    } else if (argc > 2) {
        printf("Too many arguments.\n");
        return 0;
    }
    char ip[MAX_IP_LEN + 1];
    strncpy(ip, argv[1], MAX_IP_LEN + 1);

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, scan_ports, (void *)ip);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit(NULL);
}