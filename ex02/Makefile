# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 17:37:49 by sbouheni          #+#    #+#              #
#    Updated: 2024/06/03 18:05:37 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	mutant

CXX						=	c++
CXXFLAGS				=	-Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

INCLUDE_DIR				=	include/
SRCS_DIR				=	source/
OBJ_DIR					=	obj/

SRCS					=	main.cpp											\

OBJS        			=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o			:	$(SRCS_DIR)%.cpp | $(OBJ_DIR)
							$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)				:
							mkdir -p $(OBJ_DIR)

clean					:
							rm -rf $(OBJ_DIR)

fclean					:	clean
							rm -rf $(NAME)

re						:	fclean all

.PHONY					:	all clean fclean re
