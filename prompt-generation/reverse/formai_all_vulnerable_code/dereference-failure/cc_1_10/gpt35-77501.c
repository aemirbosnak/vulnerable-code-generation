//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
// Define a structure to hold temperature data
struct temperatureData {
   float tempValue;
   char timeStamp[20];
   bool isFahrenheit;
};

// Define a linked list node structure
struct Node {
   struct temperatureData data;
   struct Node* next;
};

// Declare function prototypes
struct Node* addTemperatureToList(struct Node*, float, bool);
void printTemperatureList(struct Node*);
float convertCelsiusToFahrenheit(float);
void writeToLog(struct temperatureData);

int main() {
   // Set up random seed for simulated temperature data
   srand(time(0));
   
   // Print a welcome message to the user
   printf("Welcome to the Temperature Monitor Program\n");
   
   // Create a new linked list to store temperature data
   struct Node* temperatureList = NULL;
   
   // Request input from user to determine whether to start the program in Fahrenheit or Celsius
   char userInput[10];
   bool usingFahrenheit = false;
   printf("Please choose either Fahrenheit or Celsius: ");
   scanf("%s", userInput);
   if (strcmp(userInput, "Fahrenheit") == 0 || strcmp(userInput, "fahrenheit") == 0) {
      usingFahrenheit = true;
      printf("\nStarting program using Fahrenheit\n");
   } else {
      printf("\nStarting program using Celsius\n");
   }
   
   // Set up loop to generate random temperature data
   int loopCount = 10;
   while (loopCount > 0) {
      // Create new temperature data value
      float tempValue = (float)rand()/(float)(RAND_MAX/100);
      // Check whether to use Fahrenheit or Celsius
      if (usingFahrenheit) {
         tempValue = convertCelsiusToFahrenheit(tempValue);
      }
      // Get the current timestamp
      time_t t = time(NULL);
      struct tm tm = *localtime(&t);
      char timeStamp[20];
      sprintf(timeStamp, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
      // Create a new node for the linked list
      temperatureList = addTemperatureToList(temperatureList, tempValue, usingFahrenheit);
      // Write the temperature data to a log file
      struct temperatureData temperature = { tempValue, timeStamp, usingFahrenheit };
      writeToLog(temperature);
      // Sleep for one second to simulate realtime monitoring
      sleep(1);
      loopCount--;
   }
   // Print the full temperature list to the console
   printf("\n\nFull Temperature List:\n");
   printTemperatureList(temperatureList);
   return 0;
}

struct Node* addTemperatureToList(struct Node* head, float value, bool isF) {
   // Create a new node for the linked list
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   // Add the temperature data to the new node
   struct temperatureData data = { value, "", isF };
   newNode->data = data;
   newNode->next = NULL;
   
   // Traverse the linked list to the end and append the new node
   if (head == NULL) {
      head = newNode;
   } else {
      struct Node* currentNode = head;
      while (currentNode->next != NULL) {
         currentNode = currentNode->next;
      }
      currentNode->next = newNode;
   }
   return head;
}

void printTemperatureList(struct Node* head) {
   // Print each temperature node in the linked list
   struct Node* currentNode = head;
   while (currentNode != NULL) {
      printf("Temperature: %.2f %s ", currentNode->data.tempValue, currentNode->data.isFahrenheit ? "F" : "C");
      printf("Time: %s\n", currentNode->data.timeStamp);
      currentNode = currentNode->next;
   }
}

float convertCelsiusToFahrenheit(float celsius) {
   return (celsius * 1.8) + 32;
}

void writeToLog(struct temperatureData data) {
   // Open the temperature data log file
   FILE* filePtr;
   filePtr = fopen("temperature_log.txt", "a");
   if (filePtr == NULL) {
      printf("Error opening log file\n");
      return;
   }
   // Write the temperature data to the log file
   fprintf(filePtr, "%.2f %s at %s\n", data.tempValue, data.isFahrenheit ? "F" : "C", data.timeStamp);
   // Close the file
   fclose(filePtr);
}