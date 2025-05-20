//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to store intrusion detection data */
struct intrusion_detection_data {
    char *source_ip;
    char *destination_ip;
    char *port;
    char *protocol;
    char *timestamp;
    char *signature;
};

/* Function to parse intrusion detection data from a file */
struct intrusion_detection_data *parse_intrusion_detection_data(char *filename) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct intrusion_detection_data *data = NULL;

    /* Open the file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    /* Allocate memory for the data structure */
    data = malloc(sizeof(struct intrusion_detection_data));
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    /* Read the first line of the file */
    read = getline(&line, &len, fp);
    if (read == -1) {
        perror("getline");
        fclose(fp);
        free(data);
        return NULL;
    }

    /* Parse the first line of the file */
    char *fields[6];
    char *field;
    int i = 0;
    field = strtok(line, ",");
    while (field != NULL) {
        fields[i++] = field;
        field = strtok(NULL, ",");
    }

    /* Assign the values to the data structure */
    data->source_ip = fields[0];
    data->destination_ip = fields[1];
    data->port = fields[2];
    data->protocol = fields[3];
    data->timestamp = fields[4];
    data->signature = fields[5];

    /* Free the line buffer */
    free(line);

    /* Close the file */
    fclose(fp);

    /* Return the data structure */
    return data;
}

/* Function to print intrusion detection data */
void print_intrusion_detection_data(struct intrusion_detection_data *data) {
    printf("Source IP: %s\n", data->source_ip);
    printf("Destination IP: %s\n", data->destination_ip);
    printf("Port: %s\n", data->port);
    printf("Protocol: %s\n", data->protocol);
    printf("Timestamp: %s\n", data->timestamp);
    printf("Signature: %s\n", data->signature);
}

/* Function to free intrusion detection data */
void free_intrusion_detection_data(struct intrusion_detection_data *data) {
    free(data->source_ip);
    free(data->destination_ip);
    free(data->port);
    free(data->protocol);
    free(data->timestamp);
    free(data->signature);
    free(data);
}

/* Main function */
int main() {
    /* Parse intrusion detection data from a file */
    struct intrusion_detection_data *data = parse_intrusion_detection_data("intrusion_detection_data.csv");
    if (data == NULL) {
        return EXIT_FAILURE;
    }

    /* Print intrusion detection data */
    print_intrusion_detection_data(data);

    /* Free intrusion detection data */
    free_intrusion_detection_data(data);

    return EXIT_SUCCESS;
}