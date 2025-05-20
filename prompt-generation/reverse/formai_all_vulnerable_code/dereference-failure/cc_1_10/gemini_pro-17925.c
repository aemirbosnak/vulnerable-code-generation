//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>

// paranoid version

// macros

#define PORT 80
#define BUFSIZE 1024

// global variables

struct sockaddr_in server_addr;
int sockfd;

// functions

// paranoia: check for errors
void check_error(int e, const char *msg)
{
    if (e) {
        fprintf(stderr, "Error: %s\n", msg);
        exit(1);
    }
}

// paranoid: get hostname from argv
char *get_hostname(char *argv)
{
    char *hostname;
    hostname = malloc(strlen(argv) + 1);
    strcpy(hostname, argv);
    return hostname;
}

// get socket file descriptor
int get_sockfd(char *hostname)
{
    struct hostent *host;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    check_error(sockfd < 0, "cannot create socket");
    host = gethostbyname(hostname);
    check_error(host == NULL, "cannot resolve hostname");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
    return sockfd;
}

// connect to server
void connect_to_server(int sockfd)
{
    check_error(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0, "cannot connect to server");
}

// send data to server
void send_data(int sockfd, char *buf)
{
    check_error(send(sockfd, buf, strlen(buf), 0) < 0, "cannot send data to server");
}

// receive data from server
void receive_data(int sockfd, char *buf)
{
    check_error(recv(sockfd, buf, BUFSIZE, 0) < 0, "cannot receive data from server");
}

// paranoid: close socket
void close_socket(int sockfd)
{
    check_error(close(sockfd) < 0, "cannot close socket");
}

// paranoid: free hostname
void free_hostname(char *hostname)
{
    free(hostname);
}

// paranoia: main function
int main(int argc, char *argv[])
{
    int sockfd;
    char *hostname;
    char buf[BUFSIZE];

    // paranoia: check for argv errors
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // get hostname from argv
    hostname = get_hostname(argv[1]);

    // get socket file descriptor
    sockfd = get_sockfd(hostname);

    // connect to server
    connect_to_server(sockfd);

    // send data to server
    send_data(sockfd, "GET / HTTP/1.0\r\n\r\n");

    // receive data from server
    receive_data(sockfd, buf);

    // free hostname
    free_hostname(hostname);

    // close socket
    close_socket(sockfd);

    return 0;
}