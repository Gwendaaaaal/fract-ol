/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:39:52 by gholloco          #+#    #+#             */
/*   Updated: 2024/03/19 17:29:18 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# ifndef MAX_FILES
#  define MAX_FILES 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*return_n_clean_stock(char *stock);
char	*get_next_line(int fd);
char	*ft_substrr(char *s, unsigned int start, size_t len);
char	*ft_strjoinn(char *s1, char const *s2);
char	*ft_strcpyy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);

#endif
