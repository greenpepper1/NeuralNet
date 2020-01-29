
#include "layer.h"

typedef struct net_t
{
    layer_t **p_layer; //TODO rename these pp_layer
    uint8_t number_of_layers;
} net_t;

/* This function will need to :
    # Create layers
    # Map inputs
 */
net_t *create_net(tensor_t *inputs, uint8_t *number_of_neurons, uint8_t number_of_layers);
