//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <curl/curl.h>
#include <stdio.h>

struct ftp_data {
  CURL *curl_handle;
  char *buffer;
  size_t buffer_size;
  size_t buffer_used;
};

struct ftp_data *ftp_init(void) {
  struct ftp_data *data = malloc(sizeof(struct ftp_data));
  data->curl_handle = curl_easy_init();
  data->buffer = malloc(1024);
  data->buffer_size = 1024;
  data->buffer_used = 0;
  return data;
}

void ftp_cleanup(struct ftp_data *data) {
  curl_easy_cleanup(data->curl_handle);
  free(data->buffer);
  free(data);
}

void ftp_set_url(struct ftp_data *data, const char *url) {
  curl_easy_setopt(data->curl_handle, CURLOPT_URL, url);
}

void ftp_set_user(struct ftp_data *data, const char *user) {
  curl_easy_setopt(data->curl_handle, CURLOPT_USERNAME, user);
}

void ftp_set_password(struct ftp_data *data, const char *password) {
  curl_easy_setopt(data->curl_handle, CURLOPT_PASSWORD, password);
}

int ftp_connect(struct ftp_data *data) {
  return curl_easy_perform(data->curl_handle);
}

int ftp_read_line(struct ftp_data *data, char **line) {
  size_t nread;
  int ret;
  *line = NULL;

  if (data->buffer_used == 0) {
    ret = curl_easy_recv(data->curl_handle, data->buffer, data->buffer_size, &nread);
    if (ret != CURLE_OK || nread == 0) {
      return ret;
    }
    data->buffer_used = nread;
  }

  while (data->buffer_used > 0) {
    char *lf = memchr(data->buffer, '\n', data->buffer_used);
    if (lf) {
      *lf = '\0';
      *line = data->buffer;
      data->buffer = lf + 1;
      data->buffer_used -= (lf - data->buffer) + 1;
      return CURLE_OK;
    } else {
      size_t nmove = data->buffer_size - data->buffer_used;
      memmove(data->buffer, data->buffer + data->buffer_used, nmove);
      data->buffer_used = nmove;
      ret = curl_easy_recv(data->curl_handle, data->buffer + data->buffer_used, data->buffer_size - data->buffer_used, &nread);
      if (ret != CURLE_OK || nread == 0) {
        return ret;
      }
      data->buffer_used += nread;
    }
  }

  return CURLE_OK;
}

int main(void) {
  struct ftp_data *data = ftp_init();
  ftp_set_url(data, "ftp://ftp.example.com/");
  ftp_set_user(data, "user");
  ftp_set_password(data, "password");
  ftp_connect(data);

  char *line;
  while (ftp_read_line(data, &line) == CURLE_OK) {
    printf("%s\n", line);
  }

  ftp_cleanup(data);
  return 0;
}