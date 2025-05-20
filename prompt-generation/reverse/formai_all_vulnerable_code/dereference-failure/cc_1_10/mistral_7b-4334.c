//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    size_t req_count;
    size_t total_bytes;
} log_stats_t;

void parse_line(const char *line, log_stats_t *stats) {
    char method[8], uri[256], protocol[12], client_ip[16];
    size_t method_len, uri_len, protocol_len, client_ip_len;

    sscanf(line, "%s %n %s %n %s %n %s %n %s %n %s %n %s %n %s %n %s",
           method, &method_len,        // request line method
           "",                         // request line URL
           uri,                        // request line URI
           &uri_len,                   // request line URI length
           protocol,                   // request line protocol
           &protocol_len,              // request line protocol length
           client_ip,                  // client IP
           &client_ip_len,             // client IP length
           "",                         // request status code
           "",                         // request status reason
           "",                         // client user agent
           "",                         // request request time
           "");                        // request request time in Unix timestamp

    // skip empty lines and log lines without valid client IP addresses
    if (method_len > 0 && uri_len > 0 && client_ip_len > 0) {
        ++stats->req_count;
        stats->total_bytes += strlen(uri) + strlen(protocol) + client_ip_len + 13; // 13: space, tab, and newline characters
    }
}

int main() {
    FILE *fp;
    char line[1024];
    log_stats_t stats = {0};

    if ((fp = fopen("access.log", "r")) == NULL) {
        perror("Error opening access.log");
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        parse_line(line, &stats);
    }

    printf("Total requests: %zu\n", stats.req_count);
    printf("Total bytes transferred: %zu\n", stats.total_bytes);
    printf("Average request size: %.2f bytes\n", (float)stats.total_bytes / stats.req_count);

    fclose(fp);
    return EXIT_SUCCESS;
}