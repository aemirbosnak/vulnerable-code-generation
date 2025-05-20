//FormAI DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

// function to encode the message into the image
void encode_message(char *image_file, char *message_file, char *output_file) {
	// open the image file in read binary mode
	FILE *img_fp = fopen(image_file, "rb");
	if(img_fp == NULL) {
		printf("Error: Couldn't open the image file.\n");
		exit(1);
	}

	// open the message file in read binary mode
	FILE *msg_fp = fopen(message_file, "rb");
	if(msg_fp == NULL) {
		printf("Error: Couldn't open the message file.\n");
		exit(1);
	}

	// open the output file in write binary mode
	FILE *out_fp = fopen(output_file, "wb");
	if(out_fp == NULL) {
		printf("Error: Couldn't create the output file.\n");
		exit(1);
	}

	// read the image file into a buffer
	unsigned char *img_buffer;
	img_buffer = (unsigned char*) malloc(MAX_FILE_SIZE * sizeof(unsigned char));
	int img_size = fread(img_buffer, 1, MAX_FILE_SIZE, img_fp);

	// read the message file into a buffer
	unsigned char *msg_buffer;
	msg_buffer = (unsigned char*) malloc(MAX_FILE_SIZE * sizeof(unsigned char));
	int msg_size = fread(msg_buffer, 1, MAX_FILE_SIZE, msg_fp);

	// check if the size of the message to be encoded is smaller than the size of the image
	if(msg_size + 54 > img_size) {
		printf("Error: The image is not big enough to hold the message.\n");
		exit(1);
	}

	// add the length of the message to the beginning of the message buffer
	unsigned char message_length[4];
	message_length[0] = (msg_size >> 24) & 0xFF;
	message_length[1] = (msg_size >> 16) & 0xFF;
	message_length[2] = (msg_size >> 8) & 0xFF;
	message_length[3] = msg_size & 0xFF;

	unsigned char *full_msg_buffer;
	full_msg_buffer = (unsigned char*) malloc((msg_size+4) * sizeof(unsigned char));
	memcpy(full_msg_buffer, &message_length, 4);
	memcpy(full_msg_buffer+4, msg_buffer, msg_size);

	// write the header of the image to the output file
	fwrite(img_buffer, 1, 54, out_fp);

	// encode the message into the image
	int i, j, k;
	for(i=0; i<msg_size+4; i++) {
		for(j=0; j<8; j++) {
			unsigned char bit = (full_msg_buffer[i] >> j) & 0x01;
			int index = ((i+54)*8)+(7-j);

			img_buffer[index] = (img_buffer[index] & 0xFE) | bit;
		}
	}

	// write the encoded image to the output file
	fwrite(img_buffer, 1, img_size, out_fp);

	// close the files and free the buffers
	fclose(img_fp);
	fclose(msg_fp);
	fclose(out_fp);

	free(img_buffer);
	free(msg_buffer);
	free(full_msg_buffer);

	printf("Message encoded successfully.\n");
}

// function to decode the message from the image
void decode_message(char *image_file, char *output_file) {
	// open the image file in read binary mode
	FILE *img_fp = fopen(image_file, "rb");
	if(img_fp == NULL) {
		printf("Error: Couldn't open the image file.\n");
		exit(1);
	}

	// open the output file in write binary mode
	FILE *out_fp = fopen(output_file, "wb");
	if(out_fp == NULL) {
		printf("Error: Couldn't create the output file.\n");
		exit(1);
	}

	// read the image file into a buffer
	unsigned char *img_buffer;
	img_buffer = (unsigned char*) malloc(MAX_FILE_SIZE * sizeof(unsigned char));
	int img_size = fread(img_buffer, 1, MAX_FILE_SIZE, img_fp);

	// read the message length from the header of the image
	unsigned char message_length[4];
	memcpy(&message_length, img_buffer+2, 4);
	int msg_size = (message_length[0] << 24) | (message_length[1] << 16) | (message_length[2] << 8) | message_length[3];

	// decode the message from the image
	unsigned char *msg_buffer;
	msg_buffer = (unsigned char*) malloc((msg_size+1) * sizeof(unsigned char));

	int i, j, k=0;
	for(i=0; i<msg_size; i++) {
		unsigned char byte = 0x00;
		for(j=0; j<8; j++) {
			int index = ((i+54)*8)+(7-j);
			byte |= ((img_buffer[index] & 0x01) << j);
		}
		msg_buffer[k++] = byte;
	}

	msg_buffer[k] = '\0';

	// write the decoded message to the output file
	fwrite(msg_buffer, 1, msg_size, out_fp);

	// close the files and free the buffers
	fclose(img_fp);
	fclose(out_fp);

	free(img_buffer);
	free(msg_buffer);

	printf("Message decoded successfully.\n");
}

int main() {
	char image_file[] = "image.bmp";
	char message_file[] = "message.txt";
	char encoded_file[] = "output.bmp";
	char decoded_file[] = "output.txt";

	encode_message(image_file, message_file, encoded_file);
	decode_message(encoded_file, decoded_file);

	return 0;
}