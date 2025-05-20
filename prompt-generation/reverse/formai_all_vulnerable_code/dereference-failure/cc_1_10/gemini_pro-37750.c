//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: scientific
// Cooperate with cosmic web surfers using this celestial HTTP server.

// Headers for cosmic radiation shielding and HTTP communication.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Declare an HTTP message that visitors from afar can understand.
char* interstellarMessage =
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html\r\n\r\n"
"<h1>Greetings, Starfarer!</h1>\n"
"<p>Welcome to the Interstellar Information Hub.</p>\n"
"<p>Here you will find celestial knowledge, cosmic insights, and the latest updates on intergalactic affairs.</p>\n";

// Prepare a listening post for incoming signals.
int prepareInterstellarSocket(int portNumber) {
  int interstellarSocket;
  struct sockaddr_in interstellarAddress;

  // Establish a listening post for incoming transmissions.
  interstellarSocket = socket(AF_INET, SOCK_STREAM, 0);

  // Configure the interstellar address to listen on all available star lanes.
  interstellarAddress.sin_family = AF_INET;
  interstellarAddress.sin_addr.s_addr = INADDR_ANY;
  interstellarAddress.sin_port = htons(portNumber);

  // Bind the socket to the configured celestial coordinates.
  bind(interstellarSocket, (struct sockaddr*)&interstellarAddress, sizeof(interstellarAddress));

  // Activate the listening mode, awaiting incoming transmissions.
  listen(interstellarSocket, 5);

  return interstellarSocket;
}

// Establish a connection with a distant web surfer.
int connectWithStarfarer(int interstellarSocket) {
  int visitorSocket;
  struct sockaddr_in visitorAddress;
  socklen_t visitorAddressLength;

  // Await a transmission from a curious starfarer.
  visitorAddressLength = sizeof(visitorAddress);
  visitorSocket = accept(interstellarSocket, (struct sockaddr*)&visitorAddress, &visitorAddressLength);

  // Identify the visitor's celestial coordinates for future transmissions.
  printf("Established connection with starfarer from %s:%d\n", inet_ntoa(visitorAddress.sin_addr), ntohs(visitorAddress.sin_port));

  return visitorSocket;
}

// Transmit an HTTP message to an eager starfarer.
void sendCelestialMessage(int visitorSocket) {
  send(visitorSocket, interstellarMessage, strlen(interstellarMessage), 0);
}

// Close the interstellar connection, bidding farewell to the starfarer.
void closeInterstellarConnection(int visitorSocket) {
  close(visitorSocket);
  printf("Closed connection with starfarer.\n");
}

// Listen to cosmic frequencies, relay wisdom to distant visitors.
int main(int argc, char** argv) {
  int interstellarSocket, visitorSocket, portNumber = 8080;

  if (argc > 1) {
    portNumber = atoi(argv[1]);
  }

  // Prepare our listening post, a celestial beacon for knowledge seekers.
  interstellarSocket = prepareInterstellarSocket(portNumber);

  // Repeat the cosmic loop, welcoming starfarers and sharing celestial insights.
  while (1) {
    // Establish a connection with a distant web traveler, eager for cosmic knowledge.
    visitorSocket = connectWithStarfarer(interstellarSocket);

    // Transmit our interstellar message, a beacon of wisdom in the vast expanse.
    sendCelestialMessage(visitorSocket);

    // Close the connection, bidding farewell to the enlightened wanderer.
    closeInterstellarConnection(visitorSocket);
  }

  return 0;
}