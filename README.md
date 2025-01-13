Updated 1/13/2025. 

Current project status:
- The vuln program on kali01 is vulnerable to buffer overflow due to incorrect array sizing failing at sprintf in the response function.
- The client program sends a very large message over the socket to the vulnerable program, causing a segfault due to overflow. A simple Dos Attack.
- Tested using netcat to interact with the program.

Goal:
- The original goal was to create a NOP slide to excecute shell code on the machine running the vulnerable program.
- I have decided to pause the project here, as I cannot find any documentation on exploiting this vulnerability on a program running on Kali Linux, and investigating this is     too much of a time/energy and I wish to persue other projects.
- If I were to continue forward, I would
    -   use Immunity Debugger to see if I can overwrite the EIP assembly value
    -   Research zsh shellcode to excecute the calculator app
    -   set the value of EIP to JMP ESP to redirect the excecution to the above shellcode that was part of the payload.
    -   Pop calc
