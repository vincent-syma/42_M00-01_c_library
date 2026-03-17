# M01: get_next_line()

## Table of Contents
- [Description](#description)
- [Algorithm](#algorithm)
	- [Dynamic allocation](#dynamic-allocation)
	- [Code walk-through](#code-walk-through)
	- [Bonus part](#bonus-part)

___

## Description

The goal of this project was to write a function that returns a line read from a
file descriptor.
```c
char *get_next_line(int fd);
```

#### Requirements:
- Repeated calls (e.g., using a loop) to the `get_next_line()` function should let
you read the text file pointed to by the file descriptor, **one line at a time**.
- The function should return the line that was read.
If there is nothing left to read or if an error occurs, it should return `NULL`.
- The function works as expected both when reading a `file` and when
reading from the `standard input`.
- The returned line should include the terminating `\n` character,
except when the end of the file is reached and the file does not end with a `\n`
character.
- `get_next_line()` exhibits undefined behavior if the file associated with the file descriptor is modified after the last call, while `read()` has not yet reached the end of the file.
- `get_next_line()` also exhibits undefined behavior when reading a binary file.


#### Forbidden:
- `libft`
- `lseek()`
- `global variables`
- read the whole file and then process each line

#### Bonus requirements:
- using `only one static variable`
- `get_next_line()` can manage `multiple file descriptors at the same time`. For example, if you are reading from file descriptors 3, 4, and 5, you should be able to read from a different file descriptor with each call, without losing track of the reading state of each file descriptor or returning a line from a different one.


## Algorithm

### Dynamic allocation

I use dynamic allocation of variables instead of static. It is important because static is not as flexible as we need for different kinds of inputs that we have to be able to handle. I ran into it when testing my code.

I dynamically allocate by:
- using directly `malloc()`
- my own subfunction that is using `malloc()` inside: `ft_strdup()`

On error it is neccessary to:
- free all previously dynamically allocated variables
- and then return `NULL`

On the successful exit:
- I also free allocated variables
- but it is important not to free the `stash[fd]`, if there is still data to read in the next calling!

For freeing, I mostly use subfunction `free_stash()`. It frees the stash passed as argument by using `free()` and also sets its value to `NULL`.

### Code walk-through

I use subfunction `read_to_stash()` to fill the buffer using `read()` and end it with `\0` so I can work with the data in a form of a string.

Then I add it to the `stash[fd]` and continue doing so until the last added `buffer` contents does not contain `\n` or the input ends.

When the `ft_strchr()` finds a newline or the file ends, the reading ends and the `get_next_line()` function returns the last line found in the stash.

It does so by using subfunction `extract_line_trim_stash()`. This subfunction also modifies the stash, so it does not contain the returned line anymore.

---

### Bonus part
I decided to incorporate the bonus requirements to the mandatory part as well. So the bonus files contain basically the same code as the basic ones.

I used only 1 static variable stash from the beginning and added multiple fd option as a small variation in the end.

In the first version I worked only with `static char *stash`, whereas in the final I changed it to `static char *stash[MAX_FD]` - array, where each `fd` has its own `stash[fd]`. Since each fd is unique, each `stash[fd]` is unique as well.

---

## 👤 Author

**Simona Sucha**
*(AKA ssucha or vincent_syma)* <br>
Python & C · Developer, Software Tester · 42 student

🖥️ GitHub: https://github.com/vincent-syma/ <br>
🔗 LinkedIn: https://www.linkedin.com/in/simona-such%C3%A1-5a1b1928b <br>
✉️ Email: vincent.f.syma@email.cz <br>