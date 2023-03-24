# Push_Swap: A Sorting Algorithm | 42

## Overview

This project consists in **sorting a list of integers** in the most optimal way. At the beginning, the numbers are contained in a stack A and they can be moved in a stack B to perform the sorting operations.

Several moves are available and it is up to us to use them in the best way:

- **swap A**: swap the first two elements of stack A.
- **swap B**: swap the first two elements of the stack B.
- **rotate A**: the first element of the stack A becomes the last one.
- **rotate B**: the first element of stack B becomes the last one.
- **rotate stack A and B**.
- **reverse rotate A**: the last element of stack A becomes the first one. 
- **reverse rotate B**: the last element of stack B becomes the first one. 
- **reverse rotate A and B**.

The movements are then printed on the standard output to count them. The idea is to have as few as possible.

## Algorithm and strategy

### Prerequisites

First, I look for the longest unsorted sequence in stack A. I keep it in stack A and move the rest to stack B. I keep it in stack A and move the rest to stack B. If there is no sorted sequence, I keep 3 numbers in stack A and move all the rest to stack B. Then I sort the 3 numbers using a homemade algorithm.

### Algorithm

After that, I create a **temporary stack** and copy the stack B to it. I then perform **quicksort algorithm** via recursive calls. This allows me to retrieve the indexes of each of the numbers, in ascending sort order. So I already know what the final sort order is.

So I go through the stack B and, for each element, I **calculate the number of moves** needed to place it correctly in the stack A. Once I have all the total moves, I move the one that needs the least moves in the stack A, to its final position. This way, the A stack will remain sorted despite each addition.

**Double moves** (rotate stack A and B, reverse rotate stack A and B) are essential to reduce moves and should be taken into account when calculating moves to move into stack A.

## Performance
On average:

- 3 numbers: 2 moves.
- 5 numbers: 8 moves.
- 100 numbers: 608 moves.
- 500 numbers: 5500 moves.

## Testing

I created a little tester to help you validate the project and test your sorting algorithm:

https://github.com/julien-ctx/push-swap-tester
