// Unit tests

#include <stdlib.h> 
#include <stdbool.h>
#include "neuron.h"
#include "dbg.h"

bool check_neuron();
bool check_sum();
bool check_weights();

int main()
{
    debug("main");
    check_neuron();
    check_sum();
    check_weights();
}

bool check_neuron()
{
    debug("check_neuron ...");
    uint8_t data[4] = {2, 3, 2, 0};
    uint8_t result = 0;
    tensor_t input;
    input.amount = 4;
    input.tensor = data;

    neuron_t *cell = create_neuron(&input);
    check(cell->p_input == &input, "wrong input address")
    check(cell->p_input->amount == input.amount, "wrong input amount")
    check(cell->p_input->tensor == input.tensor, "wrong input tensor address")
    run_neuron(&cell);
    debug("output %d", cell->output);
    check(cell->output == 14, "wrong output");
    debug("check_neuron complete");
}

bool check_weights()
{
    debug("check_weights ...");
    uint8_t data[4] = {30, 8, 12, 0};
    uint8_t result = 0;
    tensor_t input;
    input.amount = 4;
    input.tensor = data;

    neuron_t *cell = create_neuron(&input);

    run_neuron(&cell);

    for(int i=0; i<4; i++)
    {
        result += data[i] * 2;
    }

    check(cell->output == cell->sum, "output(%d) == sum(%d)", cell->output, cell->sum);
    check(cell->output == result, "output(%d) == result(%d)", cell->output, result);
    debug("check_weights complete");
    return true;

}

bool check_sum()
{
    debug("check_sum ...");
    uint8_t data[4] = {6, 5, 3, 2};
    uint8_t data_two[4] = {8, 2, 1, 4};
    uint8_t result = 0;

    tensor_t input;
    input.amount = 4;
    input.tensor = data;

    neuron_t *cell = create_neuron(&input);

    cell->weights.tensor = data_two;

    run_neuron(&cell);

    for(int i=0; i<4; i++)
    {
        result += data[i] * data_two[i];
    }

    check(cell->sum == result, "sum(%d) == result(%d)", cell->sum, result);
    return true;
}