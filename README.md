*This project has been created as part of the 42 curriculum by `gcouto-b`*

# ft_printf

## About

This is a custom C implementation of the standard library `printf` function as part of the 42 School Common Core curriculum. It introduces variadic functions.

## Features

It manages the following format specifiers:

| Specifier | Description |
| --- | --- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common `C` convention). |
| `%p` | The `void *` pointer argument has to be printed in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

## Installation

- Clone the repo.
- run:

```bash
make          # builds the library (libftprintf.a)
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean + all
```

## Resources

- `man`
- [man7.org](https://man7.org/linux/man-pages/index.html)
- [printfTester](https://github.com/Tripouille/printfTester)
- [Variable-Length Parameter Lists](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Variable-Number-of-Arguments.html)
- AI was used to identify test cases not originally covered.
