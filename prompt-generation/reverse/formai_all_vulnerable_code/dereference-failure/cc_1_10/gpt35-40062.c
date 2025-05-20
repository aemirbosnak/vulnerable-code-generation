//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define DEFAULT_PORT 80
#define MAX_THREADS 10

/* Struct for holding thread data */
typedef struct {
    int id;
    char* host;
    unsigned int addr;
    int port;
    int alive;
} thread_data_t;

/* Function prototypes */
void* ping_host(void* arg);
unsigned int get_ip_addr(char* host);

/* Main function */
int main(int argc, char* argv[]) {
    /* Check for correct number of arguments */
    if(argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    /* Get host IP address */
    unsigned int host_addr = get_ip_addr(argv[1]);
    if(host_addr == 0) {
        printf("Unable to resolve host '%s'\n", argv[1]);
        return 1;
    }

    /* Create list of thread data */
    thread_data_t threads[MAX_THREADS];
    for(int i = 0; i < MAX_THREADS; i++) {
        threads[i].id = i;
        threads[i].host = argv[1];
        threads[i].addr = host_addr;
        threads[i].port = DEFAULT_PORT;
        threads[i].alive = 0;
    }

    /* Start threads */
    printf("Starting ping test...\n");
    pthread_t tid[MAX_THREADS];
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&tid[i], NULL, ping_host, &threads[i]);
    }

    /* Wait for threads to finish */
    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    /* Print results */
    int total_alive = 0;
    printf("\nPing test results:\n");
    for(int i = 0; i < MAX_THREADS; i++) {
        printf("Thread %d: %s:%d is %s\n", threads[i].id, threads[i].host, threads[i].port, threads[i].alive ? "UP" : "DOWN");
        total_alive += threads[i].alive;
    }
    printf("\n%d of %d hosts are UP\n", total_alive, MAX_THREADS);

    return 0;
}

/* Thread function for pinging host */
void* ping_host(void* arg) {
    /* Get thread data */
    thread_data_t* data = (thread_data_t*) arg;

    /* Create socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket() error");
        exit(1);
    }

    /* Set sockaddr_in struct */
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = data->addr;
    addr.sin_port = htons(data->port);

    /* Connect to host */
    if(connect(sock, (struct sockaddr*) &addr, sizeof(addr)) != -1) {
        data->alive = 1;
    }

    /* Close socket and return */
    close(sock);
    return NULL;
}

/* Function for getting IP address of hostname */
unsigned int get_ip_addr(char* host) {
    struct hostent* he;
    he = gethostbyname(host);
    if(he == NULL) {
        return 0;
    }
    return *(unsigned int*) he->h_addr;
}