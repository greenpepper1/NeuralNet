#include <stdlib.h> 
#include "neural_net.h"
#include "layer.h"
#include "dbg.h"

net_t *create_net(tensor_t *inputs, uint8_t* number_of_neurons, uint8_t number_of_layers)
{
    net_t *net = malloc(sizeof(net_t));
    net->p_layer = malloc(sizeof(layer_t)*number_of_layers); // This and layer in layer.c?
    net->number_of_layers = number_of_layers;
    layer_t **tmp = net->p_layer;
    layer_t **tmp_prev = net->p_layer;

    /* TODO make this better*/
    *tmp = create_layer(inputs, *number_of_neurons);
    tmp++;
    number_of_neurons++;

    for(int i=1; i<number_of_layers; i++)
    {
        tensor_t output_tesnsor;
        output_tesnsor.tensor = (*tmp_prev)->output;
        output_tesnsor.amount = (*tmp_prev)->number_of_neurons;
        *tmp = create_layer(&output_tesnsor, *number_of_neurons);
        tmp++;
        tmp_prev++;
        number_of_neurons++;
    }
    
    return net;
}