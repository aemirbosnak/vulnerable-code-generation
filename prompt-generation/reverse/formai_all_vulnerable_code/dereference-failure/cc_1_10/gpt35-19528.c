//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>

#define MAX_CONNS 4096
#define DEFAULT_TIMEOUT 2 // seconds

typedef struct {
    int sock;
    char* buffer;
    size_t buffer_size;
    size_t buffer_length;
    size_t offset;
    int newline;
    int done;
} connection_t;

typedef struct {
    char* target;
    int port;
} target_t;

void usage(char* argv[]) {
    fprintf(stderr, "Usage: %s <host> ... <host> -p <port>\n", argv[0]);
    exit(1);
}

int connect_to_host(char* addr, int port, int timeout) {
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        return -1;
    }

    fcntl(sock, F_SETFL, O_NONBLOCK);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(addr, &server_addr.sin_addr);

    connect(sock, (const struct sockaddr*)&server_addr, sizeof(server_addr));

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sock, &fds);

    int res = select(sock+1, NULL, &fds, NULL, &tv);
    if (res == 0) {
        fprintf(stderr, "Timeout connecting to %s:%d\n", addr, port);
        return -1;
    } else if (res < 0) {
        perror("select");
        close(sock);
        return -1;
    }

    int err;
    socklen_t len = sizeof(err);
    getsockopt(sock, SOL_SOCKET, SO_ERROR, &err, &len);
    if (err != 0) {
        fprintf(stderr, "Connect error: %s\n", strerror(err));
        close(sock);
        return -1;
    }

    fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) & ~O_NONBLOCK);

    return sock;
}

void set_nonblocking(int sock) {
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);
}

void set_blocking(int sock) {
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags & ~O_NONBLOCK);
}

connection_t* connect_target(target_t* target) {
    int sock = connect_to_host(target->target, target->port, DEFAULT_TIMEOUT);
    if (sock < 0) {
        return NULL;
    }

    connection_t* conn = malloc(sizeof(connection_t));
    conn->sock = sock;
    conn->buffer_size = 1024;
    conn->buffer = malloc(conn->buffer_size);
    conn->buffer_length = 0;
    conn->offset = 0;
    conn->newline = 0;
    conn->done = 0;

    return conn;
}

void free_connection(connection_t* conn) {
    if (conn != NULL) {
        if (conn->sock > 0) {
            close(conn->sock);
        }
        if (conn->buffer != NULL) {
            free(conn->buffer);
        }
        free(conn);
    }
}

void send_request(connection_t* conn) {
    char* request = "GET /\r\n";
    write(conn->sock, request, strlen(request));
}

void handle_data(connection_t* conn) {
    char* buffer = conn->buffer;
    size_t buffer_size = conn->buffer_size;
    size_t buffer_length = conn->buffer_length;
    size_t offset = conn->offset;
    int newline = conn->newline;

    int done = 0;
    while (!done) {
        char c;
        int n = read(conn->sock, &c, 1);
        if (n < 0 && errno != EAGAIN) {
            conn->done = 1;
            break;
        } else if (n == 0) {
            conn->done = 1;
            break;
        } else if (n > 0) {
            if (buffer_length >= buffer_size) {
                buffer_size *= 2;
                buffer = realloc(buffer, buffer_size);
                conn->buffer = buffer;
                conn->buffer_size = buffer_size;
            }

            buffer[buffer_length++] = c;
            if (c == '\n') {
                newline = 1;
            } else {
                newline = 0;
            }

            if (newline && buffer_length >= 4 &&
                buffer[buffer_length-4] == '\r' &&
                buffer[buffer_length-3] == '\n' &&
                buffer[buffer_length-2] == '\r' &&
                buffer[buffer_length-1] == '\n') {

                buffer[buffer_length] = '\0';
                printf("[%d] Received:\n%s\n", conn->sock, buffer);
                done = 1;
            }
        } else if (n < 0 && errno == EAGAIN) {
            break;
        }
    }

    conn->buffer_length = buffer_length;
    conn->offset = offset;
    conn->newline = newline;
    conn->done = done;
}

void check_connections(connection_t** connections, int num_conns) {
    for (int i = 0; i < num_conns; i++) {
        connection_t* conn = connections[i];
        if (conn->done) {
            printf("[%d] Closing\n", conn->sock);
            free_connection(conn);
            connections[i] = NULL;
        } else {
            handle_data(conn);
        }
    }
}

void add_new_connections(connection_t** connections, int* num_conns, target_t* targets, int num_targets) {
    for (int i = 0; i < num_targets; i++) {
        target_t* target = &targets[i];
        connection_t* conn = connect_target(target);
        if (conn != NULL) {
            printf("[%d] Connected to %s:%d\n", conn->sock, target->target, target->port);
            connections[*num_conns] = conn;
            (*num_conns)++;
        }
    }
}

void run(char* argv[], int argc, int port) {
    target_t targets[argc];
    int num_targets = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            i++;
            port = atoi(argv[i]);
        } else {
            targets[num_targets].target = argv[i];
            targets[num_targets].port = port;
            num_targets++;
        }
    }

    printf("Scanning %d targets on port %d\n", num_targets, port);

    connection_t* connections[MAX_CONNS];
    int num_conns = 0;

    add_new_connections(connections, &num_conns, targets, num_targets);

    while (num_conns > 0) {
        fd_set fds;
        FD_ZERO(&fds);
        int max_fd = -1;
        for (int i = 0; i < num_conns; i++) {
            connection_t* conn = connections[i];
            int sock = conn->sock;
            FD_SET(sock, &fds);
            if (sock > max_fd) {
                max_fd = sock;
            }
        }

        int res = select(max_fd+1, &fds, NULL, NULL, NULL);
        if (res < 0) {
            perror("select");
            break;
        } else if (res == 0) {
            continue;
        } else {
            check_connections(connections, num_conns);
            add_new_connections(connections, &num_conns, targets, num_targets);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        usage(argv);
    }

    int port = 80;
    run(argv, argc, port);

    return 0;
}