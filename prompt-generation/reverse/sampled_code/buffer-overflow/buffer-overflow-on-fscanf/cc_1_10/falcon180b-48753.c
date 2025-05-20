//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTS 1000
#define MAX_THREADS 50

struct host_info {
    char *hostname;
    int port;
};

void *thread_scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock, retval;
    char buffer[1024];
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(host->port);
    inet_pton(AF_INET, host->hostname, &server.sin_addr);

    retval = connect(sock, (struct sockaddr *) &server, sizeof(server));

    if (retval < 0) {
        printf("Host %s:%d is down\n", host->hostname, host->port);
    } else {
        printf("Host %s:%d is up\n", host->hostname, host->port);
        close(sock);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int i, num_hosts, num_threads;
    char *filename = "hosts.txt";
    FILE *fp;
    struct host_info *hosts;

    if (argc > 1) {
        filename = argv[1];
    }

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Failed to open hosts file\n");
        exit(1);
    }

    num_hosts = 0;
    while (fscanf(fp, "%s:%d", hosts[num_hosts].hostname, &hosts[num_hosts].port)!= EOF) {
        num_hosts++;
    }

    fclose(fp);

    if (num_hosts == 0) {
        printf("Error: No hosts found in file\n");
        exit(1);
    }

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[num_threads];

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_scan_port, &hosts[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}