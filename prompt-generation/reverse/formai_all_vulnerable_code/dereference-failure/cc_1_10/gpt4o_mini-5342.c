//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_SAMPLES 10

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int packet_loss;
    float latency;
} QosData;

void* monitor_qos(void* arg) {
    QosData* data = (QosData*)arg;
    char command[BUFFER_SIZE];
    
    printf("Starting QoS monitoring on %s...\n", data->ip);
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        snprintf(command, sizeof(command), "ping -c 1 %s 2>&1", data->ip);
        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            perror("Error opening pipe");
            return NULL;
        }

        char buffer[BUFFER_SIZE];
        int received = 0;
        float avg_time = 0.0;

        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (strstr(buffer, "bytes from")) {
                received++;
                char* time_str = strstr(buffer, "time=");
                if (time_str) {
                    float time_value;
                    sscanf(time_str + 5, "%f", &time_value);
                    avg_time += time_value;
                }
            } else if (strstr(buffer, "100% packet loss")) {
                data->packet_loss += 100;
            } else if (strstr(buffer, "0% packet loss")) {
                data->packet_loss += 0;
            }
        }
        
        if (received > 0) {
            avg_time /= received;
            data->latency = avg_time;
        } else {
            data->latency = -1; // Indicate failure to receive any reply
        }
        
        pclose(fp);
        sleep(1); // Wait 1 second before the next ping
    }
    
    printf("Finished monitoring %s. Packet Loss: %d%%, Avg Latency: %.2f ms\n", 
           data->ip, data->packet_loss / NUM_SAMPLES, data->latency);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    QosData qos_data;
    strcpy(qos_data.ip, argv[1]);
    qos_data.packet_loss = 0;
    qos_data.latency = 0.0;

    pthread_t thread;
    if (pthread_create(&thread, NULL, monitor_qos, (void*)&qos_data) != 0) {
        fprintf(stderr, "Error creating thread: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Error joining thread: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    printf("QoS Monitoring Results:\n");
    printf("IP Address: %s\n", qos_data.ip);
    printf("Total Packet Loss: %d%%\n", qos_data.packet_loss / NUM_SAMPLES);
    printf("Average Latency: %.2f ms\n", qos_data.latency);
    
    return EXIT_SUCCESS;
}