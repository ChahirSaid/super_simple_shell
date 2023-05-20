<h1>Exercises</h1>
<hr>
<h3>0. printenv with environ</h3>
<p>Write a program that prints the environment using the global variable <code>environ</code>.</p>
<h3>1. env vs environ</h3>
<p>Write a program that prints the address of <code>env</code> (the third parameter of the <code>main</code> function) and <code>environ</code> (the global variable). Are they they same? Does this make sense?</p>
<h3>2. getenv()</h3>
<p>Write a function that gets an environment variable. (without using <code>getenv</code>)</p>
<ul><li>Prototype: <code>char *_getenv(const char *name);</code></li></ul>
<p>man 3 <code>getenv</code></p>
<h3>3. PATH</h3>
<p>Write a function that prints each directory contained in the the environment variable <code>PATH</code>, one directory per line.</p>
<h3>4. PATH</h3>
<p>Write a function that builds a linked list of the <code>PATH</code> directories.</p>
<h3>5. setenv</h3>
<p>Write a function that changes or adds an environment variable (without using <code>setenv</code>).</p>
<ul> <li>Prototype: <code>int _setenv(const char *name, const char *value, int overwrite);</code></li></ul>
<p>man 3 <code>setenv</code></p>
<h3>6. unsetenv</h3>
<p>Write a function that deletes the variable name from the environment (without using <code>unsetenv</code>).</p>
<ul><li>Prototype: <code>int _unsetenv(const char *name);</code></li></ul>
<p>man 3 <code>unsetenv</code></p>
