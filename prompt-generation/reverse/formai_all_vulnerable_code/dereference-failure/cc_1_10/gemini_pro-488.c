//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: unmistakable
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Custom network packet header
typedef struct {
  uint32_t timestamp;
  uint16_t length;
  uint8_t type;
} nh_t;

// Custom network packet payload
typedef struct {
  char data[1024];
} payload_t;

// Custom network packet
typedef struct {
  nh_t header;
  payload_t payload;
} packet_t;

// Capture thread function
void* capture_thread(void* arg) {
  char* dev = (char*) arg;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t* handle = pcap_open_live(dev, 65535, 1, 1000, errbuf);
  if (!handle) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    exit(1);
  }
  while (1) {
    struct pcap_pkthdr* header;
    const u_char* data;
    int res = pcap_next_ex(handle, &header, &data);
    if (res == 1) {
      // Extract custom network packet
      packet_t* packet = (packet_t*) data;
      printf("Timestamp: %u\n", ntohl(packet->header.timestamp));
      printf("Length: %u\n", ntohs(packet->header.length));
      printf("Type: %u\n", packet->header.type);
      printf("Data: %s\n", packet->payload.data);
      printf("\n");
    }
  }
  pcap_close(handle);
  return NULL;
}

int main() {
  // Initialize network interface
  char dev[] = "eth0";
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t* handle = pcap_open_live(dev, 65535, 1, 1000, errbuf);
  if (!handle) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    exit(1);
  }

  // Create capture thread
  pthread_t tid;
  pthread_create(&tid, NULL, capture_thread, (void*) dev);

  // Wait for user input
  char c;
  while ((c = getchar()) != 'q') {
    // Handle user input (e.g., start/stop capture, change filters)
  }

  // Join capture thread
  pthread_join(tid, NULL);

  // Close network interface
  pcap_close(handle);

  return 0;
}