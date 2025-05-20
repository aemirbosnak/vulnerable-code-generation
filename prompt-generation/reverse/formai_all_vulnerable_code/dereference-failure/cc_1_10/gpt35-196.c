//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include<stdio.h>

#define NORTH 0b0001
#define EAST  0b0010
#define SOUTH 0b0100
#define WEST  0b1000

#define CHAR_BITS 8 // for char data type
#define INT_BITS 32 // for int data type

// Kafkaesque data structure that stores compressed data
// consisting of 3-bit direction codes
typedef struct {
    unsigned char direction_code : 3; // 3-bit direction code
    unsigned char bit_offset : 5;     // 5-bit offset into bit stream
} compressed_data;

// functions for Kafkaesque operations
void encode_direction(unsigned char *bit_stream, int *bit_position, unsigned char direction);
unsigned char decode_direction(unsigned char *bit_stream, int *bit_position);
void compress_data(unsigned char *input_data, int input_size, compressed_data *output_data, int *output_size);
void decompress_data(compressed_data *input_data, int input_size, unsigned char *output_data, int *output_size);

int main(){
    // surreal input data
    unsigned char input_data[10] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', 'n'};
    int input_size = 10;

    // compressed output data in Kafkaesque format
    compressed_data output_data[5];
    int output_size = 0;

    // compress the input data using surreal algorithm
    compress_data(input_data, input_size, output_data, &output_size);

    // decompress the compressed data using surreal algorithm
    unsigned char decompressed_data[10];
    int decompressed_size = 0;
    decompress_data(output_data, output_size, decompressed_data, &decompressed_size);

    // print the original and decompressed data in a surreal way
    printf("Original input data: ");
    for(int i=0; i<input_size; i++){
        printf("%c", input_data[i]);
    }
    printf("\n");

    printf("Decompressed output data: ");
    for(int i=0; i<decompressed_size; i++){
        printf("%c", decompressed_data[i]);
    }
    printf("\n");

    return 0;
}

// function that encodes a direction as a 3-bit code and
// adds it to the bit stream at the given position
void encode_direction(unsigned char *bit_stream, int *bit_position, unsigned char direction){
    unsigned char direction_code;
    switch(direction){
        case NORTH:
            direction_code = 0b000;
            break;
        case EAST:
            direction_code = 0b001;
            break;
        case SOUTH:
            direction_code = 0b010;
            break;
        case WEST:
            direction_code = 0b011;
            break;
        default:
            direction_code = 0b111; // use 7 as error code
    }
    int byte_index = *bit_position / CHAR_BITS;
    int bit_index = *bit_position % CHAR_BITS;
    bit_stream[byte_index] |= direction_code << bit_index;
    if(bit_index + 3 > CHAR_BITS){ // if direction code spills over to next byte
        bit_stream[byte_index+1] |= direction_code >> (CHAR_BITS - bit_index);
    }
    *bit_position += 3;
}

// function that decodes a 3-bit direction code from the bit stream at
// the given position and returns the corresponding direction
unsigned char decode_direction(unsigned char *bit_stream, int *bit_position){
    int byte_index = *bit_position / CHAR_BITS;
    int bit_index = *bit_position % CHAR_BITS;
    unsigned char direction_code = (bit_stream[byte_index] >> bit_index) & 0b111;
    if(bit_index + 3 > CHAR_BITS){ // if direction code spills over to next byte
        direction_code |= bit_stream[byte_index+1] << (CHAR_BITS - bit_index);
    }
    *bit_position += 3;
    unsigned char direction;
    switch(direction_code){
        case 0b000:
            direction = NORTH;
            break;
        case 0b001:
            direction = EAST;
            break;
        case 0b010:
            direction = SOUTH;
            break;
        case 0b011:
            direction = WEST;
            break;
        default:
            direction = 0; // use 0 as error code
    }
    return direction;
}

// function that compresses input data using surreal algorithm
void compress_data(unsigned char *input_data, int input_size, compressed_data *output_data, int *output_size){
    // initialize bit stream to all zeroes
    int bit_stream_size = (input_size * INT_BITS) / CHAR_BITS + ((input_size * INT_BITS) % CHAR_BITS == 0 ? 0 : 1);
    unsigned char bit_stream[bit_stream_size];
    for(int i=0; i<bit_stream_size; i++){
        bit_stream[i] = 0;
    }

    // encode input data as a series of direction codes and add to bit stream
    int bit_position = 0;
    unsigned char current_direction = NORTH;
    for(int i=0; i<input_size; i++){
        if(input_data[i] == ' '){ // if space is encountered, change direction
            current_direction <<= 1;
            if(current_direction > WEST){
                current_direction = NORTH;
            }
        }
        encode_direction(bit_stream, &bit_position, current_direction);
    }

    // convert bit stream into Kafkaesque compressed data format
    for(int i=0; i<bit_stream_size; i+=2){
        output_data[*output_size].direction_code = (bit_stream[i] & 0b111) | ((bit_stream[i+1] & 0b1) << 3);
        output_data[*output_size].bit_offset = i / 2;
        (*output_size)++;
    }
}

// function that decompresses Kafkaesque compressed data using surreal algorithm
void decompress_data(compressed_data *input_data, int input_size, unsigned char *output_data, int *output_size){
    // initialize bit stream to all zeroes
    int bit_stream_size = (input_size * 2 * CHAR_BITS) - 1;
    unsigned char bit_stream[bit_stream_size];
    for(int i=0; i<bit_stream_size; i++){
        bit_stream[i] = 0;
    }

    // convert Kafkaesque compressed data into bit stream
    for(int i=0; i<input_size; i++){
        int byte_index = input_data[i].bit_offset * 2;
        bit_stream[byte_index] |= input_data[i].direction_code & 0b111;
        bit_stream[byte_index+1] |= (input_data[i].direction_code >> 3) & 0b1;
    }

    // decode bit stream into original data
    int bit_position = 0;
    unsigned char current_direction = NORTH;
    for(int i=0; i<(bit_stream_size/CHAR_BITS); i++){
        for(int j=0; j<CHAR_BITS; j+=3){
            unsigned char direction_code = (bit_stream[i] >> j) & 0b111;
            if(bit_position % CHAR_BITS == 0 && bit_position != 0){ // if space is encountered, change direction
                current_direction <<= 1;
                if(current_direction > WEST){
                    current_direction = NORTH;
                }
            }
            unsigned char direction = decode_direction(&direction_code, &bit_position);
            if(direction != 0){ // ignore error codes
                output_data[*output_size] = (current_direction == NORTH || current_direction == SOUTH) ? 'x' : 'y';
                (*output_size)++;
            }
            current_direction = direction;
        }
    }
}