//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

double download_speed(int mbps);
double upload_speed(int mbps);
double ping_test(int mbps);

int main(int argc, char *argv[]) {
    int mbps;
    
    if (argc != 2) {
        printf("Usage: %s <mbps>\n", argv[0]);
        return 1;
    }
    
    mbps = atoi(argv[1]);
    
    printf("Starting internet speed test...\n");
    printf("Download speed: %.2f Mbps\n", download_speed(mbps));
    printf("Upload speed: %.2f Mbps\n", upload_speed(mbps));
    printf("Ping: %.2f ms\n", ping_test(mbps));
    
    return 0;
}

double download_speed(int mbps) {
    char command[BUFFER_SIZE];
    FILE *fp;
    double speed;
    
    sprintf(command, "dd if=/dev/zero of=tempfile bs=%dM count=10 conv=fdatasync", mbps);
    fp = popen(command, "r");
    
    if (fp == NULL) {
        return -1;
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Do nothing
    }
    
    pclose(fp);
    
    fp = fopen("tempfile", "r");
    
    if (fp == NULL) {
        return -1;
    }
    
    fseek(fp, 0, SEEK_END);
    double size = ftell(fp) / (1024 * 1024);
    double time_taken = 10.0;
    
    fclose(fp);
    remove("tempfile");
    
    speed = size / time_taken;
    
    return speed;
}

double upload_speed(int mbps) {
    char command[BUFFER_SIZE];
    FILE *fp;
    double speed;
    
    sprintf(command, "dd if=/dev/zero bs=%dM count=10 | nc -l 1234 > /dev/null", mbps);
    fp = popen(command, "r");
    
    if (fp == NULL) {
        return -1;
    }
    
    time_t start_time = time(NULL);
    sleep(1);
    
    sprintf(command, "dd if=/dev/zero bs=%dM count=10 | nc localhost 1234", mbps);
    fp = popen(command, "r");
    
    if (fp == NULL) {
        return -1;
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Do nothing
    }
    
    time_t end_time = time(NULL);
    
    pclose(fp);
    
    double time_taken = difftime(end_time, start_time);
    
    speed = 10 / time_taken;
    
    return speed;
}

double ping_test(int mbps) {
    char command[BUFFER_SIZE];
    FILE *fp;
    double ping_time;
    
    sprintf(command, "ping -c 4 -s %d 8.8.8.8", mbps);
    fp = popen(command, "r");
    
    if (fp == NULL) {
        return -1;
    }
    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (strcasestr(buffer, "time=") != NULL) {
            char *start = strstr(buffer, "time=") + strlen("time=");
            char *end = strstr(start, " ms");
            char ping[100];
            
            strncpy(ping, start, end-start);
            ping_time = atof(ping);
        }
    }
    
    pclose(fp);
    
    return ping_time;
}