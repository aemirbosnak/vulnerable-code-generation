//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MB 1048576 // 1 megabyte in bytes

// Function to generate random speeds between 5 and 200 Megabits per second (Mbps)
double getSpeed() {
  return ((double)(rand() % 196 + 5)) / 8.0;
}

// Function to simulate a download by generating random data and calculating the time taken
double downloadTest(int size) {
  clock_t startTime, endTime;
  double speed;

  startTime = clock();

  // Generate random data of given size
  unsigned char* data = (unsigned char*)malloc(size * sizeof(unsigned char));
  for(int i = 0; i < size; i++)
    data[i] = (unsigned char)(rand() % 256);

  endTime = clock();

  // Calculate time taken and speed in Megabits per second (Mbps)
  double timeTaken = ((double)endTime - (double)startTime) / (double)CLOCKS_PER_SEC;
  speed = ((double)size * 8.0 / MB) / timeTaken;

  free(data);

  return speed;
}

// Function to display the result of the speed test
void displayResult(double speed) {
  printf("Your internet download speed is %.2f Mbps\n\n", speed);
  if(speed < 10.0)
    printf("Your internet speed is very slow.\n");
  else if(speed < 25.0)
    printf("Your internet speed is okay.\n");
  else if(speed < 50.0)
    printf("Your internet speed is good.\n");
  else
    printf("Your internet speed is excellent!\n");
}

int main() {
  int size = 100 * MB; // 100 megabytes
  double speed;

  srand(time(NULL)); // Initialize random seed

  // Display instructions to the user
  printf("Welcome to the Internet Speed Test Application\n");
  printf("This application will simulate a download of %d MB to test your internet speed\n", size / MB);
  printf("Press Enter to begin the test\n\n");
  getchar();

  // Perform the speed test
  printf("Testing download speed...\n");
  speed = getSpeed();
  printf("Download speed: %.2f Mbps\n\n", speed);

  // Simulate actual download and calculate speed
  printf("Simulating download...\n");
  speed = downloadTest(size);

  // Display the result of the speed test
  displayResult(speed);

  return 0;
}