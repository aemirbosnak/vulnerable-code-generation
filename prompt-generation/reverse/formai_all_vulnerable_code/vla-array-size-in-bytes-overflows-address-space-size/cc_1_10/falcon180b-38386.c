//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 50
#define BUFFER_SIZE 1024

int ports[MAX_THREADS];

void *thread_func(void *arg) {
    int port = *(int *) arg;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d is closed\n", port);
        close(sock);
        return NULL;
    }

    printf("Port %d is open\n", port);
    close(sock);
    return NULL;
}

int main() {
    int num_ports = 0;
    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    if (num_ports > MAX_THREADS) {
        printf("Error: Too many ports\n");
        return 1;
    }

    printf("Enter the ports to scan (comma-separated): ");
    char input[BUFFER_SIZE];
    scanf("%s", input);

    char *token = strtok(input, ",");
    while (token!= NULL) {
        ports[num_ports] = atoi(token);
        num_ports++;
        token = strtok(NULL, ",");
    }

    pthread_t threads[num_ports];

    for (int i = 0; i < num_ports; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &ports[i]);
    }

    for (int i = 0; i < num_ports; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}