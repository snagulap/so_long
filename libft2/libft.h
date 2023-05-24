/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:20:17 by snagulap          #+#    #+#             */
/*   Updated: 2023/05/15 13:39:47 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int ch, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(char *s, size_t c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *str, const char *str2, size_t len);
void	*ft_memmove(void *dst, void *src, size_t len);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
size_t	ft_wordlen(char const *s, char c);
size_t	ft_wordcount(char const *s, char c);
char	*ft_wordcpy(char const *src, size_t b);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*read_line(char *buff);
char	*read_buff(int fd, char *buffer);
char	*get_next_line(int fd);
char	*str_combine(char *str1, char *str2);
char	*ft_strdup1(char *s1);
int		str_len(char *str);
char	*str_chr(char *str, int c);
// char	*ft_strdup(char *s1);
char	*str_join(char *str1, char *str2);
int		ft_printf(const char *format, ...);
int		ft_print(va_list args, char format);
int		ft_printnumlen(unsigned int num);
char	*ft_uitoa(unsigned int num);
int		ft_print_uns(unsigned int num);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		count_hex_num(size_t num);
char	*hex_str(unsigned long num, char base);
int		ft_printhex(unsigned int num, char base);
int		ft_print_pointer(void *p);
int		ft_print_num(int num);

#endif
