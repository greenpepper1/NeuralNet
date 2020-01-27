#ifndef __neuron_h__
#define __neuron_h__

#include <stdint.h>
#include <stdbool.h>
#include "tensor.h"

typedef struct neuron_t
{
    tensor_t *p_input;
    tensor_t weights;
    uint8_t sum;
    void * activation_function;
    uint8_t output;
} neuron_t;

/* This function will need to :
    # Map inputs
    # Alloc the weights
    # Assign weights some value
    # Asign the activation function
    # Alloc the outputs
    # Maybe add to task/ or the net could do this    
 */
neuron_t *create_neuron(tensor_t **input);

/* This function will need to :
    # Multiply the inputs by the weights
    # Store the above value in sum
    # Use the activation function on sum
    # store that value in output 
 */
neuron_t run_neuron(neuron_t *p_neuron);

/* This function will need to :
    # Change the value of the weight given
 */
bool edit_weight(neuron_t *p_neuron, uint8_t weight, uint8_t value);

#endif