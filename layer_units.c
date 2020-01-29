// Unit tests

#include <stdlib.h> 
#include <stdbool.h>
#include "layer.h"
#include "dbg.h"

bool check_layer();

int main()
{
    debug("main");
    check_layer();
}

bool check_layer()
{
    debug("check_layer ...");
    uint8_t data[4] = {2, 3, 2, 0};
    uint8_t result = 0;
    tensor_t input;
    input.amount = 4;
    input.tensor = data;
    uint8_t number_of_neurons = 2;
    debug("Setup complete");


    layer_t *layer = create_layer(&input, number_of_neurons);
    neuron_t **neurons = layer->p_neuron;
    run_neuron(*neurons);
    debug("output %d ", *layer->output);
    check(*layer->output == 14, "output is wrong")

    debug("neurons(%p) ", (*neurons));
    neurons++;
    debug("neurons(%p) ", (*neurons));

    run_neuron(*neurons);
    layer->output++; // look at next output
    debug("output %d ", *layer->output);

    check(layer->number_of_neurons == number_of_neurons, "Number of neurons is wrong")
    check(*layer->output == 14, "output is wrong")

    debug("check_layer complete");
}