/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct			s_path
{
	t_list				*aroute;
	t_list				*broute;
	int					size;
	struct s_path		*next;
	struct s_path		*prev;
}						t_path;

typedef struct			s_room
{
	t_list				*links;
	char				*name;
	int					ants;
	int					s;
	int					e;
	int					used;
	struct s_room		*next;
}						t_room;

t_room					*make(t_room **head);
void					checkrooms(t_room *head);
void					checkforend(t_path *paths);

t_room					*findinmap(t_room **head, char *name);
t_list					**makearr(int n);
t_room					**linkrooms(t_room **head, char **arr);
t_room					**makelinks(t_room **head, char *s);

void					endorstart(t_room *head, char *name, char *c);
void					makeroom(t_room **head, char *name, t_list *links);
int						checkroom(t_room *head, char *name);
t_room					*newroom(char *name, t_list *links);
void					deletemap(t_room **head);

void					pushpath(t_path **head, t_path *new_r);
t_path					*duppath(t_path *src);
t_path					*newpath(t_list *list);
void					deletepath(t_path **ptr);
void					deletepaths(t_path **head);

int						checkpaths(t_path *head, t_room *room);
t_path					*pathfinder(t_room *rooms);
void					pathstepper(t_path **head);
void					addstep(t_path **head, t_path *cur, t_room *room);

void					usedornot(t_path *r);
void					deletelist(void *c);
void					cleanpath(t_path *head);

int						possiblemove(t_path *path, int ants);
void					makeants(t_room *head, char *ants);
t_list					**addant(t_list **arr, int *loop, int n, t_path *ref);
t_list					**pushant(t_list **arr, int n, t_path *paths);
void					outputants(t_path *path);

void					outputant(int ant, char *name);
void					starterror(void);
void					linkerror(void);
void					roomerror(void);
void					anterror(void);



#endif
