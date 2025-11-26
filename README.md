### Better(propably) Shuffling algorithm for Spotify(?)
The app allows the user to alter the propability of every song popping up earlier in the queue.
The algorithm is still heavily based on randomness, unlike the spotify shuffle, whitch is based on a popularity.

### Main.cpp
## Tracklist class
The songs (represented by indexes for now) are added with their weight by the tracklist vector.
# TLtoQL
In the qList vector, the indexes are written out based on weight (weight = amount of times the song is written into qList).
# Shuffle
Here the shuffling happens by choosing a random index from qList, deleting other iterations of the same song to avoid duplicates, and adding it to queue.
## main class
# Display
Displays the current 'playing song'
# Start
Depending on if users turns the shuffle on or off, initiates TLtoQL, or fills the queue with the ordered tracklist
# main
Allows to turn shuffle on or off, then displays the current song. Then asks user for next action, Next/Previous/Exit.
