//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *hostname;
    int port;
    int sock;
    struct addrinfo *addr;
} connection_t;

void print_error(char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(connection_t *conn) {
    int ret;
    if ((ret = getaddrinfo(conn->hostname, NULL, NULL, &conn->addr))!= 0) {
        print_error("getaddrinfo");
    }
    if ((conn->sock = socket(conn->addr->ai_family, conn->addr->ai_socktype, conn->addr->ai_protocol)) == -1) {
        print_error("socket");
    }
    if ((ret = connect(conn->sock, conn->addr->ai_addr, conn->addr->ai_addrlen)) == -1) {
        print_error("connect");
    }
    return 0;
}

int read_from_socket(int sock, char *buffer, int size) {
    int ret;
    if ((ret = recv(sock, buffer, size, 0)) == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            return 0;
        }
        print_error("recv");
    }
    return ret;
}

int write_to_socket(int sock, char *buffer, int size) {
    int ret;
    if ((ret = send(sock, buffer, size, 0)) == -1) {
        print_error("send");
    }
    return ret;
}

int main() {
    connection_t conn;
    char buffer[BUFFER_SIZE];
    int size;

    conn.hostname = "example.com";
    conn.port = 80;
    if (connect_to_server(&conn)!= 0) {
        return 1;
    }

    while (1) {
        size = read_from_socket(conn.sock, buffer, BUFFER_SIZE);
        if (size <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }

    close(conn.sock);
    freeaddrinfo(conn.addr);
    return 0;
}