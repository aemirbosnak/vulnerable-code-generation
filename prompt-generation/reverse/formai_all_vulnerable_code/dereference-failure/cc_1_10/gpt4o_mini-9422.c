//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_PORTS 65535

void greet_user() {
    printf("🎉 Welcome to the Cheerful Port Scanner! 🎉\n");
    printf("Let's explore the wonders of your network and see what ports are open!\n");
    printf("You can give me an IP address and I will scan for you. Let's get started!\n\n");
}

int create_socket() {
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("🚨 Sorry, unable to create a socket: %s 🙁\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return sock;
}

void scan_port(const char *ip, int port) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    
    if (inet_pton(AF_INET, ip, &server_address.sin_addr) <= 0) {
        printf("🚨 Invalid IP address format! Please try again. 🙁\n");
        return;
    }

    int sock = create_socket();

    // Set a timeout for the connection attempt
    struct timeval timeout;
    timeout.tv_sec = 1;  // 1 second timeout
    timeout.tv_usec = 0;
   
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

    // Try to connect to the port
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == 0) {
        printf("🔓 Port %d is OPEN! 🎉\n", port);
    } else {
        if (errno == ECONNREFUSED) {
            printf("🔒 Port %d is CLOSED. 😢\n", port);
        }
    }
    
    close(sock);
}

void scan_ports(const char *ip) {
    printf("🚀 Scanning ports for %s...\n", ip);
    for (int port = 1; port <= MAX_PORTS; port++) {
        scan_port(ip, port);
    }
    printf("🎊 Scanning completed! 🥳\n");
}

int main(int argc, char *argv[]) {
    greet_user();

    if (argc != 2) {
        printf("🎈 Please provide an IP address to scan. Usage: %s <IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_to_scan = argv[1];
    scan_ports(ip_to_scan);

    printf("🥳 Thank you for using the Cheerful Port Scanner! Have a great day! 🌈\n");
    return 0;
}