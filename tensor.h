#include <stdint.h>

typedef struct tensor_t
{
    uint8_t *tensor;
    uint8_t amount;
} tensor_t;

tensor_t *create_tensor(uint8_t size);
void destroy_tensor(tensor_t *input);