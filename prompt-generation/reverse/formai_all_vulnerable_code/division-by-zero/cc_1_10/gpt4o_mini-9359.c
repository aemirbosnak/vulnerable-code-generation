//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define INTERVAL 2 // Interval in seconds for checking RAM usage

// Global variable to store RAM usage information
struct sysinfo memInfo;

// Mutex for synchronizing memory info access
pthread_mutex_t memInfoMutex;

// Function to get current RAM usage
void* fetch_memory_usage(void* arg) {
    while (1) {
        // Lock mutex before accessing shared resource
        pthread_mutex_lock(&memInfoMutex);

        // Get system information
        if (sysinfo(&memInfo) != 0) {
            perror("sysinfo");
            pthread_mutex_unlock(&memInfoMutex);
            break;
        }

        pthread_mutex_unlock(&memInfoMutex);
        sleep(INTERVAL);
    }
    return NULL;
}

// Function to display current RAM usage on the console
void* display_memory_usage(void* arg) {
    while (1) {
        // Lock mutex before accessing shared resource
        pthread_mutex_lock(&memInfoMutex);

        // Calculate memory usage
        long totalMem = memInfo.totalram;
        long freeMem = memInfo.freeram;
        long usedMem = totalMem - freeMem;
        long percentUsed = (usedMem * 100) / totalMem;

        // Display memory information
        printf("\rTotal RAM: %ld kB | Free RAM: %ld kB | Used RAM: %ld kB | Used Percentage: %ld%%",
            totalMem / 1024, freeMem / 1024, usedMem / 1024, percentUsed);
        fflush(stdout);

        pthread_mutex_unlock(&memInfoMutex);
        sleep(INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t fetchThread, displayThread;

    // Initialize mutex
    if (pthread_mutex_init(&memInfoMutex, NULL) != 0) {
        perror("Mutex initialization failed");
        return EXIT_FAILURE;
    }

    // Create a thread to fetch memory usage
    if (pthread_create(&fetchThread, NULL, fetch_memory_usage, NULL) != 0) {
        perror("Failed to create fetch thread");
        return EXIT_FAILURE;
    }

    // Create a thread to display memory usage
    if (pthread_create(&displayThread, NULL, display_memory_usage, NULL) != 0) {
        perror("Failed to create display thread");
        return EXIT_FAILURE;
    }

    // Wait for the threads to finish (they won't until the program is terminated)
    pthread_join(fetchThread, NULL);
    pthread_join(displayThread, NULL);

    // Clean up
    pthread_mutex_destroy(&memInfoMutex);

    return EXIT_SUCCESS;
}