#include "tensor.h"

tensor_t *create_tensor(uint8_t size)
{
    tensor_t *input;
    input->tensor = malloc(sizeof(uint8_t));
    return input;
}

void destroy_tensor(tensor_t *input)
{
    free(input->tensor);
}