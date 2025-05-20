//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define PORT 80
#define MAX 100
#define TIME_OUT 10

typedef struct host_info {
    char name[50];
    struct in_addr ip;
} host_info;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[100];
    char *token;
    int count = 0;
    host_info hosts[MAX];
    int sock;
    struct sockaddr_in server;
    int addrlen = sizeof(server);
    int ret;

    if (argc < 2) {
        printf("Usage:./ping <filename>\n");
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        strcpy(hosts[count].name, token);
        hosts[count].ip.s_addr = inet_addr(token);
        count++;
    }

    fclose(fp);

    for (int i = 0; i < count; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: could not create socket.\n");
            continue;
        }

        server.sin_family = AF_INET;
        server.sin_addr.s_addr = hosts[i].ip.s_addr;
        server.sin_port = htons(PORT);

        ret = connect(sock, (struct sockaddr *)&server, addrlen);
        if (ret == -1) {
            printf("Error: could not connect to %s.\n", hosts[i].name);
            close(sock);
            continue;
        }

        printf("Connected to %s.\n", hosts[i].name);
        close(sock);
    }

    return 0;
}