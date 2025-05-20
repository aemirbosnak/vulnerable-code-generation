//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h> // This library is required to make HTTP requests
#include <time.h>
#include <string.h>

void check_website(char *url, int delay);

// This struct holds the data that we want to pass to the function that receives curl responses
struct MemoryStruct {
  char *memory;
  size_t size;
};

// This function collects the response from curl and stores it in our MemoryStruct
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    printf("Out of memory\n");
    return 0;
  }
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
  return realsize;
}

int main() {
  char *urls[] = {"https://www.google.com", "https://www.microsoft.com", "https://www.apple.com", "https://www.amazon.com"};
  int num_urls = sizeof(urls) / sizeof(urls[0]);
  int delay = 60; // Number of seconds to wait between checks

  while (1) {
    for (int i = 0; i < num_urls; i++) {
      check_website(urls[i], delay);
      printf("==============================================\n");
    }
    printf("\n");
  }

  return 0;
}

void check_website(char *url, int delay) {
  CURL *curl_handle;
  CURLcode res;

  struct MemoryStruct chunk;

  chunk.memory = malloc(1);
  chunk.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();

  curl_easy_setopt(curl_handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 0L); // Change this to 1L if you want to see verbose output

  /* Perform the request */
  res = curl_easy_perform(curl_handle);

  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
  }
  else {
    time_t current_time;
    current_time = time(NULL);
    printf("[%s] %s\n", strtok(ctime(&current_time), "\n"), url);
    printf("%s\n", chunk.memory);
  }

  curl_easy_cleanup(curl_handle);
  free(chunk.memory);

  sleep(delay);
}