//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256

/* A struct to hold information about a website */
typedef struct {
  char *url;
  CURL *curl_handler;
} Website;

/* Callback function used by libcurl, writes downloaded content to /dev/null */
size_t write_data_to_null(char *ptr, size_t size, size_t nmemb, void *userdata)
{
  return size * nmemb;
}

/* Create and initialize a new Website object */
Website *create_website(char *url)
{
  Website *site = malloc(sizeof(Website));
  site->url = url;
  site->curl_handler = curl_easy_init();
  curl_easy_setopt(site->curl_handler, CURLOPT_WRITEDATA, NULL);
  curl_easy_setopt(site->curl_handler, CURLOPT_WRITEFUNCTION, write_data_to_null);
  curl_easy_setopt(site->curl_handler, CURLOPT_URL, site->url);
  return site;
}

/* Check if a website is up or down */
int is_website_up(Website *site)
{
  long http_code = 0;
  curl_easy_setopt(site->curl_handler, CURLOPT_NOBODY, 1L);
  curl_easy_setopt(site->curl_handler, CURLOPT_HEADER, 1L);
  CURLcode res = curl_easy_perform(site->curl_handler);
  if (res != CURLE_OK) {
    fprintf(stderr, "Error performing curl request: %s\n", curl_easy_strerror(res));
    return -1;
  }
  res = curl_easy_getinfo(site->curl_handler, CURLINFO_RESPONSE_CODE, &http_code);
  if (res != CURLE_OK) {
    fprintf(stderr, "Error getting HTTP response code: %s\n", curl_easy_strerror(res));
    return -1;
  }
  return (http_code == 200) ? 1 : 0;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("Usage: %s [site urls]\n", argv[0]);
    exit(0);
  }
  printf("Starting website uptime monitor...\n");
  Website *sites[argc - 1];
  for (int i = 1; i < argc; ++i) {
    char *url = argv[i];
    if (strlen(url) > MAX_URL_LENGTH) {
      printf("Error: URL '%s' exceeds maximum length of %d characters\n", url, MAX_URL_LENGTH);
      exit(1);
    }
    sites[i - 1] = create_website(url);
  }
  while (1) {
    printf("Checking websites...\n");
    for (int i = 0; i < argc - 1; ++i) {
      printf("Checking '%s'...\n", sites[i]->url);
      int result = is_website_up(sites[i]);
      if (result == -1) {
        printf("Error checking website '%s'\n", sites[i]->url);
        continue;
      }
      if (result == 1) {
        printf("Website '%s' is UP!\n", sites[i]->url);
      } else {
        printf("Website '%s' is DOWN!\n", sites[i]->url);
      }
    }
    sleep(60);
  }
  return 0;
}