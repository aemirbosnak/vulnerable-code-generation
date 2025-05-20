//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

/*This function checks the website response and returns the status code*/
int getWebsiteStatus(char* website) {
  CURL *curlHandle;
  CURLcode result;
  long httpCode = 0;

  curlHandle = curl_easy_init();
  if (curlHandle) {
    curl_easy_setopt(curlHandle, CURLOPT_URL, website);
    curl_easy_setopt(curlHandle, CURLOPT_FOLLOWLOCATION, 1L);
    result = curl_easy_perform(curlHandle);
    if(result != CURLE_OK) {
      printf("Error: %s\n", curl_easy_strerror(result));
    }
    else {
      curl_easy_getinfo(curlHandle,CURLINFO_RESPONSE_CODE,&httpCode);
    }
    curl_easy_cleanup(curlHandle);
  }
  return httpCode;
}

/*This function logs a message with the current date and time*/
void logMessage(char* message) {
  time_t currentTime;
  struct tm* localTime;
  currentTime = time(NULL);
  localTime = localtime(&currentTime);
  printf("%02d:%02d:%02d %s\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec, message);
}

int main() {
  char* website = "https://www.example.com";
  int statusCode = 0;

  while(1) {
    statusCode = getWebsiteStatus(website);
    if(statusCode != 200) {
      logMessage("Website is down!");
    }
    else {
      logMessage("Website is up!");
    }
    sleep(60); /*wait for 60 seconds before the next check*/
  }
  return 0;
}