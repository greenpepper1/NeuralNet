#include "neuron.h"

typedef struct layer_t
{
    neuron_t *p_neuron;
    int number_of_neuron;
} layer_t;

/* This function will need to :
    # Create neurons
    # Map inputs
 */
layer_t *create_layer(tensor_t *inputs, tensor_t *outputs, int number_of_neurons);
