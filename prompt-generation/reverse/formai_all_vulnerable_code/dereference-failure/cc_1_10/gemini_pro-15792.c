//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Calculate the average of an array of doubles
double average(double *arr, int len) {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum / (double)len;
}

// Calculate the standard deviation of an array of doubles
double stdev(double *arr, int len) {
    double avg = average(arr, len);
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += (arr[i] - avg) * (arr[i] - avg);
    }
    return sqrt(sum / (double)(len - 1));
}

// Perform an internet speed test
int main() {
    // Initialize variables
    int num_tests = 10;  // Number of tests to perform
    double *download_times = malloc(sizeof(double) * num_tests);  // Array to store download times
    double *upload_times = malloc(sizeof(double) * num_tests);  // Array to store upload times
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate random file sizes for each test (in MB)
    double *file_sizes_MB = malloc(sizeof(double) * num_tests);
    for (int i = 0; i < num_tests; i++) {
        file_sizes_MB[i] = (double)(rand() % 100 + 1) / 10.0;  // Random file size between 1 and 10 MB
    }
    
    // Perform the tests
    for (int i = 0; i < num_tests; i++) {
        // Generate a random download speed (in MB/s)
        double download_speed_MBps = (double)(rand() % 100 + 1) / 10.0;  // Random download speed between 1 and 10 MB/s
        
        // Calculate the download time (in seconds)
        download_times[i] = file_sizes_MB[i] / download_speed_MBps;
        
        // Generate a random upload speed (in MB/s)
        double upload_speed_MBps = (double)(rand() % 100 + 1) / 10.0;  // Random upload speed between 1 and 10 MB/s
        
        // Calculate the upload time (in seconds)
        upload_times[i] = file_sizes_MB[i] / upload_speed_MBps;
    }
    
    // Calculate the average and standard deviation of the download times
    double avg_download_time = average(download_times, num_tests);
    double stdev_download_time = stdev(download_times, num_tests);
    
    // Calculate the average and standard deviation of the upload times
    double avg_upload_time = average(upload_times, num_tests);
    double stdev_upload_time = stdev(upload_times, num_tests);
    
    // Print the results
    printf("Average Download Time: %.2f seconds\n", avg_download_time);
    printf("Standard Deviation of Download Time: %.2f seconds\n", stdev_download_time);
    printf("\n");
    printf("Average Upload Time: %.2f seconds\n", avg_upload_time);
    printf("Standard Deviation of Upload Time: %.2f seconds\n", stdev_upload_time);
    
    // Free allocated memory
    free(download_times);
    free(upload_times);
    free(file_sizes_MB);
    
    return 0;
}