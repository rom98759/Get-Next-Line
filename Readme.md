# Get Next Line (GNL)

**Get Next Line (GNL)** is a C function that reads a line from a file descriptor, including standard input, and returns it as a string. It handles multiple lines and buffers efficiently, ensuring that each call retrieves the next line from the input.

## Features
- Reads lines from a file descriptor.
- Handles reading from files and standard input.
- Supports multiple calls to fetch lines one by one.
- Efficient memory management with dynamic buffer resizing.

### How it works

1. The function reads a buffer from the file descriptor and stores it in a static variable.
2. It searches for a newline character in the buffer and copies the line to the output string.
3. If the buffer is empty, it reads more data from the file descriptor and appends it to the buffer.
4. The function returns 1 if a line is read, 0 if the end of file is reached, and -1 if an error occurs.
5. The output string is dynamically allocated and must be freed by the caller.

## Requirements
- The project must compile with no warnings.
- Must not use `malloc` or `free` inside the function.
- Ensure proper memory management for the returned string.

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/gnl.git
   ```
2. Compile the project using `cc`:
   ```bash
   cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o gnl
   ```

## Usage
1. Include the header `get_next_line.h` in your program.
2. Call `get_next_line()` in a loop to read lines from a file descriptor.
3. Free the output string after use to prevent memory leaks.

### Bonus

- The function can handle multiple file descriptors and read from them simultaneously.
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl
```

Example:
```c
#include "get_next_line.h"

int main() {
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while (get_next_line(fd, &line) > 0) {
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
```

## Functions

- **get_next_line(int fd, char **line)**: Reads the next line from the file descriptor `fd` and stores it in `line`.

## License
Distributed under the MIT License. See LICENSE for more information.

## Author

- Romain -  Github : [rom98759](https://github.com/rom98759)

