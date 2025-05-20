//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

// Function to check website availability
int check_website_availability(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    
    // Perform the request, res will get the return code
    res = curl_easy_perform(curl);
    
    // Clean up
    curl_easy_cleanup(curl);

    return (res == CURLE_OK) ? 1 : 0;
  }
  
  return 0;
}

int main() {
  char website[100];
  int interval, availability;

  printf("Enter the website url to monitor: ");
  gets(website);
  
  printf("Enter the monitoring interval in seconds: ");
  scanf("%d", &interval);

  while (1) {
    availability = check_website_availability(website);

    time_t now;
    struct tm *current_time;
    now = time(NULL);
    
    current_time = localtime(&now);

    printf("%d:%d:%d - %s is %s\n", 
      current_time->tm_hour, current_time->tm_min, current_time->tm_sec, website, (availability ? "up" : "down"));

    sleep(interval);
  }

  return 0;
}