# 📁 CLI File Manager

A lightweight command-line file manager written in **C** for performing essential file system operations. This is a tool I built out of my interest in learning about file systems in C, focusing on path safety and cross-platform compatibility.

## Features

* **Copy** 
* **Move** 
* **Rename**
* **Delete**
* **Path Sanitization:** * Converts Windows backslashes (`\`) to Unix slashes (`/`) for consistency.
    * Automatically strips quotes (`"`) and newlines (`\n`) from input.
    * Supports file paths containing spaces.



---

## Getting Started

### Prerequisites
You will need a C compiler (GCC, Clang, or MSVC) installed on your system.

### Compilation
Open your terminal and run the following command to compile the source:

```bash
gcc -o main main.c file_manager_funcs.c utils_funcs.c
```

### Run the program
After compiling, enter the following into your terminal

``` bash
./main
```

### ⚖️ License
Distributed under the MIT License.