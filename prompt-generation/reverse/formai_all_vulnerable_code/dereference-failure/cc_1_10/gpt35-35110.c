//FormAI DATASET v1.0 Category: Image Classification system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_SIZE 784		// 28x28 Input Image
#define HIDDEN_SIZE 256		// Number of Hidden Layer Neurons
#define OUTPUT_SIZE 10		// Number of Output Layer Neurons

// Structure for Neural Network Layers
typedef struct {
	float *neurons;
	float *bias;
	float **weights;
} Layer;

// Function to Initiate Neural Network Layers
void create_layer(Layer *layer, int input_size, int size) {
	layer->neurons = (float*) malloc(size*sizeof(float));
	layer->bias = (float*) malloc(size*sizeof(float));
	layer->weights = (float**) malloc(size*sizeof(float*));
	for (int i=0;i<size;i++) {
		layer->neurons[i] = 0;
		layer->bias[i] = ((float)rand()/(float)(RAND_MAX)) - 0.5;		// Random Bias Initialization
		layer->weights[i] = (float*) malloc(input_size*sizeof(float));
		for (int j=0;j<input_size;j++) {
			layer->weights[i][j] = ((float)rand()/(float)(RAND_MAX)) - 0.5;	// Random Weights Initialization
		}
  	}
}

// Function to Delete Neural Network Layers
void delete_layer(Layer *layer, int size) {
	free(layer->neurons);
	free(layer->bias);
	for (int i=0;i<size;i++) {
		free(layer->weights[i]);
  	}
	free(layer->weights);
}

// Function to Calculate Sigmoid Function
float sigmoid(float x) {
	return 1/(1 + expf(-x));
}

// Function to Calculate Sigmoid Derivative
float sigmoid_derivative(float x) {
	return x*(1-x);
}

// Function to Feed Forward through Neural Network
void feed_forward(Layer *input_layer, Layer *hidden_layer, Layer *output_layer, float *input) {
	for (int i=0;i<INPUT_SIZE;i++) {
		input_layer->neurons[i] = input[i];
	}
	for (int i=0;i<HIDDEN_SIZE;i++) {
		float sum = 0;
		for (int j=0;j<INPUT_SIZE;j++) {
			float x = input_layer->neurons[j];
			float w = hidden_layer->weights[i][j];
			sum += w*x;
		}
		hidden_layer->neurons[i] = sigmoid(sum + hidden_layer->bias[i]);
	}
	for (int i=0;i<OUTPUT_SIZE;i++) {
		float sum = 0;
		for (int j=0;j<HIDDEN_SIZE;j++) {
			float x = hidden_layer->neurons[j];
			float w = output_layer->weights[i][j];
			sum += w*x;
		}
		output_layer->neurons[i] = sigmoid(sum + output_layer->bias[i]);
	}
}

// Function to Back Propagate Error through Neural Network
void back_propagation(Layer *input_layer, Layer *hidden_layer, Layer *output_layer, float *expected_output, float learning_rate) {
	// Calculate Error for Output Layer
	float output_error[OUTPUT_SIZE];
	for (int i=0;i<OUTPUT_SIZE;i++) {
		float output = output_layer->neurons[i];
		float error = expected_output[i] - output;
		output_error[i] = error*sigmoid_derivative(output);
	}
	// Calculate Error for Hidden Layer
	float hidden_error[HIDDEN_SIZE];
	for (int i=0;i<HIDDEN_SIZE;i++) {
		float error = 0;
		for (int j=0;j<OUTPUT_SIZE;j++) {
			float output_weight = output_layer->weights[j][i];
			float output_neuron_error = output_error[j];
			error += output_weight*output_neuron_error;
		}
		float hidden_output = hidden_layer->neurons[i];
		hidden_error[i] = error*sigmoid_derivative(hidden_output);
	}
	// Update Weights for Output Layer
	for (int i=0;i<OUTPUT_SIZE;i++) {
		for (int j=0;j<HIDDEN_SIZE;j++) {
			float output_neuron_error = output_error[i];
			float hidden_output = hidden_layer->neurons[j];
			float delta = learning_rate*output_neuron_error*hidden_output;
			output_layer->weights[i][j] += delta;
		}
		output_layer->bias[i] += learning_rate*output_error[i];
	}
	// Update Weights for Hidden Layer
	for (int i=0;i<HIDDEN_SIZE;i++) {
		for (int j=0;j<INPUT_SIZE;j++) {
			float hidden_neuron_error = hidden_error[i];
			float input_neuron = input_layer->neurons[j];
			float delta = learning_rate*hidden_neuron_error*input_neuron;
			hidden_layer->weights[i][j] += delta;
		}
		hidden_layer->bias[i] += learning_rate*hidden_error[i];
	}
}

// Function to Train Neural Network
void train_network(Layer *input_layer, Layer *hidden_layer, Layer *output_layer, float **inputs, float **expected_outputs, int epochs, int batch_size, float learning_rate) {
	for (int i=0;i<epochs;i++) {
		float error = 0;
		for (int j=0;j<batch_size;j++) {
			feed_forward(input_layer, hidden_layer, output_layer, inputs[j]);
			back_propagation(input_layer, hidden_layer, output_layer, expected_outputs[j], learning_rate);
			for (int k=0;k<OUTPUT_SIZE;k++) {
				error += abs(expected_outputs[j][k] - output_layer->neurons[k]);
			}
		}
		error /= (batch_size*OUTPUT_SIZE);
		printf("Epoch: %d ; Error: %f\n", i+1, error);
	}
}

// Function to Predict Output using Neural Network
int predict_output(Layer *input_layer, Layer *hidden_layer, Layer *output_layer, float *input) {
	feed_forward(input_layer, hidden_layer, output_layer, input);
	float max = 0;
	int max_index = 0;
	for (int i=0;i<OUTPUT_SIZE;i++) {
		float output = output_layer->neurons[i];
		if (output > max) {
			max = output;
			max_index = i;
		}
	}
	return max_index;
}

int main() {
	srand(time(NULL));
	
	// Create Layers for Neural Network
	Layer input_layer, hidden_layer, output_layer;
	create_layer(&input_layer, INPUT_SIZE, INPUT_SIZE);
	create_layer(&hidden_layer, INPUT_SIZE, HIDDEN_SIZE);
	create_layer(&output_layer, HIDDEN_SIZE, OUTPUT_SIZE);
	
	// Load Training Data
	float **inputs = (float**) malloc(60000*sizeof(float*));
	float **expected_outputs = (float**) malloc(60000*sizeof(float*));
	FILE *fp;
	fp = fopen("train-images.idx3-ubyte", "rb");
	unsigned char buffer[784];
	for (int i=0;i<60000;i++) {
		inputs[i] = (float*) malloc(INPUT_SIZE*sizeof(float));
		fread(buffer, sizeof(buffer), 1, fp);
		for (int j=0;j<INPUT_SIZE;j++) {
			inputs[i][j] = buffer[j]/255.0;
		}
	}
	fclose(fp);
	fp = fopen("train-labels.idx1-ubyte", "rb");
	for (int i=0;i<60000;i++) {
		expected_outputs[i] = (float*) malloc(OUTPUT_SIZE*sizeof(float));
		unsigned char label;
		fread(&label, sizeof(label), 1, fp);
		for (int j=0;j<OUTPUT_SIZE;j++) {
			if (j == label) {
				expected_outputs[i][j] = 1;
			} else {
				expected_outputs[i][j] = 0;
			}
		}
	}
	fclose(fp);
	
	// Train Neural Network
	train_network(&input_layer, &hidden_layer, &output_layer, inputs, expected_outputs, 5, 100, 0.2);
	
	// Load Test Data
	fp = fopen("t10k-images.idx3-ubyte", "rb");
	for (int i=0;i<10000;i++) {
		fread(buffer, sizeof(buffer), 1, fp);
		for (int j=0;j<INPUT_SIZE;j++) {
			inputs[0][j] = buffer[j]/255.0;
		}
		int output = predict_output(&input_layer, &hidden_layer, &output_layer, inputs[0]);
		printf("%d\n", output);
	}
	fclose(fp);

	// Delete Neural Network Layers
	delete_layer(&input_layer, INPUT_SIZE);
	delete_layer(&hidden_layer, HIDDEN_SIZE);
	delete_layer(&output_layer, OUTPUT_SIZE);
	
	return 0;
}