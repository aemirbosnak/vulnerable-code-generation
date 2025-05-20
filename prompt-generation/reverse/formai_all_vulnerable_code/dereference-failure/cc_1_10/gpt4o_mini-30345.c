//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define TIMEOUT 1
#define MAX_PINGS 5
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in addr;
    char ip[INET_ADDRSTRLEN];
    int ping_count;
} PingRequest;

void set_nonblocking(int sock) {
    fcntl(sock, F_SETFL, O_NONBLOCK);
}

void send_ping(PingRequest *request) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "Ping %d", request->ping_count);
    
    if (sendto(request->sock, buffer, strlen(buffer), 0, 
               (struct sockaddr *)&request->addr, sizeof(request->addr)) == -1) {
        perror("Send failed");
    } else {
        printf("Sent: %s to %s\n", buffer, request->ip);
    }
}

void receive_response(PingRequest *request) {
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(request->addr);
    
    ssize_t bytes_received = recvfrom(request->sock, buffer, BUFFER_SIZE - 1, 0,
                                      (struct sockaddr *)&request->addr, &addr_len);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Received: %s from %s\n", buffer, request->ip);
    } else if (bytes_received == -1 && errno != EAGAIN && errno != EWOULDBLOCK) {
        perror("Receive failed");
    }
}

void ping(const char* ip) {
    PingRequest request;
    request.ping_count = 1;

    // Create UDP socket
    request.sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (request.sock < 0) {
        perror("Socket creation failed");
        return;
    }
    
    set_nonblocking(request.sock);

    memset(&request.addr, 0, sizeof(request.addr));
    request.addr.sin_family = AF_INET;
    request.addr.sin_port = htons(8080);
    
    if (inet_pton(AF_INET, ip, &request.addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(request.sock);
        return;
    }
    
    strcpy(request.ip, ip);
    
    struct timeval tv;
    fd_set read_fds, write_fds;
    
    while (request.ping_count <= MAX_PINGS) {
        send_ping(&request);
        
        FD_ZERO(&read_fds);
        FD_SET(request.sock, &read_fds);
        write_fds = read_fds;

        // Set timeout
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        // Wait for response or timeout
        int activity = select(request.sock + 1, &read_fds, &write_fds, NULL, &tv);
        
        if (activity < 0) {
            perror("select error");
            break;
        } else if (activity == 0) {
            printf("Ping %d to %s timed out\n", request.ping_count, request.ip);
        } else {
            if (FD_ISSET(request.sock, &read_fds)) {
                receive_response(&request);
            }
        }

        request.ping_count++;
        sleep(1); // Wait before the next ping
    }
    
    close(request.sock);
}

int main() {
    const char *target_ip = "8.8.8.8"; // Example: Google's public DNS IP
    printf("Pinging %s...\n", target_ip);
    ping(target_ip);
    return 0;
}