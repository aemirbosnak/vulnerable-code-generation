//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <resolv.h>

int nmap_scan(const char *host, const char *port, const char *output_file) {

    // Initialize variables
    struct hostent *host_info;
    struct sockaddr_in addr;
    int sockfd, optval = 1, nbytes, n;
    uint8_t buffer[4096];
    FILE *fp;

    // Check if host specified
    if(!host) {
        printf("Error: No host specified\n");
        return -1;
    }

    // Resolve host
    host_info = gethostbyname(host);
    if(!host_info) {
        printf("Error: Unable to resolve host\n");
        return -1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if(sockfd < 0) {
        printf("Error: Unable to create socket\n");
        return -1;
    }

    // Set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Initialize address
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, host_info->h_addr, sizeof(addr.sin_addr));

    // Connect to host
    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error: Unable to connect to host\n");
        return -1;
    }

    // Write to socket
    nbytes = sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    if(send(sockfd, buffer, nbytes, 0) < 0) {
        printf("Error: Unable to write to socket\n");
        return -1;
    }

    // Read from socket
    fp = fopen(output_file, "w");
    while((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }

    // Close socket
    fclose(fp);
    close(sockfd);

    return 0;
}

// Usage: ./nmap-scan hostname port [-o output_file]
int main(int argc, char **argv) {

    // Check arguments
    if(argc < 3) {
        printf("Usage: %s hostname port [-o output_file]\n", argv[0]);
        return -1;
    }

    // Get host
    const char *host = argv[1];

    // Get port
    int port = atoi(argv[2]);

    // Get output file
    const char *output_file = argv[3] ? argv[3] : "/tmp/nmap-scan.txt";

    // Perform scan
    int ret = nmap_scan(host, port, output_file);
    if(ret != 0) {
        printf("Error: Unable to perform scan\n");
        return -1;
    }

    printf("Scan results saved to %s\n", output_file);
    return 0;
}