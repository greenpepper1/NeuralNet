#ifndef __layer_h__
#define __layer_h__

#include "neuron.h"

typedef struct layer_t
{
    neuron_t **p_neuron;
    uint8_t number_of_neurons;
    uint8_t *output; 
} layer_t;

/* This function will need to :
    # Create neurons
    # Map inputs
 */
layer_t *create_layer(tensor_t *inputs, uint8_t number_of_neurons);


#endif
