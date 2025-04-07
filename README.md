# 42_pipex
Project developed during the Common Core @ 42 Porto

## Pipex

### Summary:
This project will let you discover in detail a UNIX mechanism that you already know by using it in your program.

## 🛠️ Usage

### Requirements

The project is written in C language and needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the project**

To compile the project, go to its path and run:

For all mandatory functions:

```shell
$> make
```

For bonus functions:

```shell
$> make bonus
```

**2. Using it in your terminal**

It should be executed in this way:

```shell
$> ./pipex file1 cmd1 cmd2 file2
```
'file1' and 'file2' are file names, 'cmd1' and 'cmd2' are shell commands with their parameters.

The execution of the pipex program should do the same as the next shell command:

```shell
$> < file1 cmd1 | cmd2 > file2
```
