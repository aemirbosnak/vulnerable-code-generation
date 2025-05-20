//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target_host> [start_port] [end_port]\n", argv[0]);
        exit(1);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve host name\n");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr = *((struct in_addr *)server->h_addr_list[0]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error opening socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    char buf[1024];
    int n;
    for (int i = atoi(argv[3]); i <= atoi(argv[4]); i++) {
        printf("Scanning port %d...\n", i);
        send(sock, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", 48, 0);
        n = recv(sock, buf, sizeof(buf), 0);
        if (n > 0) {
            printf("Port %d is open\n", i);
        } else if (n == 0) {
            printf("Port %d is closed\n", i);
        } else {
            perror("Error receiving data");
        }
    }

    close(sock);
    return 0;
}