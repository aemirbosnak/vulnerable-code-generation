//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define INTERVAL 1 //seconds

void print_usage(char *prog) {
    printf("Usage: %s <hostname>\n", prog);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);
    hostname[MAX_HOSTNAME - 1] = '\0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Unknown host: %s\n", hostname);
        close(sock);
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(7); //echo port
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    char buffer[MAX_DATA];
    int bytes_received;
    time_t start_time = time(NULL);

    while (1) {
        bytes_received = recv(sock, buffer, MAX_DATA, 0);
        if (bytes_received <= 0) {
            break;
        }
        time_t current_time = time(NULL);
        if (difftime(current_time, start_time) >= INTERVAL) {
            printf("Received %d bytes in %ld seconds\n", bytes_received, current_time - start_time);
            start_time = current_time;
        }
    }

    close(sock);
    return 0;
}