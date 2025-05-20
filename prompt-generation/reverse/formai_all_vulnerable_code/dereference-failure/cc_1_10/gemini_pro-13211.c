//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: genius
#include <stdio.h>
#include <curl/curl.h>

struct url_data {
  char *url;
  long code;
  char *body;
};

size_t write_data(char *ptr, size_t size, size_t nmemb, struct url_data *data) {
  size_t realsize = size * nmemb;
  data->body = realloc(data->body, data->code + realsize + 1);
  if (data->body == NULL) {
    /* out of memory! */
    fprintf(stderr, "not enough memory (realloc returned NULL)\n");
    return 0;
  }
  memcpy(&data->body[data->code], ptr, realsize);
  data->code += realsize;
  data->body[data->code] = 0;
  return realsize;
}

int check_url(char *url) {
  CURL *curl;
  CURLcode res;
  struct url_data data;
  data.url = url;
  data.code = 0;
  data.body = malloc(1);  
  data.body[0] = '\0';

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    res = curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &data.code);
    curl_easy_cleanup(curl);
    free(data.body);
  }
  return data.code;
}

int main(void) {
  int code;
  code = check_url("https://www.example.com");
  if (code == 200) {
    printf("Website is up\n");
  } else {
    printf("Website is down\n");
  }
  return 0;
}