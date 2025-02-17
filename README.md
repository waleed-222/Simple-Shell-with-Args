### **Simple Shell in C**  

A basic shell implementation in C that can execute commands with arguments using **fork()** and **execvp()**. It also provides error handling for invalid commands.  

## 🚀 **Features**  
✅ Supports commands with arguments (`ls -al`, `free -h`, etc.)  
✅ Uses `fork()` to create child processes  
✅ Executes commands with `execvp()`  
✅ Handles invalid commands and displays appropriate error messages  
✅ Displays process exit status (`0` for success, `256` for failure)  

## 🛠 **How to Compile and Run**  

1. **Compile the program:**  
   ```sh
   gcc simple_shell.c -o simple_shell
   ```
2. **Run the shell:**  
   ```sh
   ./simple_shell
   ```

## 🖥 **Example Usage**  

```sh
> ls -al
> free -h
> cat main.c
> htop
> wrong_command  # Invalid command test
```
📌 Valid commands return `status: 0`  
📌 Invalid commands return `status: 256` (Error: No such file or directory)  

## 🔧 **How It Works**  
1. Reads user input (`fgets()`).  
2. Tokenizes the command and its arguments (`strtok()`).  
3. Creates a child process (`fork()`).  
4. Executes the command in the child process (`execvp()`).  
5. Waits for the child process to complete (`waitpid()`).  

## 🏗 **Planned Improvements**  
- 🔜 Add support for **piping (`|`)**  
- 🔜 Implement **I/O redirection (`>`, `<`)**  
- 🔜 Improve command history feature  

## 🤝 **Contributing**  
Feel free to contribute by improving the code, adding new features, or optimizing performance.  

## 📜 **License**  
This project is open-source and free to use under the MIT License.  

