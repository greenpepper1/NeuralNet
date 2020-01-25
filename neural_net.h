
#include "layer.h"

typedef struct net
{
    layer_t *p_layer;
    int number_of_layers;
} net;

/* This function will need to :
    # Create layers
    # Map inputs
 */
net *create_net(tensor_t inputs, tensor_t outputs, int number_of_neurons, int number_of_layers);
