//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int check_input(int argc, char *argv[]);
int create_socket();
int connect_to_host(char *hostname, char *port);
void process_request(int client_socket, char *hostname, char *port, char *buffer);
void forward_response(int client_socket, int server_socket);

int main(int argc, char *argv[])
{
    int client_socket, server_socket;

    /* Check for valid input */
    if (check_input(argc, argv) == -1) {
        exit(EXIT_FAILURE);
    }

    /* Create client socket */
    client_socket = create_socket();
    if (client_socket == -1) {
        exit(EXIT_FAILURE);
    }

    /* Connect to host */
    server_socket = connect_to_host(argv[1], argv[2]);
    if (server_socket == -1) {
        exit(EXIT_FAILURE);
    }

    /* Process HTTP request */
    process_request(client_socket, argv[1], argv[2], argv[3]);

    /* Forward HTTP response */
    forward_response(client_socket, server_socket);

    /* Close sockets */
    close(client_socket);
    close(server_socket);

    return 0;
}

int check_input(int argc, char *argv[])
{
    /* Check for correct number of arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port message\n", argv[0]);
        return -1;
    }

    return 0;
}

int create_socket()
{
    int sockfd;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    return sockfd;
}

int connect_to_host(char *hostname, char *port)
{
    int sockfd;
    struct addrinfo hints, *result, *rp;
    int status;

    /* Set address hints */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;                  /* IPv4 */
    hints.ai_socktype = SOCK_STREAM;            /* TCP */

    /* Get address info for server hostname */
    status = getaddrinfo(hostname, port, &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return -1;
    }

    /* Loop through results and connect to the first successful one */
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        } 

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break; /* Success */
        }

        close(sockfd); /* Close socket if not successful */
    }

    /* Check if connection was successful */
    if (rp == NULL) {
        fprintf(stderr, "Could not connect to %s:%s\n", hostname, port);
        return -1;
    }

    freeaddrinfo(result); /* Free memory for result */

    return sockfd;
}

void process_request(int client_socket, char *hostname, char *port, char *buffer)
{
    char request[BUFFER_SIZE];

    /* Create HTTP request */
    snprintf(request, BUFFER_SIZE, "GET / HTTP/1.0\r\n"
                                    "Host: %s:%s\r\n"
                                    "User-Agent: SimpleHTTPProxy\r\n"
                                    "Connection: close\r\n"
                                    "\r\n", hostname, port);

    /* Send HTTP request to server */
    if (send(client_socket, request, strlen(request), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

void forward_response(int client_socket, int server_socket)
{
    char buffer[BUFFER_SIZE];
    int bytes_received;

    /* Receive server response */
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        /* Send response to client */
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        /* Clear buffer */
        memset(buffer, 0, BUFFER_SIZE);
    }

    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
}