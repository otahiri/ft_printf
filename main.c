#include "ft_printf.h"
#include <stdio.h>

int main(void) {
    void *ptr = (void*)0x7FFFFFFFFFFFFFFF;
    ft_printf("%w\n", 4294967295);
}
