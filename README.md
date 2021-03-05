# Tic Tac Toe Game
* This game is Totaly based on C langauge 
* If you find any problem then raise an issue 

# How to play
* frist you will see an game bord where you will see some number (1 to 9).
* when you choose any number your cross (X) will apper at that place.
* After your choosing computer will choose any random place and put his Zero (O).

# Who is the winner 
* If before computer your three cross will be in straight line the you are the winner
* If before you computer three Zero will be in straight line then computer is the winner
* If you and computer unable to create a straight line with cross (X) or Zero (O) the game will be try

### For more Details [click Here](https://en.wikipedia.org/wiki/Tic-tac-toe).

## Strategy
A player can play a perfect game of tic-tac-toe (to win or at least draw) if, each time it is their turn to play, they choose the first available move from the following list, as used in Newell and Simon's 1972 tic-tac-toe program.

* Win: If the player has two in a row, they can place a third to get three in a row.
* Block: If the opponent has two in a row, the player must play the third themselves to block the opponent.
* Fork: Create an opportunity where the player has two ways to win (two non-blocked lines of 2).
* Blocking an opponent's fork: If there is only one possible fork for the opponent, the player should block it. Otherwise, the player should block all forks in any way that simultaneously allows them to create two in a row. Otherwise, the player should create a two in a row to force the opponent into defending, as long as it doesn't result in them creating a fork. For example, if "X" has two opposite corners and "O" has the center, "O" must not play a corner move in order to win. (Playing a corner move in this scenario creates a fork for "X" to win.)
* Center: A player marks the center. (If it is the first move of the game, playing a corner move gives the second player more opportunities to make a mistake and may therefore be the better choice; however, it makes no difference between perfect players.)
* Opposite corner: If the opponent is in the corner, the player plays the opposite corner.
* Empty corner: The player plays in a corner square.
* Empty side: The player plays in a middle square on any of the 4 sides.
