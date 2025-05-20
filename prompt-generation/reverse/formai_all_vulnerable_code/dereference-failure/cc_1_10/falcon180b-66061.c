//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

void error(const char* msg) {
    perror(msg);
    exit(1);
}

void log(const char* fmt,...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    va_end(ap);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        error("Usage:./qos_monitor <ip_address> <port_number>");
    }

    char* ip = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip, NULL, &hints, &res)!= 0) {
        error("getaddrinfo() error");
    }

    int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        error("socket() error");
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        error("connect() error");
    }

    char recv_buf[BUF_SIZE];
    while (1) {
        int bytes_received = recv(sock, recv_buf, BUF_SIZE, 0);
        if (bytes_received == -1) {
            error("recv() error");
        } else if (bytes_received == 0) {
            log("Connection closed by server\n");
            break;
        }

        char* pkt_start = recv_buf;
        while (pkt_start < recv_buf + bytes_received) {
            if (*pkt_start == '\r') {
                char* pkt_end = pkt_start + 1;
                while (pkt_end < recv_buf + bytes_received && *pkt_end!= '\n') {
                    pkt_end++;
                }
                if (pkt_end >= recv_buf + bytes_received) {
                    break;
                }
                *pkt_end = '\0';
                log("%s", pkt_start);
            }
            pkt_start++;
        }
    }

    close(sock);
    return 0;
}