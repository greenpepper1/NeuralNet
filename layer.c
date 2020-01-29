#include <stdlib.h> 
#include "layer.h"
#include "dbg.h"

// TODO you can move the output back into neuron and have a list of 
// pointers to pointers with the outputs.

layer_t *create_layer(tensor_t *inputs, uint8_t number_of_neurons)
{
    layer_t *layer = malloc(sizeof(layer_t));
    layer->p_neuron = malloc(sizeof(neuron_t)*number_of_neurons); // We have this and a malloc p_neron?
    layer->output = malloc(sizeof(uint8_t)*number_of_neurons);

    layer->number_of_neurons = number_of_neurons;
    neuron_t **tmp_neuron = layer->p_neuron;
    uint8_t *tmp_output = layer->output;

    for(int i=0; i<number_of_neurons; i++)
    {
        *tmp_neuron = create_neuron(&inputs, tmp_output);
        tmp_neuron++;
        tmp_output++; // Give the next neuron the next output
    }
    return layer;
}
