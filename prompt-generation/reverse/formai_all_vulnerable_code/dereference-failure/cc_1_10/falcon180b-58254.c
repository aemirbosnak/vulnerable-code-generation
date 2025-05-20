//Falcon-180B DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024
#define WHITE_LIST_FILE "whitelist.txt"

struct connection {
    int sock;
    struct sockaddr_in addr;
    char *ip;
};

struct rule {
    char *ip;
    bool allow;
};

void *monitor_connections(void *arg);

int main() {
    FILE *fp;
    char line[BUFFER_SIZE];
    struct rule *whitelist = NULL;
    int num_rules = 0;

    fp = fopen(WHITE_LIST_FILE, "r");
    if (fp == NULL) {
        printf("Error opening whitelist file.\n");
        exit(1);
    }

    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        char *ip = strtok(line, " ");
        bool allow = strcmp(ip, "allow") == 0;

        struct rule *rule = malloc(sizeof(struct rule));
        rule->ip = strdup(ip);
        rule->allow = allow;

        whitelist = realloc(whitelist, sizeof(struct rule) * ++num_rules);
        whitelist[num_rules - 1] = *rule;
    }

    fclose(fp);

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket.\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket.\n");
        exit(1);
    }

    printf("Firewall started.\n");

    while (true) {
        sleep(1);
    }

    return 0;
}

void *monitor_connections(void *arg) {
    int client_sock = *(int *)arg;
    close(client_sock);
}