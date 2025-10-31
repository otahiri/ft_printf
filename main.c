#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "mine";
	ft_printf("hello %p %cworld", str, *str);
}
