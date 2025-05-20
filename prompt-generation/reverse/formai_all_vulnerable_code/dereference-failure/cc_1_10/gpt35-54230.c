//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

#define MAX_PACKET_SIZE 1024
#define MAX_PACKETS 1000

int packet_count;
char** packets;

void process_packet(char* packet) {
  int i;
  char keywords[5][10] = {"attack", "hack", "exploit", "malware", "virus"};
  
  for(i=0; i<5; i++) {
    if(strstr(packet, keywords[i]) != NULL) {
      printf("Intrusion detected: packet includes keyword '%s'\n", keywords[i]);
      return;
    }
  }
  
  printf("Packet is clean.\n");
}

int main() {
  int i;
  
  packets = (char**) malloc(sizeof(char*) * MAX_PACKETS);
  for(i=0; i<MAX_PACKETS; i++) {
    packets[i] = (char*) malloc(sizeof(char) * MAX_PACKET_SIZE);
  }
  
  packet_count = 0;
  
  while(1) {
    printf("Enter packet (enter 'exit' to quit): ");
    scanf("%s", packets[packet_count]);
    
    if(strcmp(packets[packet_count], "exit") == 0) {
      break;
    }
    
    process_packet(packets[packet_count]);
    packet_count++;
  }
  
  for(i=0; i<MAX_PACKETS; i++) {
    free(packets[i]);
  }
  free(packets);
  
  return 0;
}