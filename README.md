# push_swap
## Overview
The Push Swap project is a straightforward algorithmic challenge where the goal is to sort a set of integer values using two stacks and a set of manipulation instructions. The task is to write a program, named push_swap, in C that sorts the integers provided in the input, as well as output the operations it took to do so.

## Features
- **Efficent algorithm** that sorts the input integers with a minimal number of commands;
- **Error handling features** that only accepts input if it contains no syntax errors, no repetitions and is not bigger than an integer;
- **Flexible Input Handling:** The push_swap program is designed to handle input in various formats, allowing users to provide integers either as a single formatted string enclosed in quotation marks or as separate integer arguments directly in the command line. 
- **Thorough Testing and Debugging:** The program has undergone rigorous testing against memory leaks and runtime errors using tools like Valgrind, ensuring robustness and stability in execution.

## Possible Commands
- **sa (swap a):** Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb (swap b):** Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss:** sa and sb at the same time.
- **pa (push a):** Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- **pb (push b):** Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- **ra (rotate a):** Shift up all elements of stack a by 1.
The first element becomes the last one.
- **rb (rotate b):** Shift up all elements of stack b by 1. The first element becomes the last one.
- **rr:** ra and rb at the same time.
- **rra (reverse rotate a):** Shift down all elements of stack a by 1.
The last element becomes the first one.
- **rrb (reverse rotate b):** Shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr:** rra and rrb at the same time.

## Usage
1. Clone the repository
```
git clone git@github.com/dianazinchenko/push_swap.git
```
2. Go inside the push_swap folder and compile using the Makefile
```bash
cd push_swap
make
```
3. Run the program with one or multiple arguments
```bash
./push_swap "2 5 42 8 11"
or
./push_swap 2 5 42 8 11
```
**Output:**
pb
pb
ra
pa
pa
