//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sock, ret;
    struct hostent *host;
    char hostname[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int datalen;

    // Check if correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    // Copy hostname and data from command line arguments
    strncpy(hostname, argv[1], MAX_HOST_LEN);
    strncpy(data, argv[2], MAX_DATA_LEN);

    // Resolve hostname to IP address
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Host not found\n");
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    // Connect to remote host
    memset(&(host->h_addr), 0, host->h_length);
    ret = connect(sock, (struct sockaddr *)host->h_addr, host->h_length);
    if (ret == -1) {
        printf("Error: Could not connect to host\n");
        close(sock);
        return 1;
    }

    // Send data to host
    datalen = strlen(data);
    ret = send(sock, data, datalen, 0);
    if (ret == -1) {
        printf("Error: Could not send data to host\n");
        close(sock);
        return 1;
    }

    // Receive response from host
    memset(data, 0, MAX_DATA_LEN);
    datalen = recv(sock, data, MAX_DATA_LEN, 0);
    if (datalen == -1) {
        printf("Error: Could not receive response from host\n");
        close(sock);
        return 1;
    }

    // Print response
    printf("Response: %s\n", data);

    // Close socket
    close(sock);

    return 0;
}