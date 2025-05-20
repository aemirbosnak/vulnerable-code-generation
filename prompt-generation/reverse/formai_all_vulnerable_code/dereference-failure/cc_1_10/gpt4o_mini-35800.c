//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_WIFIS 100
#define SIGNAL_THRESHOLD -65
#define BUFFER_SIZE 256

void funny_quote() {
    printf("Why did the Wi-Fi break up with its partner? Too many connections!\n");
}

void analyze_signal_strength(int signal_strength) {
    if (signal_strength >= 0) {
        printf("Wow, a signal strength of %d dBm? You're practically surfing the web with a jetpack!\n", signal_strength);
    } else if (signal_strength >= SIGNAL_THRESHOLD) {
        printf("A signal strength of %d dBm? Not bad! You're in a decent zone, keep your internet dreams alive!\n", signal_strength);
    } else if (signal_strength >= -80) {
        printf("Oh dear, a signal strength of %d dBm? You might want to negotiate a better deal with your router!\n", signal_strength);
    } else {
        printf("A signal strength of %d dBm? You might as well be using a carrier pigeon at this point!\n", signal_strength);
    }
}

void get_wifi_data(char *wifi_info) {
    FILE *fp = popen("nmcli -t -f SSID,SIGNAL dev wifi", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (fgets(wifi_info, BUFFER_SIZE, fp) != NULL) {
        printf("Wi-Fi Data: %s", wifi_info);
        
        char *ssid = strtok(wifi_info, ":");
        char *signal_str = strtok(NULL, ":");
        int signal_strength = atoi(signal_str);
        
        printf("Analyzing signal strength for SSID: %s...\n", ssid);
        analyze_signal_strength(signal_strength);
    }

    pclose(fp);
}

void display_wifi_selection() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer 3000!\n");
    printf("Beep Boop! Get ready to analyze some Wi-Fi signals.\n\n");

    printf("Fetching Wi-Fi data...\n");
    sleep(2);
    printf("Data fetched! Time to make sense of this madness.\n\n");
}

int main() {
    funny_quote();
    display_wifi_selection();
    
    char wifi_info[BUFFER_SIZE];
    get_wifi_data(wifi_info);
    
    printf("\nThanks for using Wi-Fi Signal Strength Analyzer 3000! Remember, if life gives you low signals, change the channel!\n");
    return 0;
}