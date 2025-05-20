//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download_speed = 0, upload_speed = 0;
    long long int download_size = 100000000; // 100 MB
    long long int upload_size = 50000000; // 50 MB
    time_t start, end;

    printf("Running Internet Speed Test ...\n\n");

    // Download Speed Test
    printf("Testing Download Speed: \n");
    start = time(NULL);
    while (1) {
        long long int size = rand() % 1000000 + 1000000; // minimum of 1 MB and maximum of 2 MB
        end = time(NULL);
        if ((end - start) >= 10) { // run for 10 seconds
            break;
        }
        download_speed += size;
        download_size -= size;
    }
    download_speed /= (end - start);
    printf("Download Speed: %d KBps\n", download_speed);

    // Upload Speed Test
    printf("\nTesting Upload Speed: \n");
    start = time(NULL);
    while (1) {
        long long int size = rand() % 500000 + 500000; // minimum of 500 KB and maximum of 1 MB
        end = time(NULL);
        if ((end - start) >= 10) { // run for 10 seconds
            break;
        }
        upload_speed += size;
        upload_size -= size;
    }
    upload_speed /= (end - start);
    printf("Upload Speed: %d KBps\n", upload_speed);

    printf("\nTest Results: \n");
    printf("Download Size: %lld bytes\n", 100000000 - download_size);
    printf("Download Time: %ld seconds\n", end - start);
    printf("Upload Size: %lld bytes\n", 50000000 - upload_size);
    printf("Upload Time: %ld seconds\n", end - start);

    return 0;
}