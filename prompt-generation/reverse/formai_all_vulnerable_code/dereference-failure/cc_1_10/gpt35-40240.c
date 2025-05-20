//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_BUFFER_LEN 1024           // Maximum length of buffer
#define MAX_DEV_NUM 128               // Maximum number of devices to check
#define MAX_DEV_NAME_LEN 512          // Maximum length of device name
#define TIMEOUT_SECS 1                // Maximum seconds to wait for device response
#define DEFAULT_PORT 8080             // Default port number
#define RETRY_COUNT 3                 // Number of times to retry device connection
#define RETRY_DELAY_SECS 1            // Delay time between retry attempts in seconds

struct device_info {
    char name[MAX_DEV_NAME_LEN];
    char ip_addr[INET_ADDRSTRLEN];
    int signal_strength;
};

struct thread_args {
    struct device_info *devices;
    int dev_count;
};

// Function to scan for Wi-Fi devices
void* scan_devices(void* arg) {
    struct thread_args* t_args = (struct thread_args*) arg;
    struct device_info* devices = t_args->devices;
    int dev_count = t_args->dev_count;
    
    // Create socket for sending packets
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set timeout for waiting device response
    struct timeval tv;
    tv.tv_sec = TIMEOUT_SECS;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Create socket address for broadcasting packet
    struct sockaddr_in broadcast_addr;
    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(DEFAULT_PORT);
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    
    // Send broadcast packet to each device
    char buffer[MAX_BUFFER_LEN];
    for (int i = 0; i < dev_count; i++) {
        int retry_count = 0;
        while (retry_count++ < RETRY_COUNT) {
            // Send broadcast packet
            if (sendto(sockfd, buffer, MAX_BUFFER_LEN, 0, (struct sockaddr*) &broadcast_addr, sizeof(broadcast_addr)) < 0) {
                perror("sendto failed");
                continue;
            }
            
            // Receive response from device
            struct sockaddr_in device_addr;
            socklen_t addr_len = sizeof(device_addr);
            int recv_len = recvfrom(sockfd, buffer, MAX_BUFFER_LEN, 0, (struct sockaddr*) &device_addr, &addr_len);
            if (recv_len < 0) {
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    // Timeout occurred, device did not respond
                    printf("Timed out waiting for response from device %s at %s\n", devices[i].name, devices[i].ip_addr);
                } else {
                    perror("recvfrom failed");
                }
                continue;
            }
            
            // Parse response and update device signal strength
            buffer[recv_len] = 0;
            int signal_strength = atoi(buffer);
            devices[i].signal_strength = signal_strength;
            printf("Received signal strength %d from device %s at %s\n", signal_strength, devices[i].name, devices[i].ip_addr);
            break;
        }
        
        if (retry_count >= RETRY_COUNT) {
            // Maximum retries exceeded, give up on device
            printf("Unable to connect to device %s at %s\n", devices[i].name, devices[i].ip_addr);
        }
        
        // Delay between connection attempts
        sleep(RETRY_DELAY_SECS);
    }
    
    close(sockfd);
    return NULL;
}

int main() {
    // Create list of devices to check
    struct device_info devices[MAX_DEV_NUM] = {
        {"Device 1", "192.168.1.1", 0},
        {"Device 2", "192.168.1.2", 0},
        {"Device 3", "192.168.1.3", 0},
        {"Device 4", "192.168.1.4", 0},
        {"Device 5", "192.168.1.5", 0}
    };
    int dev_count = sizeof(devices) / sizeof(devices[0]);
    
    // Create thread to scan for devices
    pthread_t scan_thread;
    struct thread_args t_args = {devices, dev_count};
    if(pthread_create(&scan_thread, NULL, scan_devices, &t_args) != 0) {
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }
    
    // Wait for thread to complete
    void* thread_result = NULL;
    if(pthread_join(scan_thread, &thread_result) != 0) {
        perror("pthread_join failed");
        exit(EXIT_FAILURE);
    }
    
    // Print results
    printf("\nWi-Fi signal strengths:\n");
    for (int i = 0; i < dev_count; i++) {
        printf("%s at %s: %d\n", devices[i].name, devices[i].ip_addr, devices[i].signal_strength);
    }
    
    return 0;
}