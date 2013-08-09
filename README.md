# node-getcpids

Given a (parent) process ID, getcpids will return an array of child
process IDs.

```js
  var getcpids = require('getcpids');

  var cpids = getcpids(parent.pid);
```

Came across a situation recently when spawning an instance of a
program with pty.js, the process id was available but child process
IDs of the program weren't. When the binary finished it left the child
processes orphaned which can take a while to expire. Writing
getcpids (which loops from 0 - 32767 calling getpgid) creates and
returns an array of child process IDs which could be used to kill the
orphans after the parent process ended.
