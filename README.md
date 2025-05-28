# 📄 get_next_line (GNL)

<div align="center">
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-success" alt="Status">
  <img src="https://img.shields.io/badge/42-School-brightgreen" alt="42">
  <br><br>
</div>

<details open>
<summary><b>🚀 Overview</b></summary>

The **get_next_line** project is about creating a function that reads from a file descriptor and returns one line at a time. This project introduces the concept of static variables in C and helps deepen understanding of file operations, memory allocation, and string manipulation.
</details>

<details>
<summary><b>✨ Features</b></summary>

- Read text from a file descriptor, one line at a time
- Properly handle memory allocation and deallocation
- Adaptable buffer size through BUFFER_SIZE compilation flag
- Supports reading from different file descriptors
- Preserves reading position between function calls
</details>

<details>
<summary><b>🛠️ Function Overview</b></summary>

<details>
<summary><b>🔑 Main Function</b></summary>

| Function | Description |
|----------|-------------|
| `get_next_line` | Returns one line at a time from a file descriptor |

</details>

<details>
<summary><b>⚙️ Helper Functions</b></summary>

| Function | Description |
|----------|-------------|
| `ft_read_till_n` | Reads from file descriptor until newline character is found |
| `ft_get_line` | Extracts a complete line (up to newline) from holder |
| `ft_subs_line_from_holder` | Updates holder by removing the line that was just returned |
| `ft_strjoiner` | Joins two strings into a new one and frees the first |
| `ft_strchr` | Locates first occurrence of character in string |
| `ft_strlen` | Calculates the length of a string |
| `ft_substr` | Extracts a substring from a given string |
| `ft_free` | Frees memory allocated for a string and sets pointer to NULL |

</details>
</details>

<details>
<summary><b>🛠️ Installation</b></summary>

```bash
# Clone the repository
git clone https://github.com/Flingocho/get_next_line.git

# Navigate to the directory
cd get_next_line
```

### Project Structure

The project follows a modern directory structure:

```
get_next_line/
├── include/              # Header files directory
│   └── get_next_line.h   # Main header file with function prototypes
├── src/                  # Source files directory
│   ├── get_next_line.c         # Main function implementation
│   └── get_next_line_utils.c   # Helper functions implementation
├── obj/                  # Object files (created during compilation)
└── Makefile              # Build automation
```
</details>

<details>
<summary><b>📋 Usage</b></summary>

### Compilation

```bash
# Compile with default buffer size (10)
make

# Compile with custom buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 src/get_next_line.c src/get_next_line_utils.c -I./include
```

### Integration Into Your Project

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
</details>

<details>
<summary><b>⚙️ How It Works</b></summary>

1. The function uses a static variable `holder` to store any leftover text between function calls
2. When called, it checks if `holder` already contains a newline; if not, it reads more data
3. It reads data in chunks of `BUFFER_SIZE` until a newline is found or EOF is reached
4. It extracts one line (up to and including the newline character) and returns it
5. It updates `holder` to contain only the remaining text for future calls
6. When EOF is reached and all text is processed, it returns NULL

### Buffer Size

- The buffer size can be adjusted during compilation with the `-D BUFFER_SIZE=n` flag
- Larger buffer sizes can improve performance with large files but use more memory
- Smaller buffer sizes use less memory but may require more read operations

</details>

<details>
<summary><b>🧪 Testing</b></summary>

Create a test file:

```bash
echo -e "Line 1\nLine 2\nLine 3\nLast line without newline" > test.txt
```

Create a test program:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int line_count = 0;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", ++line_count, line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror test.c src/get_next_line.c src/get_next_line_utils.c -I./include -o test_gnl
./test_gnl
```
</details>

<details>
<summary><b>🌟 Key Learning Outcomes</b></summary>

- Understanding static variables and their persistence across function calls
- File descriptor handling and read operations
- Advanced memory management and avoiding memory leaks
- String manipulation and buffer handling
- Implementing functions with minimal dependencies
</details>

<details>
<summary><b>📜 License</b></summary>

This project is part of the 42 School curriculum and is provided under the [MIT License](LICENSE).
</details>

---

<div align="center">
  Created with ❤️ by <a href="https://github.com/Flingocho">jvidal-t</a>
</div>
