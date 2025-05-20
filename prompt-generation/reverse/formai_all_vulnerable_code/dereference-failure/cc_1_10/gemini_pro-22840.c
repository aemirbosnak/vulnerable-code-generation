//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "https://www.google.com"

struct response_data {
  char *data;
  size_t size;
};

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userp) {
  struct response_data *d = userp;
  size_t new_size = d->size + size * nmemb;
  d->data = realloc(d->data, new_size + 1);
  if (d->data == NULL) {
    fprintf(stderr, "realloc() failed\n");
    return 0;
  }
  memcpy(d->data + d->size, ptr, size * nmemb);
  d->size = new_size;
  d->data[new_size] = '\0';
  return size * nmemb;
}

int main(int argc, char *argv[]) {
  CURL *curl;
  CURLcode res;
  struct response_data d;
  int duration;
  double download_speed;

  d.data = malloc(1);
  d.size = 0;

  curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "curl_easy_init() failed\n");
    return -1;
  }

  curl_easy_setopt(curl, CURLOPT_URL, URL);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &d);

  res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    return -1;
  }

  curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &duration);
  curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &download_speed);

  printf("Download speed: %.2f kB/s\n", download_speed / 1024);
  printf("Duration: %.2f seconds\n", duration);

  free(d.data);
  curl_easy_cleanup(curl);

  return 0;
}