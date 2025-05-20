//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>


#define MAX_PACKET_SIZE 1024
#define DEFAULT_TIMEOUT 5



/* function prototypes */
int create_socket();
void usage(char *executable);


int main(int argc, char **argv) {

    /* check if user provided enough arguments */
    if (argc < 2 || argc > 3) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    /* get the ip address and port number */
    char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    /* create a socket */
    int sock = create_socket();
    if (sock == -1) {
        printf("[!] Failed to create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* set socket options */
    struct timeval timeout;
    timeout.tv_sec = DEFAULT_TIMEOUT;
    timeout.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout)) < 0) {
        printf("[!] Failed to set socket option: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* prepare the socket address structure */
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_addr, &addr.sin_addr) <= 0) {
        printf("[!] Failed to set socket address: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* connect to the wireless network */
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("[!] Failed to connect to the wireless network: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("[+] Connected to the wireless network.\n");

    /* send a scanning request to the wireless network */
    char *request = "SCAN";
    if (send(sock, request, strlen(request), 0) < 0) {
        printf("[!] Failed to send scanning request: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("[+] Sent scanning request to the wireless network.\n");

    /* receive response from the wireless network */
    char response[MAX_PACKET_SIZE];
    int num_bytes = recv(sock, response, MAX_PACKET_SIZE - 1, 0);
    if (num_bytes < 0) {
        printf("[!] Failed to receive response from the wireless network: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    response[num_bytes] = '\0';

    printf("[+] Received response from the wireless network: %s\n", response);

    /* close the socket */
    close(sock);

    printf("[+] Closed socket.\n");

    return EXIT_SUCCESS;
}


/*
 * Function that creates a socket.
 */
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        return -1;
    }

    return sock;
}


/*
 * Function that prints usage information for the program.
 */
void usage(char *executable) {
    printf("Usage: %s <ip address> <port>\n", executable);
}