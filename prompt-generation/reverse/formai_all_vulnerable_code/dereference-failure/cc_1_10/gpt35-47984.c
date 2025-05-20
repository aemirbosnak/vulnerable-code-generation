//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;

typedef struct {
    char* ssid;
    int signal_strength;
} ap_info;

ap_info ap_list[] = {
    {"Wifi_A", -45},
    {"Wifi_B", -66},
    {"Wifi_C", -70},
    {"Wifi_D", -80},
    {"Wifi_E", -60},
    {"Wifi_F", -75},
    {"Wifi_G", -50},
    {"Wifi_H", -64},
    {"Wifi_I", -63},
    {"Wifi_J", -90},
};

void* analyze_signal_strength(void* arg) {
    ap_info* access_point = (ap_info*)arg;
    int signal_strength = access_point->signal_strength;
    pthread_mutex_lock(&mutex);
    printf("AP Name: %s || Signal Strength: %d\n", access_point->ssid, signal_strength);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    
    int len = sizeof(ap_list)/sizeof(ap_info);
    int i;
    for(i = 0; i < len; i++) {
        pthread_create(&threads[i], NULL, analyze_signal_strength, (void*)&ap_list[i]);
    }
    
    for(i = 0; i < len; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&mutex);
    return 0;
}