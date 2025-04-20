# Wordle in CPP

Welcome to the **Wordle in CPP**, a terminal-based implementation of the popular word-guessing game!

## Features

- **Random Word Generation**: Words are picked randomly from a `validwords.txt` file.
- **Input Validation**: Checks if the guessed word is valid (exists in the dictionary) and ensures the word hasn't already been tried in the same turn.
- **Color-Coded Feedback** for Guesses:
  - 🟩 Green: Correct letter in the correct position.
  - 🟨 Yellow: Correct letter in the wrong position.
  - 🟥 Red: Incorrect letter.
- **Game Statistics**: Track your performance with the number of correct and wrong guesses.
- **Replay Option**: Play multiple rounds and see your stats improve.

## How to Play

1. The game will pick a random 5-letter word.
2. You have **6 attempts** to guess the word.
3. After each guess:
   - The program ensures your guess is a valid word from the dictionary.
   - It also verifies that you haven't repeated the same guess in the current round.
   - You'll then receive feedback with color codes for each letter:
     - 🟩 indicates the letter is correct and in the right position.
     - 🟨 indicates the letter is correct but in the wrong position.
     - 🟥 indicates the letter is incorrect.
4. If you guess the word correctly, you win! Otherwise, the correct word will be revealed after 6 attempts.

## User Stats

- After each game, you can choose to view your statistics:
  - Number of correct guesses.
  - Number of wrong guesses.
  - Detailed guess patterns with 🟩 for each correct guess.

## File Dependencies

The game depends on a file named `validwords.txt`, which should contain a list of valid 5-letter words separated by spaces or newline characters.

## Usage

1. Compile the program using a C++ compiler, for example:
   ```bash
   g++ -o wordle project.cpp
   ```
2. Run the executable:
   ```bash
   ./project
   ```
3. Follow the prompts to play the game.

## Code Overview

### Key Functions

- `randomwordpicker()`: Picks a random word from `validwords.txt`.
- `validword(string s)`: Checks if a word exists in the `validwords.txt` file.
- `alreadymade(string s, set<string> p)`: Ensures the guessed word hasn't been repeated in the same round.
- `genstring(string s, string t)`: Generates a result string to indicate guess accuracy.
- `colourstring(string s, string t)`: Displays the feedback with colors.
- `generatepattern(const vector<string> &patterns)`: Displays the pattern of guesses.
- `printstats(vector<int> stats)`: Prints statistics in a visual format.

### Game Logic

- The game loops until the player decides to quit.
- Each round consists of:
  1. Picking a random word.
  2. Taking up to 6 guesses from the user.
  3. Validating each guess (checks if it’s a valid word and hasn’t been guessed before).
  4. Providing feedback for each guess.
  5. Displaying the result and statistics.

## Example Gameplay

```
Welcome to Wordle
Enter a 5 Letter Word to Guess: adieu
Guess 1: 🟨⬜⬜⬜⬜
Enter a 5 Letter Word to Guess: party
Guess 2: 🟩🟩🟨⬜⬜
Enter a 5 Letter Word to Guess: paste
Guess 3: 🟩🟩🟩⬜⬜
Enter a 5 Letter Word to Guess: paske
Not a valid word !!
Enter a 5 Letter Word to Guess: passe
Guess 4: 🟩🟩🟩🟨⬜
Enter a 5 Letter Word to Guess: pased
Not a valid word !!
Enter a 5 Letter Word to Guess: paser
Not a valid word !!
Enter a 5 Letter Word to Guess: pasre
Not a valid word !!
Enter a 5 Letter Word to Guess: passr
Not a valid word !!
Enter a 5 Letter Word to Guess: paser
Not a valid word !!
Enter a 5 Letter Word to Guess: pasor
Not a valid word !!
Enter a 5 Letter Word to Guess: pasar
Guess 5: 🟩🟩🟩🟩🟩
Correct guess !! 
Wordle Result: 
5/6
🟨⬜⬜⬜⬜
🟩🟩🟨⬜⬜
🟩🟩🟩⬜⬜
🟩🟩🟩🟨⬜
🟩🟩🟩🟩🟩

Display User Stats?
(Y for yes,N for no)
y
USER STATS: 
No of Right Guesses: 3
No of Wrong Guesses: 2
1|0
2|0
3|0
4|🟩1
5|🟩1
6|🟩1
```

---

## Notes

- Ensure `validwords.txt` is in the same directory as the compiled executable.
- The program uses ANSI escape codes for colored output, which may not work on all terminals. For best results, use a modern terminal emulator.

---
