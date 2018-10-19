# filler

That's a player program to compete against other students (or bots given as examples) on the famous (or not) Filler board. The principle is simple: two players take on each other on a board, and take turns placing the piece that the master of the game (supplied in the form of a Ruby executable) gives them, earning points. The game stops as soon as a piece can no longer be placed.

###### Example of usage:

```
make
./filler_vm -f maps/map00 -p1 ./yzavhoro.filler -p2 players/hcao.filler
```

or 

```
./filler_vm -f maps/map00 -p1 ./yzavhoro.filler -p2 players/hcao.filler | sh visualisation/script.sh
```

to enable visualisation.

Enjoy!