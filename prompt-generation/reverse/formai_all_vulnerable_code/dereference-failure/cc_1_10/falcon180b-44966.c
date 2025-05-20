//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024
#define PORT "3490"

char host[MAX_HOST_LEN];
int port;
int sock;
int status;

void *thread_func(void *arg) {
    char buffer[MAX_DATA_LEN];
    int bytes_received;

    while (1) {
        bytes_received = recv(sock, buffer, MAX_DATA_LEN, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("Received data: %s\n", buffer);
    }

    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    struct hostent *host_info;
    struct sockaddr_in server_addr;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <filename>\n", argv[0]);
        return 1;
    }

    strcpy(host, argv[1]);
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Error resolving hostname\n");
        close(sock);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *)host_info->h_addr;

    status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, NULL);

    FILE *fp;
    fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        close(sock);
        return 1;
    }

    char line[MAX_DATA_LEN];
    while (fgets(line, MAX_DATA_LEN, fp)!= NULL) {
        send(sock, line, strlen(line), 0);
    }

    fclose(fp);

    close(sock);
    return 0;
}