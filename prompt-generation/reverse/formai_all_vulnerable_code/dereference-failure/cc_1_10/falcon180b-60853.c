//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LENGTH 1024
#define TEMP_FILE "/tmp/temperature"

typedef struct {
    char ip[16];
    int port;
} server_t;

void read_servers_from_file(server_t *servers, int *num_servers) {
    char line[MAX_LENGTH];
    FILE *fp;
    int count = 0;

    fp = fopen(TEMP_FILE, "r");
    if (fp == NULL) {
        printf("Error: Unable to open %s\n", TEMP_FILE);
        exit(1);
    }

    while (fgets(line, MAX_LENGTH, fp)!= NULL) {
        servers[count].port = atoi(strtok(line, " "));
        strcpy(servers[count].ip, strtok(NULL, " "));
        count++;
    }

    *num_servers = count;
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int num_servers = 0;
    server_t servers[10];

    read_servers_from_file(servers, &num_servers);

    for (int i = 0; i < num_servers; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: Unable to create socket\n");
            exit(1);
        }

        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        inet_pton(AF_INET, servers[i].ip, &serv_addr.sin_addr);
        serv_addr.sin_port = htons(servers[i].port);

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("Error: Unable to connect to server %s:%d\n", servers[i].ip, servers[i].port);
            exit(1);
        }

        char buf[MAX_LENGTH];
        while (fgets(buf, MAX_LENGTH, stdin)!= NULL) {
            send(sock, buf, strlen(buf), 0);
        }

        close(sock);
    }

    return 0;
}