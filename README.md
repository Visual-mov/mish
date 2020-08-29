# mish
mish (Mini-shell), is a minimalistic Unix shell written in C with the purpose of being easy to understand and use.

*Currently still under development*

If you have any insight or ideas feel free to add it and crate a pull request!

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
- [ ] Finish installation script for making default shell.
- [ ] Allow for the execution of multiple commands with `&&` operator.
- [ ] Add command redirection operator.
- [ ] Keep command history and add 'history' builtin.
- [ ] Allow for cycling through command history with up & down arrow keys.
- [ ] Add aliasing functionality.
- [ ] Make a neat logo `:D`

## Builtins
The following is a list of all built-in mish commands:
```
help - Prints mish help.
exit - Quits the shell.
cd   - Change directory (cd.. to move up).
```