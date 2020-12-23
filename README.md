#0x19. C - Stacks, Queues - LIFO, FIFO

## Description  :computer:
Monty Bytecode Interpreter built with the C programming language.

### Compilation & Output  :wrench:

```
gcc -Wall -Werror gcc -Wall -Werror *.c
```

### Example Usage

```
push 1
push 5
pall
add
pall
```
output:
```
5
1
6
```

### Opcodes  :snake:

---

* **push**
  * Pushes an element to the stack.

* **pall**
  * Prints all the values on the stack, starting from the top of the stack.

* **pint**
  * Prints the value at the top of the stack, followed by a new line.

* **pop**
  * Removes the top element of the stack.

* **swap**
  * Swaps the top two elements of the stack.

* **add**
  * Adds the top two elements of the stack.

* **nop**
  * Do no action.

### Advanced tasks

* **sub**
  * Subtracts the top element of the stack from the second top element of the stack.

* **div**
  * Divides the second top element of the stack by the top element of the stack.

* **mul**
  * Multiplies the second top element of the stack with the top element of the stack.

* **mod**
  * Computes the rest of the division of the second top element of the stack by the top element of the stack.

* **pchar**
  * Prints the char at the top of the stack, followed by a new line.

* **pstr**
  * Prints the string starting at the top of the stack, followed by a new line.

* **rotl**
  * Rotates the stack to the top.

* **rotr**
  * Rotates the stack to the bottom.

* **stack**
  * Sets the format of the data to a stack (LIFO). This is the default behavior of the program.

* **queue**
  * Sets the format of the data to a queue (FIFO).

### Brainf*ck scripts

* [1000-holberton.bf](./bf/1000-holberton.bf)
   * A Brainf*ck script that prints Holberton, followed by a new line.

* [1001-add.bf](./bf/1001-add.bf)
   * A Brainf*ck script that adds two digits given by the user.

* [1002-mul.bf](./bf/1002-mul.bf)
  * A Brainf*ck script that multiplies two digits given by the user.

* [1003-mul.bf](./bf/1003-mul.bf)
  * A Brainf*ck script that multiplies two digits given by the user.


---

## Authors  :black_nib:
* **Amilcar Armmand** - [AmilcarArmmand](https://github.com/AmilcarArmmand)
* **Maxwell Lovell** - [Maxwell Lovell](https://github.com/JohnBogey)