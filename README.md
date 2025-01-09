Updated 1/9/2025

Current project status:
- The vuln program on kali01 is vulnerable to buffer overflow due to incorrect array sizing failing at sprintf in the response function.
- The client program sends a very large message over the socket to the vulnerable program, causing a segfault due to overflow.
- Tested using netcat to interact with the program.

Goal:
- Follow this tutorial, however all in C, doing a Buffer Overflow. https://github.com/justinsteven/dostackbufferoverflowgood/blob/master/dostackbufferoverflowgood_tutorial.pdf
- Document
- Create a NOP Slide to excecute Shell code to run the calculator.

For next time: 
- Try to create the NOP slide to run the calculator.
