//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "https://api.iextrading.com/1.0/stock/aapl/quote"

struct memory_struct {
  char *memory;
  size_t size;
};

static size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
  struct memory_struct *mem = (struct memory_struct *)userdata;
  size_t realsize = size * nmemb;
  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    printf("realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(&(mem->memory[mem->size]), ptr, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
  return realsize;
}

int main(void) {
  CURL *curl;
  CURLcode res;
  struct memory_struct chunk;
  curl_global_init(CURL_GLOBAL_DEFAULT);  

  chunk.memory = malloc(1);  
  chunk.size = 0;    

  curl = curl_easy_init();
  if (curl) 
  {
      curl_easy_setopt(curl, CURLOPT_URL, URL);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
      
      res = curl_easy_perform(curl);

      if (res == CURLE_OK) 
      {
        printf("%s", chunk.memory);
      } 
      else
      {
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      }

      free(chunk.memory);
      curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}