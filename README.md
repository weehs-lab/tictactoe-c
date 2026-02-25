# tictactoe-c

## Introduction

This tic-tac-toe program is fully written in C as a practice for my C
programming skills. It is practically equivalent to the [C++ version][1]. 

Additionally, it was written for me to learn how to prepare Makefiles and it 
acts as a training to familiarize with 42's Norminette (The decision to obey 
the Norm is just for fun, because I think the Norm made my code clean, except 
I disabled `INVALID_HEADER` (why would you want that when you have already 
used [GPL](#license) for this?), `GLOBAL_VAR_NAMING`, `USER_DEFINED_TYPEDEF`, 
`STRUCT_TYPE_NAMING` (we are not in the Piscine), and `FORBIDDEN_STRUCT` (I  
want to enforce code safety and I do not prefer placing the entire `struct` 
declaration in the header file)).

Moreover, it serves as a practice for me to learn how to prepare README files 
through a terminal. The entire project is done in a TTY environment (Headless 
Debian installation, `multi-user.target`, no desktop environments), written 
using `vim`.

## How to Use

1. It will show up with player X first.
2. Write your position in form of (x y).
3. It will repeat step 1 and 2 but for player O.
4. The game continues until draw or either player X or O wins.

## Compilation

```bash
git clone https://github.com/weehs-lab/tictactoe-c.git
cd ./tictactoe-c
make all
./tictactoe-c
```

## Notes

This project is written for Debian 13. It should be working on all environments
as this project is written with C standard libraries. For most Linux 
distributions, `build-essentials` will do.

In the `Makefile`, I've introduced `all`, `clean`, `fclean`, `re` and 
`norminette` (Where most are just standard options that an average developer 
would implement).

| `make` options | What do they do? |
| :---: | :--- |
| `all` | Builds everything. |
| `clean` | Removes all object files. |
| `fclean` | Removes all object files and the binary executable. |
| `re` | Combination of `fclean` and `all`, meaning it recompiles everything. |
| `norminette` | Conducts Norm check. Requires the official [Norminette][2]. |

## License

This project is licensed under the GNU General Public License v3.0 - see the
[COPYING](COPYING) file for details.

[1]: https://github.com/weehs-lab/tictactoe
[2]: https://github.com/42school/norminette
