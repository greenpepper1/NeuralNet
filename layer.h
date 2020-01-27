#ifndef __layer_h__
#define __layer_h__

#include "neuron.h"

typedef struct layer_t
{
    neuron_t **p_neuron;
    uint8_t number_of_neurons;
    // tensor_t output; // Not sure about this
                     // It makes it easier to set up the next layer
                     // and I guess you dont have to map through all
                     // the neurons but it is a copying. 
} layer_t;

/* This function will need to :
    # Create neurons
    # Map inputs
 */
layer_t *create_layer(tensor_t *inputs, int number_of_neurons);

#endif
