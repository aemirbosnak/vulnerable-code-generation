//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold the response data
struct MemoryStruct {
  char *memory;
  size_t size;
};

// Callback function for writing data received from the HTTP request
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
  size_t realsize = size * nmemb;
  userp->memory = realloc(userp->memory, userp->size + realsize + 1);
  if (userp->memory == NULL) {
    fprintf(stderr, "Not enough memory!\n");
    return 0; // Out of memory!
  }

  memcpy(&(userp->memory[userp->size]), contents, realsize);
  userp->size += realsize;
  userp->memory[userp->size] = 0; // Null-terminate the string

  return realsize;
}

// Function to fetch the URL content
void fetch_url(const char *url) {
  CURL *curl;
  CURLcode res;
  struct MemoryStruct chunk;

  chunk.memory = malloc(1);  // Initial allocation
  chunk.size = 0;            // No data at this point

  // Initialize a curl session
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "MyCBrowserPlugin/1.0"); // Set user agent
    
    // Perform the request
    res = curl_easy_perform(curl);
    
    // Check for errors
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
      printf("Fetched URL: %s\n", url);
      printf("Content:\n%s\n", chunk.memory); // Print the HTML content
    }

    // Clean up
    curl_easy_cleanup(curl);
    free(chunk.memory);
  }

  curl_global_cleanup();
}

int main() {
  char url[256];

  printf("Welcome to My C Browser Plugin!\n");
  printf("Enter a URL to fetch its HTML content:\n");

  // Get user input
  fgets(url, sizeof(url), stdin);
  // Remove the newline character from the input
  url[strcspn(url, "\n")] = 0;

  if(strlen(url) > 0) {
    fetch_url(url);  // Fetch the content of the URL
  } else {
    printf("You entered an empty URL!\n");
  }

  printf("Thank you for using My C Browser Plugin! See you next time!\n");
  return 0;
}