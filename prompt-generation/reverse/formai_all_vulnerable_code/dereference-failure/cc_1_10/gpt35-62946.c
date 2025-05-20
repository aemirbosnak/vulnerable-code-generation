//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: random
#include <stdio.h>
#include <pcap.h>

int main() {

  printf("Starting packet capture...\n");

  char dev[] = "eth0";  // Define network device to be used
  char errbuf[PCAP_ERRBUF_SIZE];  // Buffer to capture errors

  // Open network device for packet capture
  pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

  if (handle == NULL) {
    printf("Error opening device: %s\n", errbuf);
    return 1;
  }

  // Capture 10 packets and output their details
  printf("Capturing packets...\n");

  struct pcap_pkthdr header;
  const u_char *packet;
  int packetCount = 0;

  while (packetCount < 10) {
    packet = pcap_next(handle, &header);

    if (packet == NULL) {
      printf("Error capturing packet\n");
      return 1;
    }

    printf("\nPacket #%d\n", packetCount);
    printf("Length: %d bytes\n", header.len);
    printf("Timestamp: %s\n", ctime((const time_t*)&header.ts.tv_sec));

    // Print packet data in hex
    for (int i = 0; i < header.len; i++) {
      printf("%02x ", packet[i]);
      if ((i + 1) % 16 == 0) printf("\n");
    }

    packetCount++;
  }

  // Close network device
  printf("\nPacket capture complete.\n");
  pcap_close(handle);

  return 0;
}