#include "ft_printf.h"

int	main()
{
    int test;
    int test2;
    test = printf(" %u \n", -1);
	test2 = ft_printf(" %u \n", -1);
    printf("printf returned: %d\n", test);
    printf("ft_printf returned: %d\n", test2);
	return (0);
}