#include <stdlib.h> 
#include "layer.h"
#include "dbg.h"

layer_t *create_layer(tensor_t *inputs, int number_of_neurons)
{
    layer_t *layer = malloc(sizeof(layer_t));
    layer->p_neuron = malloc(sizeof(neuron_t)*number_of_neurons);

    layer->number_of_neurons = number_of_neurons;
    neuron_t **tmp = layer->p_neuron;

    for(int i=0; i<number_of_neurons; i++)
    {
        *tmp = create_neuron(&inputs);
        tmp++;
    }
    return layer;
}