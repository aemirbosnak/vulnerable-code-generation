//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the average response time
float calcAvgResponseTime(float total, int count) {
  return (total/count);
}

// function to calculate the number of requests per minute
int calcRequestsPerMinute(int requests, int minutes) {
  return (requests/minutes);
}

int main() {
  // initialize variables
  int totalRequests = 0, successfulRequests = 0, failedRequests = 0, totalTime = 0;
  char line[100];
  
  // loop through each line of the log file
  while(fgets(line, sizeof(line), stdin) != NULL) {
    // tokenize line to get request status and response time
    char *status = strtok(line, " ");
    char *responseTime = strtok(NULL, " ");
    
    // if successful request, increment successfulRequests and calculate total time
    if(strcmp(status, "200") == 0) {
      successfulRequests++;
      totalTime += atoi(responseTime);
    } 
    // if failed request, increment failedRequests
    else {
      failedRequests++;
    }
    
    // increment total requests
    totalRequests++;
  }
  
  // calculate average response time
  float avgResponseTime = calcAvgResponseTime(totalTime, successfulRequests);
  
  // calculate requests per minute
  int requestsPerMinute = calcRequestsPerMinute(totalRequests, 5);
  
  // print out statistics
  printf("Total Requests: %d\n", totalRequests);
  printf("Successful Requests: %d\n", successfulRequests);
  printf("Failed Requests: %d\n", failedRequests);
  printf("Average Response Time: %.2f ms\n", avgResponseTime);
  printf("Requests per Minute: %d\n", requestsPerMinute);
  
  return 0;
}