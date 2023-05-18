<h1>Executing a program</h1>
<hr>
<p>The system call <code>execve</code> allows a process to execute another program (man 2 <code>execve</code>). Note that this system call does load the new program into the current process’ memory in place of the “previous” program: on success <code>execve</code> does not return to continue the rest of the “previous” program.</p>
<p><b>Warning:</b> in this example, <code>execve</code> is used without the current environment (last argument), don’t forget to add it in your Shell!</p>
<pre><code
julien@ubuntu:~/c/shell$ cat exec.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic exec.c -o exec
julien@ubuntu:~/c/shell$ ./exec
Before execve
total 120
drwxr-xr-x   2 root root 61440 Dec  4 00:08 bin
drwxr-xr-x   2 root root  4096 Jul 19 13:47 games
drwxr-xr-x  58 root root  4096 Oct 27 13:10 include
drwxr-xr-x 138 root root  4096 Dec  4 00:08 lib
drwxr-xr-x   3 root root  4096 Nov 10 09:54 lib32
drwxr-xr-x   3 root root  4096 Nov 10 09:54 libx32
drwxr-xr-x  10 root root  4096 Jul 19 13:42 local
drwxr-xr-x   3 root root  4096 Jul 19 13:48 locale
drwxr-xr-x   2 root root 12288 Dec  2 11:03 sbin
drwxr-xr-x 295 root root 12288 Jul 27 08:58 share
drwxr-xr-x   6 root root  4096 Dec  1 11:39 src
julien@ubuntu:~/c/shell$ >
</pre></code>
<h1>Creating processes</h1>
<hr>
<p>The system call <code>fork</code> (man 2 <code>fork</code>) creates a new child process, almost identical to the parent (the process that calls <code>fork</code>). Once <code>fork</code> successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.</p>
<pre><code>
julien@ubuntu:~/c/shell$ cat fork.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
julien@ubuntu:~/c/shell$ ./fork
Before fork
After fork
My pid is 4819
julien@ubuntu:~/c/shell$ After fork
My pid is 4820
</pre></code>
<i>Note: there is no typo in the above example</i>
<p>Using the return value of <code>fork</code>, it is possible to know if the current process is the father or the child: <code>fork</code> will return 0 to the child, and the PID of the child to the father.
<pre><code>
julien@ubuntu:~/c/shell$ cat fork.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    if (child_pid == 0)
    {
        printf("(%u) Nooooooooo!\n", my_pid);
    }
    else
    {
        printf("(%u) %u, I am your father\n", my_pid, child_pid);
    }
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic fork.c -o fork
julien@ubuntu:~/c/shell$ ./fork
My pid is 4869
(4869) 4870, I am your father
julien@ubuntu:~/c/shell$ My pid is 4870
(4870) Nooooooooo!
</pre></code>
<h1>Wait</h1>
<hr>
<p>The <code>wait</code> system call (man 2<code> wait</code>) suspends execution of the calling process until one of its children terminates.</p>
<pre><code>
julien@ubuntu:~/c/shell$ cat wait.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
        sleep(3);
    }
    else
    {
        wait(&status);
        printf("Oh, it's all better now\n");
    }
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic wait.c -o wait
julien@ubuntu:~/c/shell$ ./wait
Wait for me, wait for me
Oh, it's all better now
julien@ubuntu:~/c/shell$
</pre> </code>
<h1>Exercise: fork + wait + execve</h1>
<p>Write a program that executes the command <code>ls -l /tmp</code> in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.</p>
