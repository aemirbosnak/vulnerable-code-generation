//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to check the network quality and have a little fun
void check_network_quality(const char *interface_name) {
    int sockfd;
    struct ifreq ifr;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Oops! I couldn’t create a socket. Did someone forget to pay the electricity bill?");
        exit(EXIT_FAILURE);
    }

    strncpy(ifr.ifr_name, interface_name, IFNAMSIZ - 1);
    
    // Check if the interface is up and running
    if (ioctl(sockfd, SIOCGIFFLAGS, &ifr) < 0) {
        perror("Error during ioctl. Is the interface off vacation or what?");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (!(ifr.ifr_flags & IFF_RUNNING)) {
        fprintf(stderr, "Seems like %s is taking a nap... Where are you, buddy?\n", interface_name);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Get the IP address of the network interface
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) < 0) {
        perror("Failed to get the address. Maybe it forgot its ID card?");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    addr = *(struct sockaddr_in *)&ifr.ifr_addr;
    printf("Network Interface %s is alive! 🏄‍♂️\n", interface_name);
    printf("IP Address: %s\n", inet_ntoa(addr.sin_addr));

    // Simulate quality check
    int signal_strength = rand() % 100;
    printf("Fetching the Quality Score...\n");
    sleep(1); // Dramatic pause
    if (signal_strength > 75) {
        printf("Signal Strength: %d%% - Everything's awesome! 🎉\n", signal_strength);
    } else if (signal_strength > 50) {
        printf("Signal Strength: %d%% - It's okay... like your friend who always flops at karaoke nights. 🎤\n", signal_strength);
    } else if (signal_strength > 25) {
        printf("Signal Strength: %d%% - Uh-oh, things are looking shaky. Time to count the beans, my friend! 📉\n", signal_strength);
    } else {
        printf("Signal Strength: %d%% - The internet is running as fast as a tortoise on a treadmill. 🐢💨\n", signal_strength);
    }

    // Monitor Network Quality in a while loop (don’t worry, it's just a friendly loop)
    for (int i = 1; i <= 5; i++) {
        sleep(2); // Pretend to work hard
        signal_strength = rand() % 100;
        if (signal_strength < 50) {
            printf("Warning! Quality dropping! Only %d%% left. Call for backup! 🚨\n", signal_strength);
        } else {
            printf("Network Quality is at %d%% - Good job! You've got this! 🎈\n", signal_strength);
        }
    }

    close(sockfd);
    printf("All done! Hope your packets travel faster than your internet emoji skills! 😂\n");
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Placeholder for interface name
    char interface[BUFFER_SIZE];
    printf("Enter the network interface (like eth0, wlan0): ");
    fgets(interface, BUFFER_SIZE, stdin);
    
    interface[strcspn(interface, "\n")] = 0; // Remove trailing newline
    
    check_network_quality(interface);
    return 0;
}