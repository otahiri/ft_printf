#include "ft_printf.h"
#include <stdio.h>

int main(void) {
    void *ptr = (void*)0x7FFFFFFFFFFFFFFF;
    ft_printf("%p\n", ptr);  // prints 0x7fffffffffffffff return 0; }
