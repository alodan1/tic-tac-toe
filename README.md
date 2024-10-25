Tic-Tac-Toe Game in C

This is a simple command-line-based Tic-Tac-Toe game implemented in C, where you can play against a computer.

**Features**:
  - A 3x3 grid Tic-Tac-Toe game.
  - Player uses X and the computer uses O.
  - Detects the winner or a tie.
  - Random computer moves.
  - Displays the game board after every move.

**Rules**:
  1) The game is played on a 3x3 grid.
  2) You are X, and your opponent (the computer) is O.
  3) Players take turns placing their marks (X or O) on the grid.
  4) The first player to get 3 of their marks in a row (horizontally, vertically, or diagonally) wins.
  5) If all 9 spaces are filled and no player has 3 in a row, the game ends in a tie.

**How to play:**
1) When prompted, enter the row and column number (1-3) to place your move.
2) The computer will then randomly place its move.
3) The game continues until a winner is found or the board is full, resulting in a tie.

**Requirements:**  
  A C compiler (like gcc). As well as a terminal or command prompt to run the game.

**How to compile and run:**
  - Clone or download this repository.
  - Open a terminal or command prompt in the directory where the file is located.
  - Compile the C program with the following command:
      - gcc -o tictactoe tictactoe.c
  - Run the program using:
      - ./tictactoe

