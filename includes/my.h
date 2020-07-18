/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** task02
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/wait.h>
#include "struct.h"
#define baseX "0123456789ABCDEF"
#define basex "0123456789abcdef"

void unalias(char *to_del);
char **strtoarray(char *str, char sign);
char **check_alias(char **tab);
char *write_inside(char *str, char c, int place);
char **delarr(char **tab, unsigned int delete);
void my_putarray(char **array);
char *my_strcatmulti(int nb, char *str, ...);
void alias(char **tab);
void my_putarrfd(char **array, int fd);
char *del(char *str, int place);
char *my_arr_to_str(char **tab);
char *del_char(char *str);
char *remplace_word_by_another(char *src, char *dst, char *new);

void change_args2d(char **arg, int nb, shell_s *shell);
void change_argsd(char **arg, int nb, shell_s *shell);
int my_tablen(char **dest);
char *find_change_arg2(shell_s *shell, char *line);
void check_seg(void);
void find_change_arg(shell_s *shell);
void my_perror(char *str);
char *path_complet(char *str, char *dpath, char *stock);
char *fpath(char **environ);
char **gt_pa(char *path);
void init(shell_s *shell);
pid_t pipe_fork(void);
void change_redirection(shell_s *shell);
int find_pipe(char *cmd);
void exec_pipe1(char **f_cmd, char **t_cmd, shell_s *shell, int a);
char **copy_env(char **env);
char **setenviron(char **environ, char **stock);
void use_cmd(shell_s *shell, int tmp);
int use_cmd_point(shell_s *shell);
char *fill_cmd(char *dest, char *cmd, int nbr, int nb);
int check_pipe(char *str);
int exec_pipe(char **environ, char *line, shell_s *shell);
char *find_fisrt_cmd(char *cmd);
char *find_two_cmd(char *cmd);
char *find_third_cmd(char *cmd);
char *find_cmd(char *line, int a, int tmp);
char **setenvr(char **envir, char **stock);
void cd(char **stock, char **env);
char **my_str_to_dtab(char *str, char c);
int nb_of_line(char *str, char c);
int nb_p(char *path);
char **check_set_or_unset(char **environ, char **stock);
int exec_bin(char **stock, char **environ);
void loop(shell_s *shell, char *str);
char *my_strcpy(char *dest, char *src);
int verif_x(char **dest, int lines, int colone, char **copy);
char **left(char **dest, int x , int y);
int verif_nb_x(char **dest, int lines, int colone);
int verif_x(char **dest, int lines, int colone, char **copy);
char **right(char **dest, int x , int y);
int verif_lose(int verif);
char **verif_o(char **dest, int lines, int colone, char **copy);
char **up(char **dest, int x, int y);
char **down(char **dest, int x, int y);
char **get_dest_up(char **dest, int x, int y);
char **get_dest_down(char **dest, int x, int y);
int x_getch(int ch, char **dest, int x, int y);
int y_getch(int ch, char **dest, int x, int y);
void print_t(char **dest, int lines);
char **dest_getch(int ch, char **dest, int x, int y);
int findx(char **dest, char *buffer);
char **get_dest_left(char **dest, int x, int y);
char **get_dest_right(char **dest, int x, int y);
int get_y_up(char **dest, int x, int y);
int get_y_down(char **dest, int x, int y);
int get_x_right(char **dest, int x, int y);
int get_x_left(char **dest, int x, int y);
int findy(char **dest, char *buffer);
void my_putchar(char c);
int tohexa(unsigned int number, char *base);
int print_s(char *str);
char **createto2char(int line, int col);
void usage(void);
int verif_file(char *file);
int verif(char **dest, int lines, int colone, char **copy);
int condition_v_l(char **dest, int lines, int colone, char **copy);
int screen(char *buffer, char **copy, char **dest, char *file);
char *buffer(char *text);
int verif_map(char *buffer, int lines , int colone);
int sokoban(char *file);
char **char2d(char *buffer);
int col(char *buffer);
int line(char *buffer);
int toctal(unsigned int number);
int tobinary(unsigned int number);
int tohexa(unsigned int number, char *base);
int printh(va_list params, char const *str, int a);
int print_o_b(va_list params, char const *str, int a);
int print_s_s(va_list params, char const *str, int a);
int print_d_mod(va_list params, char const *str, int a);
int nb_col(char *buffer);
int my_isneg(int nb);
int **createdbint(char * buffer, int **map, int a);
int nbrr(int nb);
int word(int n);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char const *str);
int my_printf(char const *str, ...);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int nbr_to_chiff(int nb);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char *str, char *str2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strncat(char *dest, char const *src, int nb);
int my_memset(char *buffer, char chara, int size);
int nbrr(int nb);
int word(int n);
char *my_strcat(char *dest, char *src);
