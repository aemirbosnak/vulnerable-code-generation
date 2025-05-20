//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <time.h>

#define MAX_PACKETS 1000

struct packet_info {
  struct pcap_pkthdr header;
  const unsigned char *data;
};

int main() {
  // Open the network interface for packet capture.
  char *device = pcap_lookupdev(NULL);
  if (device == NULL) {
    printf("Error: Could not find a suitable network interface.\n");
    return EXIT_FAILURE;
  }
  pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
  if (handle == NULL) {
    printf("Error: Could not open the network interface for packet capture.\n");
    return EXIT_FAILURE;
  }

  // Initialize an array to store the captured packets.
  struct packet_info packets[MAX_PACKETS];
  int packet_count = 0;

  // Capture packets from the network interface.
  while (packet_count < MAX_PACKETS) {
    struct pcap_pkthdr *header;
    const unsigned char *data;
    int res = pcap_next_ex(handle, &header, &data);
    if (res == 0) {
      continue;
    } else if (res == -1) {
      printf("Error: pcap_next_ex() failed.\n");
      return EXIT_FAILURE;
    }
    packets[packet_count].header = *header;
    packets[packet_count].data = data;
    packet_count++;
  }

  // Close the network interface.
  pcap_close(handle);

  // Print the captured packets.
  for (int i = 0; i < packet_count; i++) {
    struct packet_info packet = packets[i];
    printf("Packet %d:\n", i + 1);
    printf("  Timestamp: %ld.%06ld\n", packet.header.ts.tv_sec, packet.header.ts.tv_usec);
    printf("  Length: %d\n", packet.header.len);
    printf("  Data: ");
    for (int j = 0; j < packet.header.len; j++) {
      printf("%02x", packet.data[j]);
    }
    printf("\n\n");
  }

  return EXIT_SUCCESS;
}