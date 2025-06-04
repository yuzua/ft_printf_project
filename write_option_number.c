#include "ft_printf.h"

bool	write_number(va_list args, int *total_number_of_print_char)
{
	const int	arg = va_arg(args, int);
	int			arg_int;
	int			arg_length;

	arg_int = arg;
	arg_length = 0;
	if (arg == -2147483648)
	{
		arg_length = ft_putnbr_fd_return(arg_int, 1);
		if (arg_length == -1)
			return (false);
		return ((*total_number_of_print_char) += arg_length, true);
	}
	if (arg < 0)
	{
		if (ft_putchar_fd_return('-', 1) == -1)
			return (false);
		arg_int *= -1;
		arg_length++;
	}
	arg_length += ft_putnbr_fd_return(arg_int, 1);
	if (arg_length == -1)
		return (false);
	(*total_number_of_print_char) += arg_length;
	return (true);
}

bool	write_unsigned_number(va_list args, int *total_number_of_print_char)
{
	const unsigned int	arg = va_arg(args, unsigned int);
	char				*num_str;
	int					arg_length;

	num_str = ft_convert_base(arg, "0123456789");
	if (num_str == NULL)
		return (false);
	arg_length = ft_putstr_fd_return(num_str, 1);
	free(num_str);
	if (arg_length == -1)
		return (false);
	(*total_number_of_print_char) += arg_length;
	return (true);
}

bool	write_lower_number(va_list args, int *total_number_of_print_char)
{
	const unsigned int	arg = va_arg(args, unsigned int);
	char				*lower_number_char;
	int					lower_number_char_length;

	lower_number_char = ft_convert_base(arg, "0123456789abcdef");
	if (lower_number_char == NULL)
		return (false);
	lower_number_char_length = ft_putstr_fd_return(lower_number_char, 1);
	free(lower_number_char);
	if (lower_number_char_length == -1)
		return (false);
	(*total_number_of_print_char) += lower_number_char_length;
	return (true);
}

bool	write_upper_number(va_list args, int *total_number_of_print_char)
{
	const unsigned int	arg = va_arg(args, unsigned int);
	char				*lower_number_char;
	int					lower_number_char_length;

	lower_number_char = ft_convert_base(arg, "0123456789ABCDEF");
	if (lower_number_char == NULL)
		return (false);
	lower_number_char_length = ft_putstr_fd_return(lower_number_char, 1);
	free(lower_number_char);
	if (lower_number_char_length == -1)
		return (false);
	(*total_number_of_print_char) += lower_number_char_length;
	return (true);
}
