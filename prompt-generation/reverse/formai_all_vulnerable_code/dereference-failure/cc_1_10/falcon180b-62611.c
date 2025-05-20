//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

struct hostent *host;
int sock;
char *ip;
char buffer[BUFFER_SIZE];
pthread_t threads[MAX_THREADS];
int thread_count = 0;

void *scanner(void *arg) {
    int port = *(int *) arg;
    char *response;

    response = malloc(BUFFER_SIZE);
    if (response == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    if (connect(sock, host->h_addr, host->h_length) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ip);
    send(sock, buffer, strlen(buffer), 0);

    memset(response, 0, BUFFER_SIZE);
    if (recv(sock, response, BUFFER_SIZE, 0) < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Port %d is open\n", port);
    close(sock);
    free(response);
    return NULL;
}

int main() {
    int i, j;
    char domain[100];
    char *ip_addr;
    struct hostent *server;

    printf("Enter the domain name: ");
    scanf("%s", domain);

    host = gethostbyname(domain);
    if (host == NULL) {
        printf("Invalid domain name\n");
        exit(1);
    }

    ip = inet_ntoa(*(struct in_addr *)host->h_addr);

    printf("Enter the number of threads: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        pthread_create(&threads[j], NULL, scanner, (void *)j);
        thread_count++;
    }

    for (j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}