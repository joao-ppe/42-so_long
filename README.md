<div align="center">
  <img src="https://i.imgur.com/eArSYVd.png" alt="SO_LONG">
</div>

<div align="center">
  <h1>Description</h1>
</div>
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.  
  
<div align="center">
  <img src="https://i.imgur.com/7tsij2e.png" alt="SO_LONG_1">
</div>

## Features:
- Player model evolves after collecting half of the collectibles, changing player animations when moving.
- Enemies (bonus part only) roam around the map randomly and if both player and enemy collide, a death animation is triggered and you lose the game.
- The map exit only unlocks after picking up all of the collectibles.
- Various animations.

<div align="center">
  <h1>How to play</h1>
</div>

### Step 1 / Clone the repository:

```bash
$ git clone git@github.com:jppcarvalho94/42-so_long.git
```

### Step 2 / Install Minilibx dependencies:

```bash
$ sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Step 3 / Compile the program:  

```bash
$ cd 42-so_long/
$ make
$ make bonus
```

### Step 4 / Run the program:
The map folder has some pre-configured maps for you to test the game environment.  
You're able to create a map of your own and the program will tell you if the map is valid or not, pointing the out the problem if it isn't.  

<details>
<summary>Click here for map creation tutorial.</summary>
  
Map Rules:  
It has to be a **rectangular closed map** (walls around) and there needs to be a valid way to collect the balls and to the exit.  
The map file extension has to be **'.ber'**.  
The map is composed by 5 elements:  
```
- '1' for walls;
- '0' for available floor;
- 'P' for Player starting position;
- 'E' for exit;
- 'C' for collectible;
```

Map example:
```
1111111111111111111
10000000000E0001C01
1011111100000101101
101C000101100001101
1011001101100P00001
1000000000000100111
10110011000C0000111
101000C1000110000C1
1011111100111100011
10C1000000000000111
1111111111111111111
```
</details>

<div align="center">
  <img src="https://i.imgur.com/wPFCswz.gif" alt="SO_LONG_GIF">
</div>

To run the program, you need to select a map from the existing ones or the one that you've created. For that, you need to put the it's filename, extension and directory.  
  
For *mandatory*:
```bash
$ ./so_long maps/map1.ber
```
For *bonus*:
```bash
$ ./so_long_bonus maps/map1.ber
```

To exit the game, just press 'ESC' on your keyboard or click the 'X' in the game window. **HAVE FUN!**

## Disclaimer:
This project's source code adheres to the standards of 42 School and it's norms rigorous coding practices:
```
- We refrain from using 'for,' 'do while,' 'switch,' 'case,' or 'goto' constructs.
- Each function has no more than 25 lines of code. 
- There's a maximum of 5 functions per file.
- Assignments and declarations are kept on separate lines unless the variable is declared as static.
- We ensure that no single function has more than 5 variables, promoting code simplicity and readability.
```
