
#include <stdlib.h> 
#include "neuron.h"
#include "dbg.h"

#define DEFAULT_WEIGHT 2

/* Private functions */
static void create_weights();

/* This function will need to :
    # Create neuron
    # malloc the weights
    # Map inputs
    # Assign weights some value
    # Asign the activation function
    # Maybe add to task/ or the net could do this    
 */
neuron_t *create_neuron(tensor_t **input)
{
    neuron_t *p_neuron = malloc(sizeof(neuron_t));
    debug("create_neuron() input(%p)", *input);
    
    // Setup the input
    p_neuron->p_input = *input;

    // Configure the weights
    p_neuron->weights.amount = (*input)->amount;
    create_weights(&p_neuron->weights);
    return p_neuron;
}

/* This function will need to :
    # Multiply the inputs by the weights
    # Store the above value in sum
    # Use the activation function on sum
    # store that value in output 
 */
neuron_t run_neuron(neuron_t *p_neuron)
{
    p_neuron->sum = 0;

    uint8_t *tmp_input = p_neuron->p_input->tensor;
    uint8_t *tmp_weight = p_neuron->weights.tensor;
    
    for(int i=0; i<p_neuron->p_input->amount; i++)
    {
        // Multiply the weights and input.
        p_neuron->sum += *tmp_input * *tmp_weight;
        tmp_input++;
        tmp_weight++;
    }

    // Move sum to the output as there is no activation right now.
    // TODO add activation
    p_neuron->output = p_neuron->sum;
}

/* Change the weight to an input value*/
bool edit_weight(neuron_t *p_neuron, uint8_t weight, uint8_t value)
{
    if(weight > p_neuron->weights.amount)
    {
        log_err("Setting a weight value that doesnt exist.");
        return false;
    }
    check(weight < p_neuron->weights.amount, "Setting a weight that doesnt exist")
    
    uint8_t *tmp_weight = p_neuron->weights.tensor;
    tmp_weight += weight;
    *tmp_weight = value; 
    return true;
}

/* Sets weights to 2 for now */
void create_weights(tensor_t *weights)
{
    weights->tensor = malloc(sizeof(uint8_t)*weights->amount);

    uint8_t *tmp_weight = weights->tensor; 
    for(int i=0; i<weights->amount; i++)
    {
        *tmp_weight = DEFAULT_WEIGHT;
        tmp_weight++;
    }
}