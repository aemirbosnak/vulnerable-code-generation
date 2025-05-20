//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
/*
  This C program implements a simple port scanner that scans ports within a specified range on a given host using the TCP protocol. 
  It utilizes sockets to create a connection to the specified host and sends SYN packets and listens for an ACK response.
  If ACK is received, the port is considered open. Otherwise, it is considered closed. 
  The program prints a report of the open ports found on the host within the specified range.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // needed for close() function
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_PORT 65535 // Maximum number of ports that can be scanned

// Global variables
int PORT_RANGE_START; // Start of port range to scan
int PORT_RANGE_END; // End of port range to scan
char* HOSTNAME; // Destination host name or IP address

// Function prototypes
void scan_ports(char* hostname, int start_port, int end_port);
int create_socket();
void set_socket_timeout(int sockfd, int seconds);
void set_socket_non_blocking(int sockfd);
int check_socket(int sockfd);
int is_port_open(char* hostname, int port);

// Main function
int main(int argc, char** argv){

    // Error handling for insufficient arguments
    if(argc < 4) {
        perror("Invalid arguments");
        printf("Usage: %s <hostname> <port_range_start> <port_range_end>\n", argv[0]);
        exit(1);
    }

    // Parse command line arguments
    HOSTNAME = argv[1];
    PORT_RANGE_START = atoi(argv[2]);
    PORT_RANGE_END = atoi(argv[3]);

    // Error handling for invalid port ranges
    if(PORT_RANGE_START < 0 || PORT_RANGE_END > MAX_PORT || PORT_RANGE_START > PORT_RANGE_END) {
        perror("Invalid port range");
        exit(1);
    }

    printf("Scanning ports %d to %d on %s...\n", PORT_RANGE_START, PORT_RANGE_END, HOSTNAME);

    scan_ports(HOSTNAME, PORT_RANGE_START, PORT_RANGE_END);

    return 0;
}

// Scan ports within a specified range on a given host using the TCP protocol
void scan_ports(char* hostname, int start_port, int end_port) {
    int sockfd;
    struct addrinfo hints, *result, *rp;
    char port[6];

    // Convert port numbers to strings
    sprintf(port, "%d", start_port);

    // Set up address structure
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Get address of the destination host
    if (getaddrinfo(hostname, port, &hints, &result) != 0) {
        perror("getaddrinfo() failed");
        exit(1);
    }

    // Loop through the list of possible addresses and attempt to connect to each
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        // Check for invalid socket creation
        if (sockfd == -1) {
            continue;
        }

        // Connect to the socket
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            
            printf("Port %d is open!\n", start_port);

            // Close the socket
            close(sockfd);
        }
        else{

            printf("Port %d is closed.\n", start_port);

            // Close the socket
            close(sockfd);
        }
    }
}

// Create a new socket with the default TCP protocol
int create_socket(){
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Error handling for invalid socket creation
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    return sockfd;
}

// Set a timeout value for a socket
void set_socket_timeout(int sockfd, int seconds){
    struct timeval timeout;
    timeout.tv_sec = seconds;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
}

// Set up a socket to be non-blocking
void set_socket_non_blocking(int sockfd){
    int flags;

    flags = fcntl(sockfd, F_GETFL);
    if (flags == -1){
        perror("fcntl get failed");
        exit(1);
    }

    flags |= O_NONBLOCK;        
    if (fcntl(sockfd, F_SETFL, flags) == -1) {
        perror("fcntl set failed");
        exit(1);
    }
}

// Check if a socket has data waiting to be read
int check_socket(int sockfd){
    struct timeval timeout;
    fd_set read_fd_set;

    // Set up the file descriptor set
    FD_ZERO(&read_fd_set);     
    FD_SET(sockfd, &read_fd_set);

    // Set timeout to zero for non-blocking socket
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    // Wait for data to arrive
    if (select(sockfd + 1, &read_fd_set, NULL, NULL, &timeout) == -1) {
        perror("select failed");
        exit(1);
    }

    return FD_ISSET(sockfd, &read_fd_set);
}

// Attempt to open a connection to a specified port on the given host
int is_port_open(char* hostname, int port){

    int sockfd = create_socket();

    // Set socket options
    set_socket_timeout(sockfd, 3);
    set_socket_non_blocking(sockfd);

    struct hostent* host = gethostbyname(hostname);

    // Error handling for invalid host name or IP address
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    struct sockaddr_in server_addr;

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *(long*)host->h_addr;
    server_addr.sin_port = htons(port);

    // Attempt to connect to the specified port
    int connect_status = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    if (connect_status == -1) {
        // Check if the failure was due to the port being closed or due to some other error
        if (errno == EINPROGRESS) {
            if (check_socket(sockfd)) {

                printf("Port %d is open!\n", port);

                close(sockfd);
                return 1;
            }
        }
    }
    else{

        printf("Port %d is open!\n", port);

        close(sockfd);
        return 1;
    }

    printf("Port %d is closed.\n", port);

    close(sockfd);
    return 0;
}