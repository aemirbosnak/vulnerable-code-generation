//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

void downloadSpeed() {
    char buffer[BUFFER_SIZE];
    FILE *fp = popen("ping -c 1 -s 1024 8.8.8.8 > /dev/null", "r");
    int num = 0;
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        num = 0;
        while (buffer[num]!= '\n') {
            num++;
        }
        num++; // skip newline
    }
    pclose(fp);
    printf("Download speed: %f Mbit/s\n", (float) num / 1024 / 1024 / 8);
}

void uploadSpeed() {
    char buffer[BUFFER_SIZE];
    FILE *fp = popen("ping -c 1 -s 1024 google.com > /dev/null", "r");
    int num = 0;
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        num = 0;
        while (buffer[num]!= '\n') {
            num++;
        }
        num++; // skip newline
    }
    pclose(fp);
    printf("Upload speed: %f Mbit/s\n", (float) num / 1024 / 1024 / 8);
}

void megabitToByte(float mb) {
    printf("%.2f Mbit/s = %.2f MBytes/s = %.2f KB/s = %.2f KB/s\n", mb, mb * 1048576, mb * 1048576 / 1024, mb * 1024 / 1024);
}

int main() {
    downloadSpeed();
    uploadSpeed();
    megabitToByte(0.5);
    return 0;
}