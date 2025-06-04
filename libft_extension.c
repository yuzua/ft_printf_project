#include "ft_printf.h"

int	ft_putnbr_fd_return(int n, int fd)
{
	int	putnbr_length;

	if (n == -2147483648)
	{
		if (ft_putstr_fd_return("-2147483648", fd) == -1)
			return (-1);
		return (sizeof("-2147483648") - 1);
	}
	if (n < 0)
	{
		if (ft_putchar_fd_return('-', fd) == -1)
			return (-1);
		n *= -1;
	}
	putnbr_length = 0;
	if (n >= 10)
	{
		putnbr_length = ft_putnbr_fd_return(n / 10, fd);
		if (putnbr_length == -1)
			return (-1);
	}
	if (ft_putchar_fd_return((n % 10) + '0', fd) == -1)
		return (-1);
	return (putnbr_length + 1);
}

int	ft_putstr_fd_return(char *s, int fd)
{
	size_t	s_i;

	if (s == NULL)
		return (-1);
	s_i = 0;
	while (s[s_i] != '\0')
	{
		if (ft_putchar_fd_return(s[s_i], fd) == -1)
			return (-1);
		s_i++;
	}
	return (s_i);
}

int	ft_putchar_fd_return(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

size_t	ft_strlcpy_reverse(char *dst, const char *src, size_t dsize)
{
	size_t	src_i;
	size_t	dst_i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dsize == 0)
		return (src_len);
	if (dsize > src_len)
		src_i = src_len;
	else
		src_i = dsize;
	dst_i = 0;
	while (src_i > 0)
		dst[dst_i++] = src[--src_i];
	dst[dst_i] = '\0';
	return (src_len);
}
