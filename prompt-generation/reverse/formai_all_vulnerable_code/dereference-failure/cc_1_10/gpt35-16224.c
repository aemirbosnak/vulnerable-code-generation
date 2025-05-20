//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL_SIZE 256
#define INTERVAL 10

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata){}

int main(int argc, char **argv) 
{
  CURL *curl = NULL;
  CURLcode res;
  char url[URL_SIZE];
  int down_count = 0;
  int up_count = 0;
  int seconds_down = 0;
  int paranoid = 1;

  if(argc < 2) {
    printf("Usage: %s <url to test>\n", argv[0]);
    return -1;
  }

  /* Initialize curl */
  curl = curl_easy_init();
  if(!curl) {
    printf("Failed to initialize curl\n");
    return -1;
  }

  /* Setup the url to monitor */
  strncpy(url, argv[1], URL_SIZE-1);
  url[URL_SIZE-1] = '\0';

  /* Setup curl */
  curl_easy_setopt(curl, CURLOPT_URL, url);

  /* Write callback function */
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

  /* Loop forever */
  while(paranoid) {
    /* Perform curl request */
    res = curl_easy_perform(curl);

    /* Check if request was successful */
    if(res != CURLE_OK) {
      /* Website is down */
      down_count++;
      up_count = 0;
      seconds_down += INTERVAL;
      printf("Website is down for %d seconds. Count: %d\n", seconds_down, down_count);

      /* Notify if website has been down for 5 minutes */
      if(seconds_down == 300) {
        printf("Website has been down for 5 minutes. Alert the authorities!\n");
        system("echo WEBSITE DOWN | mail -s 'Website Down' admin@example.com");
      }
    } else {
      /* Website is up */
      up_count++;
      down_count = 0;
      seconds_down = 0;
      printf("Website is up. Count: %d\n", up_count);

      /* Notify if website has been up for 10 minutes */
      if(up_count == 60) {
        printf("Website has been up for 10 minutes. Time to celebrate!\n");
        system("echo WEBSITE UP | mail -s 'Website Up' admin@example.com");
      }
    }

    /* Wait for INTERVAL seconds before checking again */
    sleep(INTERVAL);
  }

  /* Cleanup */
  curl_easy_cleanup(curl);

  return 0;
}