//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_HOSTS 1000
#define MAX_THREADS 100

struct host_info {
    char *hostname;
    int port;
};

void *scan_port(void *arg) {
    struct host_info *host = (struct host_info *) arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(host->port);
    inet_pton(AF_INET, host->hostname, &server.sin_addr);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
        close(sock);
        printf("%s:%d is open.\n", host->hostname, host->port);
    } else {
        close(sock);
        printf("%s:%d is closed.\n", host->hostname, host->port);
    }
    return NULL;
}

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    struct host_info hosts[MAX_HOSTS];
    int num_hosts = 0;
    pthread_t threads[MAX_THREADS];

    fp = fopen("hosts.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open hosts file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        if (token!= NULL && num_hosts < MAX_HOSTS) {
            hosts[num_hosts].hostname = strdup(token);
            hosts[num_hosts].port = atoi(strtok(NULL, " "));
            num_hosts++;
        }
    }

    fclose(fp);

    for (int i = 0; i < num_hosts; i++) {
        pthread_create(&threads[i], NULL, scan_port, &hosts[i]);
    }

    for (int i = 0; i < num_hosts; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}