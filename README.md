# so_long

ℹ️ A small 2D Game made using the MiniLibX Graphics Library - Textures, sprites and tiles included.



so_long

🪄 Everything small is just a smaller version of something big

Index

What is so_long?

Requirements

How does it work?

Maps

Controls

How do I test it?
42 Cursus

Author

What is so_long?
The fifth project at 42 programming school. It's the first graphical project in the Cursus , we can choose between 3 options - FdF, Fractol and so_long - that in general cover different areas, but all 3 are graphical projects. The so_long consists of a top-down game, which we code from scratch using the MiniLibx graphical library. It involves a series of validations from the map that is passed as argument, checks to prevent memoy leaks, the game engineering, managing windows, events, sprites and maps.

Requirements
⚠️ The project must be written in accordance with the Norm

The Norm is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and to any project where it's specified. These are some of them:
Each function must be maximum 25 lines, not counting the function's own curly brackets.

Each line must be at most 80 columns wide, comments included.

A function can take 4 named parameters maximum.

You can't declare more than 5 variables per function.

You're not allowed to use: for , do...while , switch , case ,  goto  ,
ternary operators such as `?' and VLAs - Variable Length Arrays.
The norminette (as we call the norm at 42) is in python and open source.

Its repository is available at https://github.com/42School/norminette.

How does it work?
You'll be able to play once you install the MiniLibx features or if you're using one of the machines at 42.
MiniLibx git link for installation and building the lib and all requirements included in make file.

To play, first compile the project with make:

make

So, run ./so_long followed by the map:

./so_long maps/img2.ber	

You can parse any kind of map, as long as it respects the below rules:
The map must be a .ber file.

And can only contain these characters:

CHAR	OBJECT
1	Wall
C	Coin
E	Exit
P	Player
0	Floor
For bonus there's an extra character - which makes you lose once touch it.

CHAR	OBJECT

The map must be rectangular and surrounded by walls '1'.

The map must contain at least one exit, one collectible, and one starting position.

Check some examples in the folder maps.

As in maps/img2.ber:

This .ber file generates this map:


Controls
KEY	OBJECT
W or ⬆️	Move up
A or ⬅️	Move left
S or ⬇️	Move down
D or ➡️	Move para right
Q or Esc	Close the game
Use WASD or arrow keys to move.

After getting all the coin bags, the exit opens and you can escape downstairs.

You can close the game by Clicking on the red cross on the window’s frame, or pressing Q or Esc.

How do I test it?
To test the game itself it's recommendable to run it with some different maps and try things like:

Running into a wall and see if you're blocked or if the movements counter increase while you're stucked.

Go to the exit withou collecting all the coins.

Go through the same path at least one time.

Try to move with WASD.

Check if the window closes when clicking the red cross on window's frame, same with Esc.

Try to minimize the window and open it again.

Run the project with Valgrind to see if there's any memory leak.

To test the code in this repo Clone this repo and cd into it:

git clone [/so_long](https://github.com/snagulap/so_long)

cd so_long/
