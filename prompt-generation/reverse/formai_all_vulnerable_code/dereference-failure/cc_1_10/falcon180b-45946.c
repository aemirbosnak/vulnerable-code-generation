//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 64
#define MAX_DATA 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    char hostname[MAX_HOSTNAME];
    int port;
} host_t;

int main(int argc, char *argv[]) {
    int i, j, num_hosts, max_attempts, attempts, response_time;
    host_t *hosts;
    char *response;
    struct sockaddr_in server_addr;
    int sock;

    if(argc < 4) {
        printf("Usage: %s <hostname> <port> <max_attempts>\n", argv[0]);
        exit(1);
    }

    strcpy(hosts[0].hostname, argv[1]);
    hosts[0].port = atoi(argv[2]);
    max_attempts = atoi(argv[3]);

    num_hosts = 1;
    hosts = (host_t *) malloc(num_hosts * sizeof(host_t));

    for(i = 0; i < num_hosts; i++) {
        strcpy(hosts[i].hostname, argv[1]);
        hosts[i].port = atoi(argv[2]);
    }

    for(i = 0; i < num_hosts; i++) {
        attempts = 0;
        while(attempts < max_attempts) {
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if(sock == -1) {
                printf("Error creating socket\n");
                exit(1);
            }

            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(hosts[i].port);
            inet_pton(AF_INET, hosts[i].hostname, &server_addr.sin_addr);

            if(connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
                printf("Error connecting to %s:%d\n", hosts[i].hostname, hosts[i].port);
                close(sock);
                attempts++;
                continue;
            }

            response_time = 0;
            response = (char *) malloc(MAX_DATA);
            memset(response, 0, MAX_DATA);

            while(response_time < 5000) {
                if(recv(sock, response, MAX_DATA, 0) == -1) {
                    printf("Error receiving data from %s:%d\n", hosts[i].hostname, hosts[i].port);
                    close(sock);
                    attempts++;
                    response_time = 0;
                    break;
                }

                response_time += strlen(response);
            }

            close(sock);

            printf("Response from %s:%d in %d milliseconds\n", hosts[i].hostname, hosts[i].port, response_time);

            attempts++;
        }
    }

    free(hosts);
    return 0;
}