// Unit tests

#include <stdlib.h> 
#include <stdbool.h>
#include "neuron.h"
#include "dbg.h"

bool check_neuron();
bool check_neuron_overtime();
bool check_weight();

int main()
{
    debug("main");
    check_neuron();
    check_neuron_overtime();
    check_weight();
}

bool check_weight()
{
    debug("check_neuron_overtime ...");
    uint8_t data[4] = {2, 5, 2, 1};
    uint8_t result = 0;
    tensor_t *input;
    uint8_t output;
    input->amount = 4;
    input->tensor = data;

    neuron_t *cell = create_neuron(&input, &output);
    check(cell->p_input == input, "wrong input address");
    check(cell->p_input->amount == input->amount, "wrong input amount");
    check(cell->p_input->tensor == input->tensor, "wrong input tensor address");

    run_neuron(cell);
    debug("inputs %d, %d, %d, %d", cell->p_input->tensor[0], cell->p_input->tensor[1], cell->p_input->tensor[2], cell->p_input->tensor[3]);
    debug("output %d",output);
    check(output == 20, "wrong output");

    edit_weight(cell, 2, 5);
    run_neuron(cell);
    debug("weights %d, %d, %d, %d", cell->weights.tensor[0], cell->weights.tensor[1], cell->weights.tensor[2], cell->weights.tensor[3]);
    debug("output %d",output);
    check(output == 26, "wrong output");
    debug("");
}

bool check_neuron_overtime()
{
    debug("check_neuron_overtime ...");
    uint8_t data[4] = {2, 5, 2, 1};
    uint8_t result = 0;
    tensor_t *input;
    uint8_t output;
    input->amount = 4;
    input->tensor = data;

    neuron_t *cell = create_neuron(&input, &output);
    check(cell->p_input == input, "wrong input address");
    check(cell->p_input->amount == input->amount, "wrong input amount");
    check(cell->p_input->tensor == input->tensor, "wrong input tensor address");

    run_neuron(cell);
    debug("inputs %d, %d, %d, %d", cell->p_input->tensor[0], cell->p_input->tensor[1], cell->p_input->tensor[2], cell->p_input->tensor[3]);
    debug("output %d",output);
    check(output == 20, "wrong output");

    // Change data
    data[3] = 2;
    run_neuron(cell);
    check(cell->p_input == input, "wrong input address");
    debug("inputs %d, %d, %d, %d", cell->p_input->tensor[0], cell->p_input->tensor[1], cell->p_input->tensor[2], cell->p_input->tensor[3]);
    check(cell->p_input->amount == input->amount, "wrong input amount");
    check(cell->p_input->tensor == input->tensor, "wrong input tensor address");
    debug("output %d",output);
    check(output == 22, "wrong output");
    debug("check_neuron_overtime complete");
    debug("");
}

bool check_neuron()
{
    debug("check_neuron ...");
    uint8_t data[4] = {2, 3, 2, 0};
    uint8_t result = 0;
    tensor_t *input;
    uint8_t output;
    input->amount = 4;
    input->tensor = data;

    neuron_t *cell = create_neuron(&input, &output);
    check(cell->p_input == input, "wrong input address")
    check(cell->p_input->amount == input->amount, "wrong input amount")
    check(cell->p_input->tensor == input->tensor, "wrong input tensor address")
    run_neuron(cell);
    check(output == 14, "wrong output");
    debug("check_neuron complete");
    debug("");

}
