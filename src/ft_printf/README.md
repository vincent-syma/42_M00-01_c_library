# 42_M01: ft_printf()

## Table of Contents
- [Description](#description)
- [My code](#my-code)
	- [Variadic functions](#variadic-functions)
	- [Mandatory part](#mandatory-part)
	- [Bonus part](#bonus-part)


___

## Description

The goal of this 42 project was to recode the `printf()` function from libc.
```c
int	ft_printf(const char *, ...)
```

#### Requirements:
- The function has to handle the following conversions: `cspdiuxX%`
- Do not implement the **buffer management** of the original `printf()`.

#### Bonus requirements:
- Manage any combination of the following flags: `-`, `0`, `.` and the **field minimum width** under all conversions.
- Manage all the following flags: `#`, ` `,`+`


## My code

### Variadic functions
The original `printf()` function is implemented by using **variadic functions**, which is a little bit similar to **argc / argv**.

The difference is that the arguments are not passed through terminal, they can be of different data type and you are supposed to use them only in their order.

To work with the arguments I use:
```bash
1. va_list	args
2. va_start(args, format)
3. va_arg(args, variable data type)
4. va_end(args)
```

### Mandatory part
I wanted to make the code as efficient as it could be, so I wanted to use `libft` functions as much as possible.

Since the `printf()` function is supposed to return the number of printed signs, I had to change some of them a little bit from void to int return type (and also to handle the errors by adding -1 exit).

```bash
ft_putchar()
ft_putstr()
ft_putnbr()
```

I had to write some additional printing functions:
```bash
ft_puthex_unsigned()		# I made that one super variable
							# so it can be used for both 'x' and 'X'
							# specifiers and also as a part of ft_putptr.

ft_putnbr_unsigned()		# Just a ft_putnbr() tweeked
							# to not handle negative numbers.

ft_putptr()					# It has its special error outcome '(nil)'.
```


#### Note:
Since this is just a **partial** version of `printf()`, I had to make my own desicions in terms of function behaviour in some cases.

___

### Bonus part

I added a special **parsing subfunction** which recognizes all known **flags** and **specifiers**, stores them into a data structure `flags` to be used later and skips them.

The **printing part** was the tricky one. I found out that I have to count lengths of everything before I start to print it.

So I created another structure `format_info`, in which I stored different types of input values (`long val_signed`; `unsigned long val_unsigned`; `char char_val`; `char *str_val`), its length (`int len_content`) and length of all the paddings (`int len_prefix`; `int len_zero`; `int spaces`).

Then one by one I print it and count the number of printed characters.

---

## 👤 Author

**Simona Sucha**
*(also known as ssucha or vincent_syma)* <br>
Python & C · Developer, Software Tester · 42 student

🖥️ GitHub: https://github.com/vincent-syma/ <br>
🔗 LinkedIn: https://www.linkedin.com/in/simona-such%C3%A1-5a1b1928b <br>
✉️ Email: vincent.f.syma@email.cz <br>