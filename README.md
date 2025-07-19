# 🎮 AI Tic-Tac-Toe Game (C++)

A terminal-based Tic-Tac-Toe game in C++ featuring an unbeatable AI opponent using the Minimax algorithm. Play against the computer and test your strategy!

## 🧠 Features

- Human vs AI mode
- Unbeatable AI with Minimax algorithm
- Clean 3x3 board display in terminal
- Input validation for smooth gameplay

## 🛠️ Tech Stack

- Language: C++
- Concepts Used: OOP, Recursion, Backtracking, Game Trees, Minimax

## ▶️ Build & Run

### 🔧 Prerequisites
- C++ compiler (g++)
- CMake (v3.10+ recommended)

### 🗂️ Folder Structure
```
AI-TicTacToe-Cpp/
├── CMakeLists.txt
├── main.cpp
├── TicTacToe.cpp
├── TicTacToe.h
└── bin/
```

### ⚙️ Steps
```bash
# Clone the repository
git clone https://github.com/your-username/AI-TicTacToe-Cpp.git
cd AI-TicTacToe-Cpp

# Create build directory
mkdir build && cd build

# Generate build files using CMake
cmake ..

# Build the project
make

# Run the executable
./bin/AI_TicTacToe
```

## 🧩 Minimax Logic

The AI uses the Minimax algorithm to evaluate all possible moves recursively and chooses the one that maximizes its chances of winning or forcing a draw.

## 📸 Screenshot
```
 X | O | X
-----------
 O | X |  
-----------
   |   | O
```

## 📝 License

This project is licensed under the MIT License.

## 👨‍💻 Author

- [Yash Agrawal](https://github.com/yashagrawal-dev)
