//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 1024 * 1024 * 10

// Structure to store log data
typedef struct {
    int request_count;
    double response_time_mean;
    double response_time_stddev;
    double error_rate;
} log_data_t;

// Function to parse log file and calculate statistics
log_data_t* parse_log_file(const char* log_file_path) {
    log_data_t* data = malloc(sizeof(log_data_t));
    FILE* log_file = fopen(log_file_path, "r");

    // Initialize request count to 0
    data->request_count = 0;

    // Read log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        // Ignore empty lines and comments
        if (strlen(line) == 0 || line[0] == '#') continue;

        // Extract request information
        char* request_time = strtok(line, " ");
        char* request_method = strtok(NULL, " ");
        char* request_uri = strtok(NULL, " ");
        char* response_code = strtok(NULL, " ");

        // Increment request count
        data->request_count++;

        // Calculate response time
        double response_time = atof(request_time);
        data->response_time_mean += response_time;
        data->response_time_stddev += (response_time - data->response_time_mean) * (response_time - data->response_time_mean);

        // Calculate error rate
        if (strcmp(response_code, "200") != 0) {
            data->error_rate++;
        }
    }

    // Calculate mean and standard deviation of response time
    data->response_time_mean /= data->request_count;
    data->response_time_stddev = sqrt(data->response_time_stddev / data->request_count);

    // Close log file
    fclose(log_file);

    return data;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    // Parse log file
    log_data_t* data = parse_log_file(argv[1]);

    // Print statistics
    printf("Request Count: %d\n", data->request_count);
    printf("Mean Response Time: %f seconds\n", data->response_time_mean);
    printf("Standard Deviation of Response Time: %f seconds\n", data->response_time_stddev);
    printf("Error Rate: %f\n", data->error_rate);

    // Free memory
    free(data);

    return 0;
}