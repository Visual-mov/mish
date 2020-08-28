# mish
mish (Mini-shell), is a simplistic Unix shell written in C.

Currently still under development

## Install
Clone repo and compile:
```
~$ git clone https://github.com/Visual-mov/mish
~$ cd mish
~$ make
```

## Planned features
List of all planned features for mish:
- [ ] Add escape space escape character for file & folder names with spaces.
- [ ] Allow for the execution of multiple commands with `&&` operator.
- [ ] Add command redirection operator.
- [ ] Keep command history and add 'history' builtin.
- [ ] Allow for cycling through command history with up & down arrow keys.
- [ ] Add shortcuts (same as alias).

## Builtins
The following is a list of all built-in mish commands:
```
help - Prints mish help.
exit - Quits the shell.
cd   - Change directory (cd.. to move up).
```