//FormAI DATASET v1.0 Category: Audio processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/select.h>

// Constants
#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define CHANNELS 2

// Structs
typedef struct WaveHeader {
    char chunkID[4];
    int chunkSize;
    char format[4];
    char subchunk1ID[4];
    int subchunk1Size;
    short audioFormat;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char subchunk2ID[4];
    int subchunk2Size;
} WaveHeader;

// Global variables
sem_t sem_audio_data;
int audio_data_ready = 0;
int client_socket;
pthread_t audio_thread;

// Function declarations
void *audio_processing_thread(void *arg);
void signal_handler(int sig);
void cleanup();
void print_wav_header(WaveHeader header);
WaveHeader read_wav_header(int fd);
void *error_check(void *arg);

int main(int argc, char *argv[]) {
    int server_socket, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Setup signal handler for cleaning up audio resources
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    signal(SIGPIPE, signal_handler);

    // Create server socket
    port = atoi(argv[1]);
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to specified port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 1) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Wait for client connection
    printf("Waiting for client connection...\n");
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

    // Start audio processing thread
    if (pthread_create(&audio_thread, NULL, audio_processing_thread, NULL) == -1) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Wait for audio processing thread to start up
    sem_wait(&sem_audio_data);

    // Main loop
    while (1) {
        // Read input from client
        char input[BUFFER_SIZE];
        int bytes_read = read(client_socket, input, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("read");
            continue;
        }
        if (bytes_read == 0) {
            printf("Disconnected from client\n");
            break;
        }

        // Send input to audio processing thread
        int bytes_written = write(client_socket, input, bytes_read);
        if (bytes_written == -1) {
            perror("write");
            continue;
        }
    }

    // Cleanup resources
    cleanup();
    exit(EXIT_SUCCESS);
}

void *audio_processing_thread(void *arg) {
    // Attach error checking thread
    pthread_t error_thread;
    if (pthread_create(&error_thread, NULL, error_check, NULL) == -1) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Initialize audio resources
    int fd;
    WaveHeader header;
    short *audio_data;
    float *left_channel, *right_channel;
    int num_samples;
    fd = open("sample.wav", O_RDONLY);
    header = read_wav_header(fd);
    print_wav_header(header);
    audio_data = mmap(NULL, header.subchunk2Size, PROT_READ, MAP_PRIVATE, fd, 44);
    num_samples = header.subchunk2Size / 2 / header.numChannels;
    left_channel = (float *)malloc(num_samples * sizeof(float));
    right_channel = (float *)malloc(num_samples * sizeof(float));
    close(fd);

    // Set semaphore to indicate audio data is ready
    sem_post(&sem_audio_data);

    // Start audio playback loop
    while (1) {
        // Wait for audio data to be ready
        while (!audio_data_ready) {
            usleep(1000);
        }
        audio_data_ready = 0;

        // Process audio data
        int i, j;
        for (i = 0, j = 0; i < num_samples * header.numChannels; i += header.numChannels, j++) {
            if (header.numChannels == 1) {
                left_channel[j] = audio_data[i] / 32767.0;
            } else if (header.numChannels == 2) {
                left_channel[j] = audio_data[i] / 32767.0;
                right_channel[j] = audio_data[i + 1] / 32767.0;
            }
        }

        // Wait for input from client
        char input[BUFFER_SIZE];
        int bytes_read = read(client_socket, input, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("read");
            continue;
        }
        if (bytes_read == 0) {
            printf("Disconnected from client\n");
            break;
        }

        // Apply processing to audio data according to input from client
        // ...

        // Send processed audio to client
        int bytes_written = write(client_socket, audio_data, num_samples * header.numChannels * sizeof(short));
        if (bytes_written == -1) {
            perror("write");
            continue;
        }
    }

    // Cleanup resources
    cleanup();
    pthread_exit(NULL);
}

void signal_handler(int sig) {
    // Cleanup resources
    cleanup();
    exit(EXIT_SUCCESS);
}

void cleanup() {
    close(client_socket);
}

void print_wav_header(WaveHeader header) {
    printf("ChunkID: %.4s\n", header.chunkID);
    printf("ChunkSize: %d\n", header.chunkSize);
    printf("Format: %.4s\n", header.format);
    printf("Subchunk1ID: %.4s\n", header.subchunk1ID);
    printf("Subchunk1Size: %d\n", header.subchunk1Size);
    printf("AudioFormat: %d\n", header.audioFormat);
    printf("NumChannels: %d\n", header.numChannels);
    printf("SampleRate: %d\n", header.sampleRate);
    printf("ByteRate: %d\n", header.byteRate);
    printf("BlockAlign: %d\n", header.blockAlign);
    printf("BitsPerSample: %d\n", header.bitsPerSample);
    printf("Subchunk2ID: %.4s\n", header.subchunk2ID);
    printf("Subchunk2Size: %d\n", header.subchunk2Size);
}

WaveHeader read_wav_header(int fd) {
    WaveHeader header;
    read(fd, &(header.chunkID), 4);
    read(fd, &(header.chunkSize), 4);
    read(fd, &(header.format), 4);
    read(fd, &(header.subchunk1ID), 4);
    read(fd, &(header.subchunk1Size), 4);
    read(fd, &(header.audioFormat), 2);
    read(fd, &(header.numChannels), 2);
    read(fd, &(header.sampleRate), 4);
    read(fd, &(header.byteRate), 4);
    read(fd, &(header.blockAlign), 2);
    read(fd, &(header.bitsPerSample), 2);
    read(fd, &(header.subchunk2ID), 4);
    read(fd, &(header.subchunk2Size), 4);
    return header;
}

void *error_check(void *arg) {
    while (1) {
        if (!audio_data_ready) {
            fprintf(stderr, "Error: Audio data not yet processed!\n");
        }
        sleep(1);
    }
}