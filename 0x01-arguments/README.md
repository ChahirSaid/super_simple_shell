<h1>Arguments</h1>
<p>The command line arguments are passed through the <code>main</code> function: <code>int main(int ac, char **av);</code>
<ul><li><code>av</code> is a <code>NULL</code> terminated array of strings</li>
<li><code>ac</code> is the number of items in <code>av</code></li></ul>
<p><code>av[0]</code> usually contains the name used to invoke the current program. <code>av[1]</code> is the first argument of the program, <code>av[2]</code> the second, and so on.</p>
<hr>
<h1>Exercises</h1>
<h3>0. av</h3>
<p>Write a program that prints all the arguments, without using <code>ac</code>.
<h3>1. Read line</h3>
<p>Write a program that prints <code>"$ "</code>, wait for the user to enter a command, prints it on the next line.</p><p>man 3 <code>getline</code></p>
<p><em><b>important</b></em> make sure you read the man, and the RETURN VALUE section, in order to know when to stop reading Keyword: “end-of-file”, or <code>EOF</code>(or <code>Ctrl+D</code>).</p>
<h3>2. command line to av</h3>
<p>Write a function that splits a string and returns an array of each word of the string.</p>
<p>man <code>strtok</code></p>

