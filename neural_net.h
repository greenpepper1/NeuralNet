

typedef int *tensor_t;

typedef struct net
{
    layer *p_layer;
    int number_of_layers;
} net;

/* This function will need to :
    # Create layers
    # Map inputs
 */
net *create_net(tensor_t inputs, tensor_t outputs, int input_size, int output_size, int number_of_neurons, int number_of_layers);
