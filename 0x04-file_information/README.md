<h1>File information</h1>
<hr>
<p>The<code>stat</code> (man 2 stat) system call gets the status of a file. On success, zero is returned. On error, -1 is returned.</p>
<pre><code>
julien@ubuntu:~/c/shell$ cat stat.c
#include &lt;stdio.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;sys/stat.h&gt;
#include &lt;unistd.h&gt;

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
}
julien@ubuntu:~/c/shell$ ./stat ls /bin/ls /usr/bin/ls
ls: NOT FOUND
/bin/ls: FOUND
/usr/bin/ls: NOT FOUND
julien@ubuntu:~/c/shell$
</code></pre>
<h2>Exercise: find a file in the PATH</h2>
<p>Write a program that looks for files in the current <code>PATH</code>.
<ul><li>usage: <code>_which filename ...</code></li></ul>
