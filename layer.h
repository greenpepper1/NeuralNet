

typedef int *tensor_t;

typedef struct layer
{
    neuron *p_neuron;
    int number_of_neuron;
} layer;

/* This function will need to :
    # Create neurons
    # Map inputs
 */
layer *create_layer(tensor_t inputs, tensor_t outputs, int input_size, int output_size, int number_of_neurons);
