# ft_printf

*This project has been created as part of the 42 curriculum by mjaafar.*

## Description

The `ft_printf` project is about recreating the behavior of the standard C `printf()` function.

The goal is to build a custom formatted output function that handles different data types using variadic arguments.

The function prints formatted text to the standard output and returns the total number of characters printed.

## Supported Conversions

| Conversion | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a string. |
| `%p` | Prints a pointer address in hexadecimal. |
| `%d` | Prints a decimal integer. |
| `%i` | Prints an integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints a hexadecimal number in lowercase. |
| `%X` | Prints a hexadecimal number in uppercase. |
| `%%` | Prints a percent sign. |

## Instructions

### Compilation

Run the following command in the project directory:

```bash
make
```

This creates the static library:

```text
libftprintf.a
```

### Cleaning

Remove object files:

```bash
make clean
```

Remove object files and the compiled library:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

### Usage

Include the header in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

## Algorithm and Data Structures

The implementation uses variadic arguments through `va_list`, allowing the function to receive a variable number of arguments.

The main function reads the format string character by character. When it encounters a conversion specifier (`%`), it passes the specifier to a conversion handler.

The conversion handler identifies the requested type and calls the appropriate helper function.

Each helper prints the corresponding value and returns the number of characters printed. These return values are added together to calculate the total number of characters printed by `ft_printf()`.

Recursive functions are used to print decimal, unsigned, and hexadecimal numbers digit by digit. Pointer addresses are also printed in hexadecimal format.

The project uses no complex data structures. Its main mechanisms are:

- **Variadic arguments:** `va_list`, `va_start`, `va_arg`, and `va_end`.
- **Recursion:** Used to print numbers in the correct digit order.
- **Helper functions:** Separate conversion and printing responsibilities.
- **Character counting:** Each printing function returns the number of characters it writes.

## Resources

- C documentation and references for `printf()`.
- C standard library documentation for variadic functions (`stdarg.h`).
- Peer discussions and technical documentation.

### Use of AI

I used an AI assistant (Claude, by Anthropic) as a learning aid during this project:

- **Explanations:** Understanding variadic functions, format specifiers, pointers, and hexadecimal representation.
- **Step-by-step guidance:** Breaking down the implementation into smaller functions and understanding how the different components work together.
- **Testing and debugging:** Reviewing implementation decisions, identifying errors, and understanding edge cases.

I implemented the functions myself after studying the concepts and can explain the logic behind the code.
