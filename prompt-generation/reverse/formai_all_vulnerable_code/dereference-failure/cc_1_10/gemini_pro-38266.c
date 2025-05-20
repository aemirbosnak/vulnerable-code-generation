//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// A captivating callback function to handle HTTP responses
size_t danceWithResponse(void* payload, size_t size, size_t nmemb, void* userdata) {
  // Cast userdata back to our enthusiastic buffer
  char** buffer = (char**)userdata;
  
  // Magnify our buffer's realm to embrace the incoming bytes
  *buffer = realloc(*buffer, strlen(*buffer) + size * nmemb + 1);
  
  // Gracefully weave the response into our tapestry of knowledge
  memcpy(*buffer + strlen(*buffer), payload, size * nmemb);

  // Always leave room for enchantment by null-terminating our string
  (*buffer)[strlen(*buffer)] = '\0';

  // Return the size of our captivated response
  return size * nmemb;
}

int main(void) {
  // Initialize our CURL library, the gateway to HTTP adventures
  curl_global_init(CURL_GLOBAL_ALL);

  // Craft our request, a beacon of curiosity
  CURL* curl = curl_easy_init();
  if (!curl) {
    printf("Alas, our request to curl fizzled into oblivion!\n");
    return 1;
  }

  // Set sail for the vastness of the web
  curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

  // Prepare our buffer, a canvas for the HTTP response
  char* buffer = malloc(1);
  *buffer = '\0';

  // Define our magical callback function, the guardian of responses
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, danceWithResponse);

  // Link our buffer to the callback, creating an unbreakable bond
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

  // Cast the spell to retrieve the HTTP response
  CURLcode res = curl_easy_perform(curl);

  // Did our spell succeed?
  if (res != CURLE_OK) {
    printf("Our request to the ethereal web encountered a cruel twist of fate: %s\n", curl_easy_strerror(res));
    free(buffer);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 1;
  }

  // Behold, the HTTP response in all its glory!
  printf("The web has graced us with its wisdom:\n%s\n", buffer);

  // Release our resources gracefully
  free(buffer);
  curl_easy_cleanup(curl);
  curl_global_cleanup();

  return 0;
}