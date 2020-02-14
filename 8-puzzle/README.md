# 8-puzzle
start with 4-puzzle
generate a tree.
add nodes that are available, check for dupes, if for one node there is a dupe, don't create child, if there is two dupes, then stop expanding, return null?

Test out the tree first

thoughts:
generate tree in algo?
keep fronteir and visited in algo
NO VECTOR FOR CHILDREN?
visited should be keep track of the vectors, vector of vectors.
## Todo 
* write tree generation code first
* Solve it without using node
* Maybe create a state class(Problem) to store the state of the puzzle
* Node could contain the state
* Algorithm classes focus on Uniformed first
* Ask on piazza what we should print out. Like the states being expanded until the solution.

## pseudoccode
```
Create new puzzle
Initialize node with this init puzzle
Create a tree with this init node as root.
In the algo add it to frontier, then visited as we expand. add a visited check
if expansion/ legal operations create children add them to frontier and tree. repeat this and previous line, until no more in frontier.
```