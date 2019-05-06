**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
sleeping: the process is blocked waiting for some event or it has been put to sleep because it ran for its entire timeslice

ready-to-run: the process is awake and ready to be scheduled as soon as space frees up

running: the process is running on a CPU


**2. What is a zombie process?**

a zombie process or defunct process is a process that has completed execution(via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state" 


**3. How does a zombie process get created? How does one get destroyed?**
the child process has died and needs to be wait()ed on by the parent
A zombie process is created when a child has died and needs to be wait()ed on by the parent. After the wait() is executed and reads the exit and other information, the zombie process is removed.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages are faster than non-compiled languages. Also, because they are strongly typed, the compiler are better at detecting errors.