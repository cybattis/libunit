/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:47:32 by cybattis          #+#    #+#             */
/*   Updated: 2022/02/10 17:51:29 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 2048

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

typedef struct s_matrix
{
	float	m[4][4];
}	t_matrix;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* math */
float		ft_lerp(float a, float b, float f);

/* vec2 */
t_vec2		vec2(float x, float y);
t_vec2		vec2_zero(void);
t_vec2		vec2_set(float value);
t_vec2		*vec2_add(t_vec2 *self, t_vec2 v2);
t_vec2		*vec2_multv2(t_vec2 *self, t_vec2 v2);
t_vec2		*vec2_multi(t_vec2 *self, long n);
t_vec2		*vec2_multf(t_vec2 *self, float n);
t_vec2		*vec2_divv2(t_vec2 *self, t_vec2 v2);
t_vec2		*vec2_divi(t_vec2 *self, long n);
t_vec2		*vec2_divf(t_vec2 *self, float n);
float		vec2_mag(t_vec2 vec2);
t_vec2		*vec2_normalize(t_vec2 *v);
t_vec2		vec2_normalized(t_vec2 v);

/* vec3 */
t_vec3		vec3(float x, float y, float z);
t_vec3		vec3_zero(void);
t_vec3		vec3_set(float value);
t_vec3		*vec3_add(t_vec3 *self, t_vec3 v3);
t_vec3		*vec3_multv3(t_vec3 *self, t_vec3 v3);
t_vec3		*vec3_multi(t_vec3 *self, long n);
t_vec3		*vec3_multf(t_vec3 *self, float n);
t_vec3		*vec3_divv3(t_vec3 *self, t_vec3 v3);
t_vec3		*vec3_divi(t_vec3 *self, long n);
t_vec3		*vec3_divf(t_vec3 *self, float n);
t_vec3		*vec3_normalize(t_vec3 *v);
t_vec3		vec3_normalized(t_vec3 v);
t_vec3		*vec3_clamp_max(t_vec3 *v, float x, float y, float z);
t_vec3		*vec3_clamp_min(t_vec3 *v, float x, float y, float z);
t_vec3		vec3_lerpf(t_vec3 base, t_vec3 high, float value);
float		vec3_mag(t_vec3 v);

/* vec4 */
t_vec4		vec4(float x, float y, float z, float w);
t_vec4		vec4_zero(void);
t_vec4		vec4_set(float value);
t_vec4		*vec4_add(t_vec4 *self, t_vec4 v4);
t_vec4		*vec4_multv4(t_vec4 *self, t_vec4 v4);
t_vec4		*vec4_multi(t_vec4 *self, long n);
t_vec4		*vec4_multf(t_vec4 *self, float n);
t_vec4		*vec4_divv4(t_vec4 *self, t_vec4 v4);
t_vec4		*vec4_divi(t_vec4 *self, long n);
t_vec4		*vec4_divf(t_vec4 *self, float n);
t_vec4		*vec4_normalize(t_vec4 *v);
t_vec4		vec4_normalized(t_vec4 v);
t_vec4		*vec4_clamp_max(t_vec4 *v, t_vec4 clamp);
t_vec4		*vec4_clamp_min(t_vec4 *v, t_vec4 clamp);
t_vec4		vec4_lerpf(t_vec4 base, t_vec4 high, float value);
float		vec4_mag(t_vec4 v);

/* matrix */
void		matrix_mult44(float m1[][4], float m2[][4], t_matrix *out);
t_vec3		matrix_mult44v3(const t_vec3 *v, t_matrix *matrix);
t_vec4		matrix_mult44v4(const t_vec4 *v, t_matrix *matrix);

/* Check */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isspace(int c);

/* Memory */
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *src, int cpy, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t n);

	/* utils */
void		*ft_free_all(char **strs, size_t i);

/* number */
int			ft_nbrlen(long nb);
int			ft_atoi(const char *str);
long		ft_atol(const char *s);
int			ft_atoi_base(const char *str, const char *base);
char		*ft_itoa(int n);

/* String */
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
int			ft_strichr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_strrev(char *s);
void		ft_strnrev(char *s, size_t n);
char		*ft_get_next_line(int fd);
char		*ft_str_tolower(char *str);
char		*ft_str_toupper(char *str);

/* I/O */
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_puts(char *s);
void		ft_putnbr(int nb);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_printf(const char *format, ...);
void		ft_print_matrix(int fd, t_vec3 **matrix, int size);

/* Single chained list */
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);

#endif
