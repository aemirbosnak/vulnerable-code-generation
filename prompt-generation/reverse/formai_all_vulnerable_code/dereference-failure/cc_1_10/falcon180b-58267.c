//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

static int create_socket(int domain, int type, int protocol)
{
    int sock = socket(domain, type, protocol);
    if (sock == -1) {
        printf("Error: socket() failed: %s\n", strerror(errno));
        exit(1);
    }
    return sock;
}

static int connect_to_server(const char* hostname, int port)
{
    int sock = create_socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) == -1) {
        printf("Error: inet_pton() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    return sock;
}

static int send_request(int sock, const char* request)
{
    int bytes_sent = send(sock, request, strlen(request), 0);
    if (bytes_sent == -1) {
        printf("Error: send() failed: %s\n", strerror(errno));
        exit(1);
    }
    return bytes_sent;
}

static int receive_response(int sock, char* buffer, int buffer_size)
{
    int bytes_received = recv(sock, buffer, buffer_size, 0);
    if (bytes_received == -1) {
        printf("Error: recv() failed: %s\n", strerror(errno));
        exit(1);
    }
    return bytes_received;
}

static void print_response(const char* response)
{
    printf("Response:\n%s\n", response);
}

int main(int argc, char* argv[])
{
    if (argc!= 4) {
        printf("Usage: http_client <hostname> <port> <request>\n");
        exit(1);
    }

    const char* hostname = argv[1];
    int port = atoi(argv[2]);
    const char* request = argv[3];

    int sock = connect_to_server(hostname, port);
    char response[MAX_RESPONSE_SIZE];

    int bytes_sent = send_request(sock, request);
    int bytes_received = receive_response(sock, response, MAX_RESPONSE_SIZE);

    print_response(response);

    close(sock);
    return 0;
}