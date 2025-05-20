//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100

int ports[MAX_PORTS];
int num_ports = 0;

void *thread_func(void *arg) {
    int port = *(int *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        close(sock);
        printf("Port %d is open.\n", port);
    } else {
        close(sock);
    }

    return NULL;
}

int main() {
    int num_threads = 0;

    printf("Enter the number of threads to use (max %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    printf("Enter the ports to scan (comma-separated): ");
    char ports_str[1024];
    scanf("%s", ports_str);

    char *token = strtok(ports_str, ",");
    while (token!= NULL) {
        int port = atoi(token);
        if (port >= 0 && port <= 65535) {
            ports[num_ports++] = port;
        }
        token = strtok(NULL, ",");
    }

    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &ports[i * MAX_PORTS / num_threads]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}