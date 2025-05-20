//LLAMA2-13B DATASET v1.0 Category: Browser Plugin ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LENGTH 1024

typedef struct {
    char *url;
    char *title;
    char *content;
} plugin_data_t;

plugin_data_t *get_plugin_data(void) {
    plugin_data_t *data = malloc(sizeof(plugin_data_t));
    char *url = getenv("PLUGIN_URL");
    char *title = getenv("PLUGIN_TITLE");
    char *content = getenv("PLUGIN_CONTENT");

    data->url = url;
    data->title = title;
    data->content = content;

    return data;
}

void free_plugin_data(plugin_data_t *data) {
    free(data->url);
    free(data->title);
    free(data->content);
    free(data);
}

int main(int argc, char *argv[]) {
    plugin_data_t *data = get_plugin_data();

    if (data == NULL) {
        fprintf(stderr, "No plugin data available\n");
        return 1;
    }

    char *content = data->content;
    size_t content_len = strlen(content);
    size_t max_len = MAX_LENGTH;
    size_t written = 0;

    while (written < content_len) {
        size_t to_write = content_len - written;
        if (to_write > max_len) {
            to_write = max_len;
        }

        if (write(STDOUT_FILENO, content + written, to_write) < 0) {
            perror("write");
            return 1;
        }

        written += to_write;
    }

    free_plugin_data(data);

    return 0;
}