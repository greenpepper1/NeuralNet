// Unit tests

#include <stdlib.h> 
#include <stdbool.h>
#include "neural_net.h"
#include "dbg.h"

bool check_neural_net();

int main()
{
    debug("main");
    check_neural_net();
}

bool check_neural_net()
{
    debug("check_neural_net ...");
    uint8_t data[4] = {2, 3, 2, 0};
    uint8_t result = 0;
    tensor_t input;
    uint8_t output;
    input.amount = 4;
    input.tensor = data;
    uint8_t number_of_neurons = 2;
    debug("Setup complete");

    net_t *net = create_net(&input, &number_of_neurons, 1);

    debug("check_neural_net complete");
}