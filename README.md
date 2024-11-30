# Spot - Simple Powerful Toolkit

Spot is a simple, yet powerful C library that provides a collection of utilities and abstractions designed to make C programming experience safer and easier. It includes safer versions of standard C functions and a variety of helpful tools that can be seamlessly integrated into any C project.

## Features

- **Safer versions of standard C functions**: Includes improved versions of commonly used functions such as `malloc` and `strcpy`, with added safety checks to prevent common programming errors.
- **Utilities and abstractions**: A collection of useful utilities for tasks like string manipulation, memory management, and error handling.
- **Easy to integrate**: The entire library can be included in your project with a single header file, `spot.h`.

## Installation

To use Spot in your project, simply include the `spot.h` header file:

```c
#include "spot.h"
```

## Usage Examples

### Safe Memory Allocation

```c
#include "spot.h"

char *buffer = spt_malloc(1024);  // Safe memory allocation with error checking

if (!buffer) {
    // Handle memory allocation failure
}
```

## Functions and Utilities

Spot provides the following utilities:

## Contributing

Contributions are welcome! Feel free to fork the repository, create a branch, and submit a pull request. Please make sure to write tests for any new functionality and ensure that existing tests pass.

## License

Spot is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
