//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

/* The Turing Machine's state machine */
enum TuringState {
  START,
  READ_HEADER,
  READ_PAYLOAD,
  END
};

/* The Turing Machine's transition function */
enum TuringState transition(enum TuringState state, char input) {
  switch (state) {
    case START:
      if (input == '\x00') {
        return READ_HEADER;
      }
      break;
    case READ_HEADER:
      if (input == '\x00') {
        return READ_PAYLOAD;
      }
      break;
    case READ_PAYLOAD:
      if (input == '\x00') {
        return END;
      }
      break;
    case END:
      return END;
  }
  return state;
}

/* The Turing Machine's output function */
void output(enum TuringState state, char input) {
  switch (state) {
    case READ_HEADER:
      printf("Header: %s\n", input);
      break;
    case READ_PAYLOAD:
      printf("Payload: %s\n", input);
      break;
    case END:
      printf("End\n");
      break;
  }
}

/* The Turing Machine's main loop */
void turing(char *input) {
  enum TuringState state = START;
  char *p = input;
  while (state != END) {
    state = transition(state, *p);
    output(state, *p);
    p++;
  }
}

/* The main function */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <pcap file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *filename = argv[1];
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle = pcap_open_offline(filename, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Error opening %s: %s\n", filename, errbuf);
    return EXIT_FAILURE;
  }

  struct pcap_pkthdr header;
  const u_char *packet;
  while (pcap_next_ex(handle, &header, &packet) == 1) {
    turing((char *)packet);
  }

  pcap_close(handle);
  return EXIT_SUCCESS;
}