# Minishell

Minishell is a simplified UNIX shell developed as part of the 42 school curriculum.
It reproduces basic behavior of bash, including command execution, redirections, pipes, built-in functions, and environment variable handling.

## 📦 Features

- Prompt display with readline
- Execution of system commands (`ls`, `cat`, etc.)
- Built-in commands: `cd`, `echo`, `pwd`, `exit`, `env`, `export`, `unset`
- Input/output redirections: `<`, `>`, `>>`, `<<`
- Pipes: `ls | grep .c | wc -l`
- Environment variable expansion: `$HOME`, `$USER`, `$?`
- Signal handling: `Ctrl+C`, `Ctrl+D`, `Ctrl+\`
- Error handling and memory management

## ⚙️ Compilation

```bash
make

┌───────────────────────────────┐
│        User Input Line        │
│ e.g., echo "Hello $USER" > f  │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│        Lexical Analysis       │
│ - Split input into tokens     │
│ - Handle quotes and escapes   │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│       Token Classification    │
│ - Identify command, args,     │
│   pipes, redirections         │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│     Variable Expansion        │
│ - Replace $VAR with its value │
│ - Handle special vars like $? │
│ - Respect quote rules         │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│      Redirection Handling     │
│ - Identify >, <, >>, <<       │
│ - Set up file descriptors     │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│        Pipe Handling          │
│ - Identify '|' tokens         │
│ - Set up inter-process pipes  │
└──────────────┬────────────────┘
               │
               ▼
┌───────────────────────────────┐
│     Command Execution Loop    │
│ - For each command segment:   │
│   - Fork process              │
│   - Apply redirections/pipes  │
│   - Execute command           │
└───────────────────────────────┘


