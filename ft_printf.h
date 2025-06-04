#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>

# include "libft/libft.h"

typedef bool	(*t_format_function)(
	va_list arg,
	int *total_number_of_print_char);

typedef struct s_printf_format_entry
{
	char				specifier;
	t_format_function	function;
}	t_printf_format_entry;

int							ft_printf(const char *format, ...);
int							ft_printf_processor(
								const char *format,
								va_list args);
bool						print_format_specifier(
								char specifier,
								va_list args,
								int *total_number_of_print_char);

const t_printf_format_entry	*find_t_printf_format_entry(char specifier);
bool						write_a_char(
								va_list args,
								int *total_number_of_print_char);
bool						write_string(
								va_list args,
								int *total_number_of_print_char);
bool						write_pointer(
								va_list args,
								int *total_number_of_print_char);
bool						write_percent(
								va_list args,
								int *total_number_of_print_char);

bool						write_number(
								va_list args,
								int *total_number_of_print_char);
bool						write_unsigned_number(
								va_list args,
								int *total_number_of_print_char);
bool						write_lower_number(
								va_list args,
								int *total_number_of_print_char);
bool						write_upper_number(
								va_list args,
								int *total_number_of_print_char);

char						*ft_convert_base(unsigned long n, char *base);
bool						is_valid_base(char *base);

int							ft_putnbr_fd_return(int n, int fd);
int							ft_putstr_fd_return(char *s, int fd);
int							ft_putchar_fd_return(char c, int fd);
size_t						ft_strlcpy_reverse(
								char *dst,
								const char *src,
								size_t dsize);

#endif