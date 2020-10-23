
default: oss user

clear:
	rm -f oss user

oss: oss.c
	gcc -Wall -ggdb -Werror -o oss oss.c

user: user.c
	gcc -Wall -ggdb -Werror -o user user.c
