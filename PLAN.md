[Helpful Guide](https://hackernoon.com/lets-build-a-linux-shell-part-i-bz3n3vg1)

# Target Features for the MVP
- Basic shell loop
    - [x] read, eval, print loop
    - [x] command parsing (split on whitespace)
    - [x] execute commands
        - [x] process forking
        - [x] pass execution of commands to the os
    - [ ] simple builtin commands
        - [ ] exit
        - [x] help
        - [x] cd
    - [ ] Error handling
        - [ ] print error messages
        - [ ] exit with error code
    - [ ] Signal handling
    - [ ] history
        - [ ] store history
        - [ ] recall history
    - [ ] key input
        - [ ] navigate history with arrow keys
        - [ ] tab completion

# Program Structure
- [ ] REPL (shell loop)
    - [ ] read
    - [ ] eval
    - [ ] print
- [ ] Scanner (lexer)
    - [ ] Tokenizer
- [ ] Parser
    - [ ] Input Parsing
    - [ ] Word Expansion
    - [ ] AST
- [ ] Executor
    - [ ] I/O Redirection
    - [ ] Builtin Execution
    - [ ] External Command Execution
        - [ ] Process Management (fork, exec, wait)
- [ ] Symbol Table
    - [ ] Environment Variables
    - [ ] Shell Variables
    
