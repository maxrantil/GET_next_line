NAME = test_gnl

all: $(NAME)

$(NAME):
	@echo "This is get_new_line!"
	@echo ""
	@echo "	                                                                                             88  88"
	@echo "                           ,d                                                       ,d               88  \"\""
	@echo "                           88                                                       88               88"
	@echo " ,adPPYb,d8   ,adPPYba,  MM88MMM            8b,dPPYba,    ,adPPYba,  8b,     ,d8  MM88MMM            88  88  8b,dPPYba,    ,adPPYba,"
	@echo "a8\"    \`Y88  a8P_____88    88               88P'   \`\"8a  a8P_____88   \`Y8, ,8P'     88               88  88  88P'   \`\"8a  a8P_____88"
	@echo "8b       88  8PP\"\"\"\"\"\"\"    88               88       88  8PP\"\"\"\"\"\"\"     )888(       88               88  88  88       88  8PP\"\"\"\"\"\"\""
	@echo "\"8a,   ,d88  \"8b,   ,aa    88,              88       88  \"8b,   ,aa   ,d8\" \"8b,     88,              88  88  88       88  \"8b,   ,aa"
	@echo " \`\"YbbdP\"Y8   \`\"Ybbd8\"'    \"Y888            88       88   \`\"Ybbd8\"'  8P'     \`Y8    \"Y888            88  88  88       88   \`\"Ybbd8\"'"
	@echo " aa,    ,88"
	@echo " \"Y8bbdP\"                       888888888888                                             888888888888"
	@echo ""
	@make -C libft/ fclean && make -C libft/
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
	@echo "$(NAME) created"

clean:
	@rm -rf $(O_FILES)
	@echo ".o files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
