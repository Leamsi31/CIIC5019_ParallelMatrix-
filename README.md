# CIIC5019_ParallelMatrix-
The project optimizes parallel matrix multiplication, crucial in scientific applications, for large datasets. Leveraging OpenMP on multi-core CPUs enhances efficiency, addressing computational demands in simulations and machine learning. Performance metrics guide evaluation, advancing high-performance computing for intricate datasets.

# Instructions on how to run the project:
Sure! Here's an example of a ReadMe.md file with instructions on how to install OpenMP and GCC:

# OpenMP and GCC Installation Guide

This guide provides step-by-step instructions on how to install OpenMP and GCC on your system.

## Prerequisites

Before proceeding with the installation, make sure you have the following prerequisites:

- A compatible operating system (e.g., Linux, macOS, Windows)
- Internet connection

## Installation Steps

Follow these steps to install OpenMP and GCC:

### Step 1: Install GCC

1. **Linux**:
   - For most Linux distributions, you can install GCC using the package manager. Open a terminal and run the following command:
     ```
     sudo apt-get install build-essential
     ```
     This command will install GCC along with other necessary tools.
     
   - For other Linux distributions, refer to the respective package manager documentation or official GCC website for installation instructions.

2. **macOS**:
   - Install Xcode command line tools by opening a terminal and running the following command:
     ```
     xcode-select --install
     ```
     Follow the on-screen prompts to complete the installation.

3. **Windows**:
   - Install MinGW-w64, which is a port of GCC for Windows. Download the installer from the official website: https://mingw-w64.org/doku.php/download

   - Run the installer and follow the installation wizard. Make sure to select the appropriate architecture (32-bit or 64-bit) and components (e.g., C compiler, C++ compiler).

### Step 2: Verify GCC Installation

To verify that GCC is installed correctly, open a terminal or command prompt and run the following command:
```
gcc --version
```
You should see the GCC version information printed on the screen.

### Step 3: Install OpenMP

1. **Linux**:
   OpenMP is typically included with GCC on Linux distributions. You don't need to install it separately.

2. **macOS**:
   OpenMP is also included with GCC on macOS. No additional installation is required.

3. **Windows**:
   If you installed MinGW-w64 using the steps above, OpenMP should already be available.

## 3a. Running the Program

To run the program follow these steps:

1. Open a terminal or command prompt.
2. Navigate to the directory where your program files are located.
3. Run the following command to compile the program:
   ````bash
   gcc -o test_matrix_multiply.exe test_matrix_multiply.c standard_sequential.c standard_parallel.c transposed_sequential.c transposed_parallel.c transpose.c print_matrix.c -fopenmp -lm -Wall
   ```
   
4. After successful compilation, run the program by executing the following command:
   ````bash
   ./test_matrix_multiply.exe
   ```

Note: Make sure that you have the necessary input files or data required by your program in the same directory.

Certainly! Here's an additional set of instructions specifically for running the program on Windows:

## Running the Program (Windows)

To run your program using the provided command on Windows, follow these steps:

1. Open a Command Prompt window.

2. Run the following command to compile the program:
   ````bash
   gcc -o test_matrix_multiply.exe test_matrix_multiply.c standard_sequential.c standard_parallel.c transposed_sequential.c transposed_parallel.c transpose.c print_matrix.c -fopenmp -lm -Wall
   ```
   
3. After successful compilation, run the program by executing the following command:
   ````bash
   test_matrix_multiply.exe
   ```

Note: Make sure that you have the necessary input files or data required by your program in the same directory.