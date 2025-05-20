//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<sys/time.h>

#define kilo 1024
#define mega 1048576

struct timeval tv1, tv2;
double tv_diff;

double calc_time_diff(struct timeval tv1, struct timeval tv2) {
    return (double)(tv2.tv_sec - tv1.tv_sec) + (double)(tv2.tv_usec - tv1.tv_usec)/1000000.0;
}

void download_test() {
    int file_size = 50 * mega;
    char *file_buffer = malloc(file_size);
    int download_speed;
    
    gettimeofday(&tv1, NULL);
    //for simplicity, we'll simulate a download by generating a random file
    for(int i=0; i<file_size; i++) {
        file_buffer[i] = rand() % 256;
    }
    gettimeofday(&tv2, NULL);
    tv_diff = calc_time_diff(tv1, tv2);
    download_speed = (int)(file_size / tv_diff / mega);
    printf("Download speed: %d Mbps\n", download_speed);
}

void upload_test() {
    int upload_size = 10 * mega;
    char *upload_buffer = malloc(upload_size);
    int upload_speed;
    
    gettimeofday(&tv1, NULL);
    //for simplicity, we'll simulate an upload by copying a buffer to another buffer
    memcpy(upload_buffer, upload_buffer+upload_size, upload_size);
    gettimeofday(&tv2, NULL);
    tv_diff = calc_time_diff(tv1, tv2);
    upload_speed = (int)(upload_size / tv_diff / mega);
    printf("Upload speed: %d Mbps\n", upload_speed);
}

int main() {
    printf("Starting speed test...\n");
    printf("Performing download test...\n");
    download_test();
    printf("Performing upload test...\n");
    upload_test();
    printf("Speed test complete.\n");
    return 0;
}