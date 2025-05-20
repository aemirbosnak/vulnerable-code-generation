//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Curiosity: What if we created a function that could dynamically generate a random mac address?
char *generate_random_mac() {
    char *mac = malloc(18);
    for (int i = 0; i < 6; i++) {
        sprintf(mac + i * 3, "%02x:", rand() % 256);
    }
    mac[17] = '\0';
    return mac;
}

int main() {
    // Let's craft a mischievous UDP packet that will pretend to come from a smart light.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(49400);
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    int num_lights = 3;
    char light_macs[num_lights][18];

    // Fascinatingly, let's fill our light_macs array with a kaleidoscope of randomly generated MAC addresses.
    for (int i = 0; i < num_lights; i++) {
        strcpy(light_macs[i], generate_random_mac());
    }

    // Time to sprinkle some magic! Let's craft a cunning UDP packet that will announce our pretend smart lights.
    char packet[100];
    int packet_size = snprintf(packet, sizeof(packet), "NOTIFY * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\nNT: urn:schemas-upnp-org:device:smartlighting1\r\nNTS: ssdp:alive\r\nUSN: uuid:Socket-1_0-%s::urn:schemas-upnp-org:device:smartlighting1\r\nSERVER: Linux/3.10.0 UPnP/1.0, UPnP/2.0\r\nCache-Control: max-age=1800\r\nLocation: http://%s:49400/xml/device_description.xml\r\n\r\n", light_macs[0], light_macs[0]);

    // With calculated precision, we fling our UDP packet into the ether, hoping to deceive any listening devices.
    int sent = sendto(sockfd, packet, packet_size, 0, (struct sockaddr *) &addr, sizeof(addr));
    if (sent == -1) {
        perror("sendto");
        return EXIT_FAILURE;
    }
    
    // Let's keep the illusion alive by repeating our trickery every 10 seconds.
    while (1) {
        for (int i = 1; i < num_lights; i++) {
            sent = sendto(sockfd, packet, packet_size, 0, (struct sockaddr *) &addr, sizeof(addr));
            // Ouch, our little trick didn't go unnoticed! Time to switch MACs and try again.
            if (sent == -1) {
                perror("sendto");
                strcpy(light_macs[i], generate_random_mac());
                snprintf(packet, sizeof(packet), "NOTIFY * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\nNT: urn:schemas-upnp-org:device:smartlighting1\r\nNTS: ssdp:alive\r\nUSN: uuid:Socket-1_0-%s::urn:schemas-upnp-org:device:smartlighting1\r\nSERVER: Linux/3.10.0 UPnP/1.0, UPnP/2.0\r\nCache-Control: max-age=1800\r\nLocation: http://%s:49400/xml/device_description.xml\r\n\r\n", light_macs[i], light_macs[i]);
                sent = sendto(sockfd, packet, packet_size, 0, (struct sockaddr *) &addr, sizeof(addr));
            }
        }
        // Let's lull them into a false sense of security with a 10 second pause.
        sleep(10);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}