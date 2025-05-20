//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
// Romeo: QoS Monitor
// Juliet: Network Guardian

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// QoS parameters
#define DELAY 100 //ms
#define JITTER 20 //ms
#define BANDWIDTH 1000000 //bps

// Network I/O
int sock_romeo, sock_juliet;
struct sockaddr_in addr_romeo, addr_juliet;

// QoS monitoring variables
int delay_avg = 0, jitter_avg = 0, bandwidth_avg = 0;
int seq_num = 0;

// Romeo's heart beats
void romeo_monitor() {
    int start_time, end_time, delay;

    char buf[1024];
    buf[0] = seq_num++;
    
    // Send a QoS probe to Juliet
    sendto(sock_romeo, buf, 1, 0, (struct sockaddr*)&addr_juliet, sizeof(addr_juliet));
    
    // Start the timer
    start_time = time();

    // Receive the probe back from Juliet
    recvfrom(sock_romeo, buf, 1, 0, NULL, NULL);
    
    // End the timer
    end_time = time();

    // Calculate the delay
    delay = end_time - start_time;

    // Update the QoS variables
    delay_avg = (delay_avg + delay) / 2;
    jitter_avg = (jitter_avg + abs(delay - delay_avg)) / 2;
    bandwidth_avg = (bandwidth_avg + 1024 * 8 / delay) / 2;

    // Display the QoS parameters
    printf("Delay: %d ms, Jitter: %d ms, Bandwidth: %d bps\n", delay_avg, jitter_avg, bandwidth_avg);
}

// Juliet's watchful eye
void juliet_guard() {
    char buf[1024];

    // Receive a QoS probe from Romeo
    recvfrom(sock_juliet, buf, 1, 0, NULL, NULL);
    
    // Send the probe back to Romeo
    sendto(sock_juliet, buf, 1, 0, (struct sockaddr*)&addr_romeo, sizeof(addr_romeo));
}

// Their tragic end
void close_sockets() {
    close(sock_romeo);
    close(sock_juliet);
}

int main(int argc, char *argv[]) {
    // Create Romeo's socket
    sock_romeo = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_romeo < 0) {
        perror("Romeo's socket creation failed");
        exit(1);
    }
    
    // Create Juliet's socket
    sock_juliet = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_juliet < 0) {
        perror("Juliet's socket creation failed");
        exit(1);
    }
    
    // Set Romeo's socket address
    addr_romeo.sin_family = AF_INET;
    addr_romeo.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_romeo.sin_port = htons(1234);

    // Set Juliet's socket address
    addr_juliet.sin_family = AF_INET;
    addr_juliet.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr_juliet.sin_port = htons(1235);

    // Bind Romeo's socket to the address
    if (bind(sock_romeo, (struct sockaddr*)&addr_romeo, sizeof(addr_romeo)) < 0) {
        perror("Romeo's socket binding failed");
        exit(1);
    }

    // Their eternal loop
    while (1) {
        romeo_monitor();
        juliet_guard();
    }

    // Their tragic end
    close_sockets();

    return 0;
}