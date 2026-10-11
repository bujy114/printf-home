*This activity has been created as part of the 42 curriculum by lsallam.*

# ft_printf

## Description

The goal of this activity is to recreate the C `printf` function and package it as a static library, `libftprintf.a`, that can be linked into other programs.

```c
int ft_printf(const char *format, ...);
```

It writes to standard output and returns the number of characters printed (or -1 if `format` is NULL).

### Supported conversions

| Specifier | Prints |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is NULL) |
| `%p` | a pointer in hex, with `0x` prefix (`(nil)` if NULL) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` | an unsigned integer in lowercase hex |
| `%X` | an unsigned integer in uppercase hex |
| `%%` | a percent sign |

### Files

| File | Purpose |
|------|---------|
| `ft_printf.c` | main function, chooses the right handler |
| `ft_char.c` | `%c` |
| `ft_string.c` | `%s` |
| `ft_int.c` | `%d`, `%i` |
| `ft_unsigned.c` | `%u` |
| `ft_hex.c` | `%x`, `%X` |
| `ft_ptr.c` | `%p` |
| `ft_itoa.c`, `ft_strlen.c`, `ft_memcpy.c` | helper functions |
| `ft_printf.h` | header with all prototypes |

## Instructions

### Compilation

```sh
make
```

This creates `libftprintf.a`.

Other rules:

```sh
make clean    # remove object files
make fclean   # remove object files and the library
make re       # rebuild everything
```

### Usage

Include the header in your code:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	return (0);
}
```

Compile your program with the library:

```sh
cc main.c libftprintf.a -o test
./test
```

## Algorithm and data structures

### Main algorithm

`ft_printf` reads the format string once, from left to right:

1. If the character is not `%`, it is written directly with `write` and the counter goes up by 1.
2. If it is `%`, the next character is read and sent to a dispatcher (`type`), which calls the matching function for `c`, `s`, `d`, `i`, `p`, `u`, `x`, `X` or `%`.
3. At the end, the total count is returned.

**Why this approach:** the format string is only walked once, so the time is O(n) in the length of the output. A simple `if / else if` chain is enough for 9 specifiers, and it is easy to read and extend. A jump table or array of function pointers would be harder to read for no real gain at this size.

### Data structures

- **`va_list`** from `<stdarg.h>`: the only way in C to read a variable number of arguments. It is passed by pointer to the dispatcher so every `va_arg` call advances the same list.
- **`int *count`**: one counter shared by every print function through a pointer. Each function adds the number of characters it wrote, so the return value is always correct, even when output comes from recursion. A global variable would work too but is not allowed and would not be safe to reuse.
- **Lookup string** (`"0123456789abcdef"` and `"0123456789ABCDEF"`): the digit value is used as an index into the string, so converting a number to its hex character takes one step with no `if` or arithmetic on ASCII values. Switching between `x` and `X` only means switching the string.

### Number conversion

- **Hex (`%x`, `%X`, `%p`) and unsigned (`%u`)** use recursion: the function first prints `n / base`, then prints the last digit `n % base`. This prints digits in the correct order without needing a buffer, and the stack depth is at most 8 for hex and 10 for decimal on a 32-bit value, so it is safe.
- **Signed integers (`%d`, `%i`)** use `ft_itoa`, which allocates a string with `malloc`, since the final length depends on the number. `ft_int` prints it and then calls `free`, so there is no leak. `INT_MIN` is handled separately because `-INT_MIN` overflows an `int`.
- **Pointers (`%p`)** are cast to `unsigned long` (which is large enough to hold an address on 64-bit systems), printed as hex after a `0x` prefix. A NULL pointer prints `(nil)` to match the behavior of glibc.

### Edge cases handled

- `%s` with NULL prints `(null)`.
- `%p` with NULL prints `(nil)`.
- `INT_MIN` prints correctly.
- A lone `%` at the end of the string does not read past the end.
- A NULL format returns -1.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- GNU Make manual: https://www.gnu.org/software/make/manual/
- The C Programming Language, Kernighan and Ritchie (variable arguments and recursion)

### AI usage

AI was used for the following tasks:
- Explaining how Makefiles work (variables, pattern rules, execution order).
- Reviewing the code for bugs: a memory leak in `ft_int`, NULL handling for `%s` and `%p`, the `INT_MIN` case, and a wrong character count for `(nil)`.
- Suggesting test cases and a small `main` to compare `ft_printf` with the real `printf`.
- Helping write this README.

All the code was written by the author, and every suggestion was reviewed and understood before being applied.
