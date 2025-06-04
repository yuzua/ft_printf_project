#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_number_of_print_char;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	total_number_of_print_char = ft_printf_processor(format, args);
	va_end(args);
	return (total_number_of_print_char);
}

int	ft_printf_processor(const char *format, va_list args)
{
	int		total;
	size_t	i;
	bool	is_percent;

	total = 0;
	is_percent = false;
	i = 0;
	while (format[i] != '\0')
	{
		if (is_percent)
		{
			if (!print_format_specifier(format[i++], args, &total))
				return (-1);
			is_percent = false;
			continue ;
		}
		if (format[i] == '%')
			is_percent = true;
		else if (ft_putchar_fd_return(format[i], 1) == -1)
			return (-1);
		if (!is_percent)
			total++;
		i++;
	}
	return (total);
}

bool	print_format_specifier(
			char specifier, va_list args, int *total_number_of_print_char
		)
{
	const t_printf_format_entry	*format_entry;

	format_entry = find_t_printf_format_entry(specifier);
	if (format_entry == NULL)
		return (false);
	if (
		format_entry->function(args, total_number_of_print_char) == false
	)
		return (false);
	return (true);
}

const t_printf_format_entry	*find_t_printf_format_entry(char specifier)
{
	static const t_printf_format_entry	format_table[] = {
	{'c', write_a_char},
	{'s', write_string},
	{'p', write_pointer},
	{'d', write_number},
	{'i', write_number},
	{'u', write_unsigned_number},
	{'x', write_lower_number},
	{'X', write_upper_number},
	{'%', write_percent}
	};
	size_t								format_table_size;
	size_t								format_table_i;

	format_table_size = sizeof(format_table) / sizeof(format_table[0]);
	format_table_i = 0;
	while (format_table_i < format_table_size)
	{
		if (format_table[format_table_i].specifier == specifier)
			return (&format_table[format_table_i]);
		format_table_i++;
	}
	return (NULL);
}
