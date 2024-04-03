A small terminal input based program of tic-tac-toe

to place an X or an O, type the coordinates of the location in the grid.

e.g


```
> ___
> ___
> ___
```

If it's O's turn:

```
< 0 0
```
will produce

```
> O__
> ___
> ___
```

Then, since it's now X's turn, 

```
< 1 1
```
will produce

```
> O__
> _X_
> ___
```

If it's out of bounds, or you try to input something in an filled location, the program will ask you to input a correct coordinate.
If something other than an integer is provided in input, the program will exit.

:)


Compile the program with 'g++-11 -std=c++20 -Wall -g', and just run it from the terminal
