//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct UnitConversion {
    char *name;
    double factor;
};

struct Server {
    int sock;
    struct UnitConversion *conversions;
    int num_conversions;
};

void handle_client(int sock, struct Server *server) {
    char buffer[1024];
    int len = recv(sock, buffer, 1024, 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }
    char *request = buffer;
    char *unit1 = strtok(request, " ");
    char *unit2 = strtok(NULL, " ");
    double value = atof(request);
    for (int i = 0; i < server->num_conversions; i++) {
        if (strcmp(unit1, server->conversions[i].name) == 0) {
            double converted_value = value * server->conversions[i].factor;
            send(sock, "converted value: ", 14, 0);
            send(sock, "%.2f", converted_value, 0);
            send(sock, "\n", 1, 0);
            break;
        }
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }
    struct Server server;
    server.sock = sock;
    server.conversions = malloc(sizeof(struct UnitConversion) * 10);
    server.num_conversions = 10;
    for (int i = 0; i < 10; i++) {
        server.conversions[i].name = malloc(sizeof("inch") + 1);
        server.conversions[i].factor = 1;
        if (i % 2 == 0) {
            server.conversions[i].factor = 0.01;
        }
        strcpy(server.conversions[i].name, "inch");
    }
    listen(sock, 3);
    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client(client_sock, &server);
        close(client_sock);
    }
    return 0;
}