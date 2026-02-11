*This project has been created as part of the 42 curriculum by ssucha/vincent_syma.*


## Table of Contents
- [Description](#description)
- [Algorithm](#algorithm)
	- [Variadic functions](#variadic-functions)
	- [Mandatory part](#mandatory-part)
	- [Bonus part](#bonus-part)


___

## Description

The goal of this project was to recode the `printf()` function from libc.
```c
int	ft_printf(const char *, ...)
```

#### Requirements:
- The function has to handle the following conversions: `cspdiuxX%`

#### Additional info:
- Do not implement the **buffer management** of the original printf().

#### Bonus requirements:
- Manage any combination of the following flags: `'-'`, `'0'`, `'.'` and the **field minimum width** under all conversions.
- Manage all the following flags: `'#'`, `' '` (space) ,`'+'`


## Algorithm

### Variadic functions
The original `printf()` function is implemented by using **variadic functions**, which is a little bit similar to **argc / argv**.

The difference is that the arguments are not passed through terminal, they can be of different data type and you are supposed to use them only in their order.

To work with the arguments I use:
1. `va_list	args`
2. `va_start(args, format)`
3. `va_arg(args, variable data type)`
4. `va_end(args)`

### Mandatory part
I wanted to make the code as efficient as it could be, so I wanted to use `libft` functions as much as possible.

Since the `printf()` function is supposed to return the number of printed signs, I had to change some of them a little bit from void to int return type (and also to handle the errors by adding -1 exit).

- `ft_putchar()`
- `ft_putstr()`
- `ft_putnbr()`

I had to write some additional printing functions:
- `ft_puthex_unsigned()`

*I made that one super variable so it can be used for both **x** and **X** specifiers and also as a part of ft_putptr.*

- `ft_putnbr_unsigned()`

*Just a `ft_putnbr()` tweeked to not handle negative numbers.*

- `ft_putptr()`

*It has its special error outcome `(nil)`.*

#### Note:
Since this is just a **partial** version of `printf()`, I had to make my own desicions in terms of function behaviour in some cases.

**One of them is:** When a `%` is not followed by any of the recognized format specifiers `cspdiuxX%`, the original function behavior is:
1. If there are NO arguments after `format`, it just prints `'%'` as any other character.
2. However when there ARE other arguments, it triggers `compilation error`.

3. Except for cases of other existing flags (like `-0.# +`). These are accepted by original `printf()` as known and do not trigger error. They are not handled in the mandatory part of my implementation though, so I make them **trigger an error**.

___

### Bonus part
Initially I thought that bonus part would be much easier than it was. :D

I added a special **parsing subfunction** which recognizes all known **flags** and **specifiers**, stores them into a data structure `flags` to be used later and skips them.

The **printing part** was the tricky one. I found out that I have to count lengths of everything before I start to print it.

So I created another structure `format_info`, in which I stored different types of input values (`long val_signed`; `unsigned long val_unsigned`; `char char_val`; `char *str_val`), its length (`int len_content`) and length of all the paddings (`int len_prefix`; `int len_zero`; `int spaces`).

Then one by one I print it and count the number of printed characters.

The biggest issues were:
- negative numbers
- **zero** flag
- **presicion** flag (I had to create `ft_putnstr()`)

*And of course I changed the error triggering behaviour mentioned in Mandatory part, since the flags are recognized as valid now. :)*