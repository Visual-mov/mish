# mish
mish (Mini-shell), is a simple Unix shell written in C for the purpose of learning and being easy to use. I also intend for it to be my personal shell.

*Currently still under development*

If you have any insight or ideas, feel free to add it and create a pull request!

## Install
Clone repo and compile:
```
~$ git clone https://github.com/Visual-mov/mish
~$ cd mish
~$ make
```

## Planned features
List of all planned features for mish:
- [ ] Add a space escape character for file & folder names with spaces.
- [ ] Finish installation script for making default shell.
- [ ] make code more modular
- [ ] Allow for the execution of multiple commands with `&&` operator.
- [ ] Keep command history and add 'history' builtin.
- [ ] Allow for cycling through command history with up & down arrow keys.
- [ ] Make a neat logo `:D`

## Builtins
The following is a list of all built-in mish commands:
```
help - Prints mish help.
exit - Quits the shell.
cd [path] - Change directory (.. to move up).
```