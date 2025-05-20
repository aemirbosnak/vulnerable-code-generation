//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "http://speedtest.net"
#define TIMEOUT 10
#define BUFSIZE 1024

struct speedtest {
  CURL *curl;
  char *buffer;
  size_t size;
};

static size_t write_callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
  struct speedtest *st = (struct speedtest *)stream;
  size_t new_size = st->size + size * nmemb;
  st->buffer = realloc(st->buffer, new_size + 1);
  if (st->buffer == NULL) {
    return 0;
  }
  memcpy(st->buffer + st->size, ptr, size * nmemb);
  st->size = new_size;
  st->buffer[st->size] = '\0';
  return size * nmemb;
}

static int speedtest_init(struct speedtest *st)
{
  st->curl = curl_easy_init();
  if (st->curl == NULL) {
    return -1;
  }
  st->buffer = malloc(BUFSIZE);
  if (st->buffer == NULL) {
    return -1;
  }
  st->size = 0;
  curl_easy_setopt(st->curl, CURLOPT_URL, URL);
  curl_easy_setopt(st->curl, CURLOPT_TIMEOUT, TIMEOUT);
  curl_easy_setopt(st->curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(st->curl, CURLOPT_WRITEDATA, st);
  return 0;
}

static void speedtest_cleanup(struct speedtest *st)
{
  curl_easy_cleanup(st->curl);
  free(st->buffer);
}

static int speedtest_run(struct speedtest *st)
{
  CURLcode res = curl_easy_perform(st->curl);
  if (res != CURLE_OK) {
    return -1;
  }
  return 0;
}

static int speedtest_parse(struct speedtest *st)
{
  char *ptr = strstr(st->buffer, "Download Speed:");
  if (ptr == NULL) {
    return -1;
  }
  ptr += strlen("Download Speed:");
  while (*ptr == ' ' || *ptr == '\n') {
    ptr++;
  }
  char *end = strchr(ptr, ' ');
  if (end == NULL) {
    return -1;
  }
  *end = '\0';
  printf("Download speed: %s\n", ptr);
  return 0;
}

int main(int argc, char **argv)
{
  struct speedtest st;
  if (speedtest_init(&st) != 0) {
    return EXIT_FAILURE;
  }
  if (speedtest_run(&st) != 0) {
    return EXIT_FAILURE;
  }
  if (speedtest_parse(&st) != 0) {
    return EXIT_FAILURE;
  }
  speedtest_cleanup(&st);
  return EXIT_SUCCESS;
}