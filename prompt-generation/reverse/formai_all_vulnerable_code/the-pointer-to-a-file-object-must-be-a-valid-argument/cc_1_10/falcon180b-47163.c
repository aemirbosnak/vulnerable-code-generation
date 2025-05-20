//Falcon-180B DATASET v1.0 Category: Firewall ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024
#define WHITE_LIST_FILE "whitelist.txt"
#define BLACK_LIST_FILE "blacklist.txt"
#define LOG_FILE "firewall.log"

struct connection {
    int sock;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    int buffer_len;
};

void *handle_connection(void *arg) {
    struct connection *conn = (struct connection *) arg;
    char request[BUFFER_SIZE];
    int request_len;

    while ((request_len = recv(conn->sock, request, BUFFER_SIZE, 0)) > 0) {
        request[request_len] = '\0';

        FILE *whitelist_file = fopen(WHITE_LIST_FILE, "r");
        char whitelist_line[BUFFER_SIZE];

        while (fgets(whitelist_line, BUFFER_SIZE, whitelist_file)!= NULL) {
            if (strstr(request, whitelist_line)!= NULL) {
                send(conn->sock, "HTTP/1.1 200 OK\r\nContent-Length: 0\r\nConnection: close\r\n\r\n", 78, 0);
                break;
            }
        }

        fclose(whitelist_file);

        FILE *blacklist_file = fopen(BLACK_LIST_FILE, "r");
        char blacklist_line[BUFFER_SIZE];

        while (fgets(blacklist_line, BUFFER_SIZE, blacklist_file)!= NULL) {
            if (strstr(request, blacklist_line)!= NULL) {
                send(conn->sock, "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\nConnection: close\r\n\r\n", 78, 0);
                break;
            }
        }

        fclose(blacklist_file);
    }

    close(conn->sock);
    free(conn);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, MAX_CONNECTIONS);

    printf("Firewall started on port 80\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_len);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_connection, (void *) &client_sock);
    }

    return 0;
}