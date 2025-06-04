#include "ft_printf.h"

bool	write_a_char(va_list args, int *total_number_of_print_char)
{
	const int	arg = va_arg(args, int);

	if (ft_putchar_fd_return((char)arg, 1) == -1)
		return (false);
	(*total_number_of_print_char)++;
	return (true);
}

bool	write_string(va_list args, int *total_number_of_print_char)
{
	const char		*arg = va_arg(args, char *);
	size_t			arg_len;

	if (arg == NULL)
	{
		if (ft_putstr_fd_return("(null)", 1) == -1)
			return (false);
		(*total_number_of_print_char) += ft_strlen("(null)");
		return (true);
	}
	arg_len = ft_strlen(arg);
	if (ft_putstr_fd_return((char *)arg, 1) == -1)
		return (false);
	(*total_number_of_print_char) += arg_len;
	return (true);
}

bool	write_pointer(va_list args, int *total_number_of_print_char)
{
	const void		*ptr = va_arg(args, void *);
	const uintptr_t	pointer_uintptr = (uintptr_t)ptr;
	size_t			pointer_char_length;
	char			*pointer_char;
	int				putstr_length;

	if (ptr == NULL)
	{
		if (ft_putstr_fd_return("(nil)", 1) == -1)
			return (false);
		(*total_number_of_print_char) += ft_strlen("(nil)");
		return (true);
	}
	if (ft_putstr_fd_return("0x", 1) == -1)
		return (false);
	pointer_char_length = 2;
	pointer_char = ft_convert_base(pointer_uintptr, "0123456789abcdef");
	if (pointer_char == NULL)
		return (false);
	putstr_length = ft_putstr_fd_return(pointer_char, 1);
	free(pointer_char);
	if (putstr_length == -1)
		return (false);
	(*total_number_of_print_char) += (pointer_char_length + putstr_length);
	return (true);
}

bool	write_percent(va_list args, int *total_number_of_print_char)
{
	(void)args;
	if (ft_putchar_fd_return('%', 1) == -1)
		return (false);
	(*total_number_of_print_char)++;
	return (true);
}
