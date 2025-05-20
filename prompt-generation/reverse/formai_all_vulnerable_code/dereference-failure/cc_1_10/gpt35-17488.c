//FormAI DATASET v1.0 Category: Client Server Application ; Style: future-proof
/*
 * A simple client-server application that sends a message
 * from the client to the server, the server then converts
 * all characters in the message to uppercase and sends
 * it back to the client.
 *
 * This program supports both IPv4 and IPv6 and eliminates
 * the need for specifying the IP version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef _WIN32 
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else 
#include <sys/types.h>  // for socket, bind, listen, accept, recv, send
#include <sys/socket.h> // for socket, bind, listen, accept, recv, send
#include <arpa/inet.h>  // for inet_ntop, inet_pton
#include <netdb.h>      // for getaddrinfo, freeaddrinfo, gai_strerror
#include <unistd.h>     // for close
#endif

#define PORT "8080"      // the port number to use
#define MAX_BUF_SIZE 512 // the maximum message buffer size

#define CHAT_ERROR(MSG) { fprintf(stderr, "Error: %s\n", MSG); exit(1); }

/* Function prototypes */
#ifdef _WIN32
void init_winsock(void);
#endif
bool addr_is_ipv6(const struct sockaddr *sa);
int get_socket(const char *port);
void bind_socket(int sock_fd, const char *port);
void listen_socket(int sock_fd);
int accept_socket(int sock_fd, struct sockaddr *client_addr, socklen_t *addr_len);
void send_msg(int client_fd, const char *msg);
bool recv_msg(int client_fd, char *buf, int buf_size);

/*
 * The main server loop that receives messages from clients,
 * converts the messages to uppercase and sends them back.
 */
int main(int argc, char **argv)
{
#ifdef _WIN32
    init_winsock(); // only on Windows
#endif

    int server_fd = get_socket(PORT);
    struct sockaddr_storage client_addr;
    socklen_t addr_len;

    bind_socket(server_fd, PORT);
    listen_socket(server_fd);

    printf("Server listening on port %s...\n", PORT);

    while (true) {
        int client_fd = accept_socket(server_fd, (struct sockaddr *) &client_addr, &addr_len);

        char client_ip[INET6_ADDRSTRLEN];
        inet_ntop(client_addr.ss_family, &(((struct sockaddr_in *) &client_addr)->sin_addr), client_ip, INET6_ADDRSTRLEN);
        printf("Accepted connection from %s\n", client_ip);

        char buf[MAX_BUF_SIZE];
        if (recv_msg(client_fd, buf, MAX_BUF_SIZE)) {
            printf("%s sent: %s\n", client_ip, buf);

            // convert message to uppercase
            for (int i = 0; i < strlen(buf); ++i) {
                buf[i] = toupper(buf[i]);
            }

            send_msg(client_fd, buf);
        }

        close(client_fd);
        printf("Closed connection from %s\n", client_ip);
    }

    return 0;
}

/* Initializes winsock2 library */
#ifdef _WIN32
void init_winsock(void)
{
    WSADATA wsa_data;
    int res = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (res != 0)
        CHAT_ERROR("Failed to initialize winsock2.");
}
#endif

/*
 * Returns whether the address family of the address 'sa'
 * is IPv6 or not
 */
bool addr_is_ipv6(const struct sockaddr *sa)
{
    return sa->sa_family == AF_INET6;
}

/*
 * Creates and returns a socket FD for the provided port.
 */
int get_socket(const char *port)
{
    struct addrinfo hints, *result, *rp;
    int res, sock_fd;

    memset(&hints, 0, sizeof (struct addrinfo));
    hints.ai_family = AF_UNSPEC; /* Return IPv4 and IPv6 choices */
    hints.ai_socktype = SOCK_STREAM; /* We want a TCP socket with streaming semantics */
    hints.ai_flags = AI_PASSIVE; /* All interfaces */

    res = getaddrinfo(NULL, port, &hints, &result);
    if (res != 0)
        CHAT_ERROR(gai_strerror(res));

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sock_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sock_fd == -1)
            continue;

        int optval = 1;
        /* Eliminates the error message "address already in use" */
        if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (const void *) &optval, sizeof (int)) == -1) {
            close(sock_fd);
            continue;
        }

        if (!addr_is_ipv6(rp->ai_addr) || rp->ai_addr->sa_family == AF_INET6) {
            /* For IPv6, disable IPv4 compat mode */
            int ipv6_only = 1;
            if (setsockopt(sock_fd, IPPROTO_IPV6, IPV6_V6ONLY, (const void*) &ipv6_only, sizeof (ipv6_only)) == -1) {
                close(sock_fd);
                continue;
            }
        }

        if (bind(sock_fd, rp->ai_addr, rp->ai_addrlen) == 0)
            break; /* Success */

        close(sock_fd);
    }

    if (rp == NULL)
        CHAT_ERROR("Could not bind");

    freeaddrinfo(result);

    return sock_fd;
}

/*
 * Binds the socket FD to the provided port
 */
void bind_socket(int sock_fd, const char *port)
{
    if (listen(sock_fd, 5) == -1)
        CHAT_ERROR("Listen failed");
}

/*
 * Makes the socket FD a listening socket
 */
void listen_socket(int sock_fd)
{
    if (listen(sock_fd, 5) == -1)
        CHAT_ERROR("Listen failed");
}

/*
 * Accepts a connection from a client and returns the client's socket FD.
 * 'client_addr' parameter is a pointer to a sockaddr_storage where the client's
 * address information can be stored.
 */
int accept_socket(int sock_fd, struct sockaddr *client_addr, socklen_t *addr_len)
{
    int client_fd = accept(sock_fd, client_addr, addr_len);
    if (client_fd == -1)
        CHAT_ERROR("Accept failed");

    return client_fd;
}

/*
 * Sends the provided message to the client FD. Terminates the connection
 * if an error occurs.
 */
void send_msg(int client_fd, const char *msg)
{
    int msg_size = strlen(msg) + 1; // +1 for null-terminator
    int bytes_sent = send(client_fd, msg, msg_size, 0);
    if (bytes_sent != msg_size)
        CHAT_ERROR("Send failed");
}

/*
 * Receives a message from the client FD and stores it in the 'buf' parameter.
 * Returns true if the message was successfully received, and false otherwise.
 */
bool recv_msg(int client_fd, char *buf, int buf_size)
{
    int bytes_rcvd = recv(client_fd, buf, buf_size, 0);
    if (bytes_rcvd <= 0)
        return false;

    buf[bytes_rcvd] = '\0';
    return true;
}