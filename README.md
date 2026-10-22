# -CPP-Games

A small collection of console-based C++ game projects built as standalone Windows applications. The repository currently includes:

- A math quiz game where the player answers arithmetic questions across different difficulty levels
- A rock-paper-scissors game played against the computer across multiple rounds

This project is ideal for beginners learning C++ fundamentals such as loops, conditionals, enums, structs, random number generation, and console input/output.

## Project overview

### 1. Math Game
The Math Game project generates random arithmetic questions and asks the user to solve them. It includes:

- difficulty selection: Easy, Medium, Hard, or Mixed
- operation selection: Addition, Subtraction, Division, Multiplication, or Mixed
- configurable number of questions
- score tracking for correct and incorrect answers
- replay option after each session

### 2. Rock, Paper, Scissor Game
The Rock, Paper, Scissor game is a classic console-based match against the computer. It includes:

- player choice input
- computer random choice generation
- round-by-round winner determination
- final match result summary
- replay option

## Repository structure

```text
-CPP-Games/
├── Math Game.cpp
├── Math Game.sln
├── Math Game.vcxproj
├── Math Game.vcxproj.filters
├── Math Game.vcxproj.user
├── Rock, Paper, Scissor, Game Project.cpp
├── Rock, Paper, Scissor, Game Project.sln
├── Rock, Paper, Scissor, Game Project.vcxproj
├── Rock, Paper, Scissor, Game Project.vcxproj.filters
├── Rock, Paper, Scissor, Game Project.vcxproj.user
├── newMathGane.cpp
├── newMathGane.sln
├── newMathGane.vcxproj
├── newMathGane.vcxproj.filters
├── newMathGane.vcxproj.user
├── README.md
└── x64/
```

Note: The project includes multiple Visual Studio solution files, so each game can be opened and run independently.

## Prerequisites

To build and run this project, you will need:

- Windows operating system
- Visual Studio 2019 or later
- Desktop development with C++ workload enabled
- A C++ compiler and MSVC toolchain

If you prefer using a terminal-based compiler, you can also compile the `.cpp` files with `g++` on a compatible environment.

## Installation

### Option 1: Using Visual Studio
1. Clone the repository:

```bash
git clone https://github.com/essmatx/-CPP-Games.git
```

2. Open the solution file (`.sln`) for the game you want to run, such as:
   - `Math Game.sln`
   - `Rock, Paper, Scissor, Game Project.sln`

3. In Visual Studio, restore NuGet dependencies if prompted (this project does not appear to require external packages).

4. Build the project:
   - Press `Ctrl + Shift + B`, or
   - Choose `Build > Build Solution`

5. Run the project:
   - Press `F5`, or
   - Choose `Debug > Start Debugging`

### Option 2: Compile from the command line
If you have a C++ compiler installed, you can compile a game directly. For example:

```bash
g++ "Math Game.cpp" -o math_game.exe
```

Then run:

```bash
math_game.exe
```

or:

```bash
g++ "Rock, Paper, Scissor, Game Project.cpp" -o rps_game.exe
rps_game.exe
```

## How to use the games

### Math Game
When you start the program:

1. Enter how many questions you want to answer
2. Choose the difficulty level
3. Pick the arithmetic operation type
4. Solve each displayed question by entering the answer
5. Review the final score and decide whether to play again

Example flow:

```text
How Many Questions do you want to Answer?
5
Please Enter The Question Level { [1] EasyLevel, [2] Hardlevel, [3] MidLevel , [4] Mix }
1
Please Enter Operation Type {[1] Add, [2] Sub, [3] Div, [4] Mult , [5] Mix} 
3
```

### Rock, Paper, Scissor Game
When you start the program:

1. Choose a move: `1` = Stone, `2` = Paper, `3` = Scissor
2. The computer chooses randomly
3. The winner for that round is determined using standard game rules
4. After all rounds, the overall winner is displayed
5. You can play another round by entering `Y` or `N`

## Learning value

This project demonstrates several beginner-to-intermediate C++ concepts, including:

- `iostream` for console I/O
- `cstdlib` and `ctime` for randomization and system calls
- arrays and loops
- `enum` types for game states and choices
- structs for storing game state and round data
- control flow for game logic and replay behavior

## Notes

- This repository is a learning/demo project rather than a production-ready game engine.
- The project uses Windows-specific console commands such as `system("cls")` and `system("color 2F")`, so it is best suited for Windows environments.
- There is no explicit license file in the repository, so reuse should be checked against the repository owner’s preferences.

## Contributing

This repository appears to be a personal collection of small game prototypes. If you want to extend it, you could add features such as:

- a start menu
- sound effects
- high-score tracking
- additional mini-games
- better input validation
- cross-platform support for Linux/macOS

## Summary

-CPP-Games is a lightweight C++ console game collection focused on simple, beginner-friendly gameplay.
It is especially useful for practicing C++ logic, user input, game loops, and randomization in a fun and approachable way.

---

If you want, I can also generate a more polished version of this README tailored to GitHub presentation style or add screenshots / gameplay examples.
