
1. What is a function pointer?

A function pointer is a variable that stores the address of a function and can be used to call that function indirectly.

int (*funptr)(int,int);
funptr = &sum;
funptr(10,20);   // calls sum(10,20)


So instead of calling the function by name, you call it through a pointer.

2. Why function pointers are IMPORTANT in C & Embedded Systems 🚀

In embedded systems, function pointers are used when:

1️⃣ Dynamic behavior is required (Runtime decision)

In embedded systems:

We don’t know at compile time which function should run

Decision depends on:

Interrupt

Mode

Sensor input

Communication command

State machine

📌 Example:

if(command == ADD)
    sum(a,b);
else if(command == MUL)
    mul(a,b);


⬇ Using function pointer ⬇

funptr = sum;  // or mul
funptr(a,b);


✔ Cleaner
✔ Faster switching
✔ Scalable

2️⃣ Used heavily in Drivers & HAL layers

![image alt](https://github.com/ThummaRahul/Function_pointer/blob/main/1765505702752.jpg?raw=true)

Embedded drivers use function pointers for:

Abstraction

Portability

📌 Example (UART driver):

struct uart_ops {
    void (*init)(void);
    void (*send)(char);
    char (*recv)(void);
};


✔ Same application code
✔ Different hardware implementation
✔ Only function pointers change

👉 This is how STM32 HAL, Linux drivers, RTOS work internally.

3️⃣ Interrupt handling (VERY IMPORTANT ⚡)

In microcontrollers:

Interrupt Vector Table = Array of function pointers

Each interrupt points to a handler function

void (*ISR_Vector[])(void) = {
    Reset_Handler,
    Timer_ISR,
    UART_ISR,
};


👉 Without function pointers, interrupts are impossible.

4️⃣ State Machines (Common Embedded Pattern)
void state_idle(void);
void state_run(void);
void state_error(void);

void (*current_state)(void);

current_state = state_idle;
current_state();  // calls idle


✔ No if-else hell
✔ Clean state transitions
✔ Efficient memory usage

5️⃣ RTOS (You already use RTX 😉)

RTOS task creation uses function pointers:

os_tsk_create(task1, priority);


Internally:

void (*task_func)(void);


👉 Task = function pointer

3. Advantage of Function Pointer over Normal Function Call (IN YOUR CODE)
Your normal method:
printf("sum : %d", sum(10,20));


❌ Fixed at compile time
❌ Cannot change behavior dynamically
❌ Not scalable

Function pointer method:
int (*funptr)(int,int);
funptr = &sum;
printf("sum : %d", funptr(10,20));

✅ Advantages:
Feature	Normal Call	Function Pointer
Runtime flexibility	❌ No	✅ Yes
Dynamic function selection	❌ No	✅ Yes
Used in drivers/RTOS	❌ No	✅ Yes
Reduces if-else chains	❌ No	✅ Yes
Interrupt / callback support	❌ No	✅ Yes
4. REAL Embedded Example using your code
int (*funptr)(int,int);

char operation = '*';

if(operation == '+')
    funptr = sum;
else if(operation == '*')
    funptr = mul;
else if(operation == '-')
    funptr = sub;

printf("Result = %d", funptr(10,20));


👉 Same code
👉 Different behavior
👉 Zero function-name dependency

5. Interview-Ready One-Line Answer 🧠

Function pointers are used in embedded systems to achieve runtime flexibility, hardware abstraction, interrupt handling, RTOS task management, and efficient state machines. They allow dynamic selection of functions instead of fixed compile-time calls.
