//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TEST_DURATION 10
#define MEGA_BYTE 1048576

void calculate_speed(char* server_ip){
    char command[BUFFER_SIZE];
    sprintf(command, "iperf -c %s -t %d -i 1 -w 1M", server_ip, TEST_DURATION);

    printf("Testing internet speed. Please wait...\n");

    // Open a pipe to execute the command
    FILE* pipe = popen(command, "r");

    // Read in pipe output to buffer
    char buffer[BUFFER_SIZE];
    int total_bytes = 0;
    while (fgets(buffer, BUFFER_SIZE, pipe) != NULL) {
        if (buffer[0] >= '0' && buffer[0] <= '9') {
            int bytes_written;
            float mbps = 0;

            // Parse out bytes written and calculate speed
            sscanf(buffer, "%d bytes %f %*s", &bytes_written, &mbps);
            printf("%.2f Mbps\t", mbps);
            total_bytes += bytes_written;
        }
    }

    // Calculate total data received and display result
    float total_mega_byte = ((float) total_bytes / MEGA_BYTE);
    float speed = total_mega_byte / TEST_DURATION;
    printf("\nDownloaded %.2f MB in %d seconds. Average speed: %.2f Mbps\n", total_mega_byte, TEST_DURATION, speed);

    // Close pipe and clean up
    pclose(pipe);
}

int main(){
    printf("Welcome to Internet Speed Test Application\n");
    printf("Enter the IP address of the server you'd like to test: ");
    char server_ip[BUFFER_SIZE];
    scanf("%s", server_ip);

    calculate_speed(server_ip);
    return 0;
}