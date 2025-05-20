//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_HOSTS 100
#define TIMEOUT 5

typedef struct host_t {
    char name[64];
    struct sockaddr_in address;
} host_t;

int main(int argc, char* argv[]) {
    int num_hosts = 0;
    host_t hosts[MAX_HOSTS];
    char input_buffer[BUFFER_SIZE];
    char* token;

    // Read input file
    FILE* input_file = fopen("hosts.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(input_buffer, BUFFER_SIZE, input_file)!= NULL) {
        token = strtok(input_buffer, "\n");
        if (token!= NULL) {
            strcpy(hosts[num_hosts].name, token);
            if (inet_pton(AF_INET, token, &hosts[num_hosts].address.sin_addr) <= 0) {
                fprintf(stderr, "Error: Invalid hostname or IP address: %s\n", token);
                return 1;
            }
            num_hosts++;
        }
    }

    fclose(input_file);

    // Ping each host
    for (int i = 0; i < num_hosts; i++) {
        printf("Pinging %s...\n", hosts[i].name);
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            fprintf(stderr, "Error: Could not create socket.\n");
            return 1;
        }

        struct sockaddr_in server_addr;
        memcpy(&server_addr, &hosts[i].address, sizeof(struct sockaddr_in));

        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in))!= 0) {
            close(sock);
            fprintf(stderr, "Error: Could not connect to %s.\n", hosts[i].name);
            continue;
        }

        char recv_buffer[BUFFER_SIZE];
        if (recv(sock, recv_buffer, BUFFER_SIZE, 0) <= 0) {
            close(sock);
            fprintf(stderr, "Error: Could not receive data from %s.\n", hosts[i].name);
            continue;
        }

        close(sock);
        printf("Successfully pinged %s.\n\n", hosts[i].name);
    }

    return 0;
}