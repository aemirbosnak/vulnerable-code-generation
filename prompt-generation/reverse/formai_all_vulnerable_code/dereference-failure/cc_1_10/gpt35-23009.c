//FormAI DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <errno.h>

#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 5

int ping(const char *addr, int port, int timeout) {
    struct sockaddr_in server_address;
    struct hostent *he;
    int socket_fd, err_code, ret_code = 0;
    fd_set recv_fds;
    char recv_buf[1024];
    long sec = timeout, usec = 0;
    struct timeval timeout_val = {sec, usec};
    struct sigaction sigact, oldact;

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if ((he = gethostbyname(addr)) == NULL) {
        printf("Error: Cannot resolve %s\n", addr);
        return -1;
    }
    memcpy(&server_address.sin_addr, he->h_addr, he->h_length);

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Cannot create socket\n");
        return -1;
    }

    memset(&sigact, 0, sizeof(sigact));
    sigact.sa_handler = SIG_IGN;
    if (sigaction(SIGPIPE, &sigact, &oldact) == -1) {
        printf("Error: Cannot ignore SIGPIPE\n");
        ret_code = -1;
        goto cleanup;
    }

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error: Connection failed\n");
        ret_code = -1;
        goto cleanup;
    }

    FD_ZERO(&recv_fds);
    FD_SET(socket_fd, &recv_fds);
    err_code = select(socket_fd + 1, &recv_fds, NULL, NULL, &timeout_val);
    if (err_code == -1) {
        printf("Error: %s\n", strerror(errno));
        ret_code = -1;
        goto cleanup;
    } else if (err_code == 0) {
        printf("Error: Timeout occurred\n");
        ret_code = -1;
        goto cleanup;
    }

    if (FD_ISSET(socket_fd, &recv_fds)) {
        if (recv(socket_fd, recv_buf, sizeof(recv_buf), 0) == -1) {
            printf("Error: Unable to receive data\n");
            ret_code = -1;
            goto cleanup;
        }
        printf("Connection successful!\n");
    }

cleanup:
    close(socket_fd);
    sigaction(SIGPIPE, &oldact, NULL);
    return ret_code;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <address> [<port>] [<timeout>]\n", argv[0]);
        return -1;
    }

    int port = DEFAULT_PORT, timeout = DEFAULT_TIMEOUT;
    if (argc >= 3) {
        port = atoi(argv[2]);
        if (port < 1 || port > 65535) {
            printf("Error: Invalid port number %s\n", argv[2]);
            return -1;
        }
    }

    if (argc >= 4) {
        timeout = atoi(argv[3]);
        if (timeout < 1) {
            printf("Error: Invalid timeout %s\n", argv[3]);
            return -1;
        }
    }

    printf("Pinging %s:%d with a timeout of %d seconds\n", argv[1], port, timeout);

    if (ping(argv[1], port, timeout) == 0) {
        printf("Ping successful!\n");
        return 0;
    } else {
        printf("Ping failed!\n");
        return -1;
    }
}