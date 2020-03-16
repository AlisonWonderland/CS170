# Todo
* Print out for program
* build 1-nn
* test out nn with sample
* how to read in data
* normalizing values
* validator
* implent forward selection first

# implementation thoughts
maybe use dataset and feature objects. or create feature vector in the main code.
For validator(maybe attach the knn algo to it), keep track of the features being used, pass them through run the nn algo on them, after being done, add percentages to a vector, keep track of the best percents at each level(one feature, two feature...), maybe add search algo to the validator  
Pass the dataset into dataset object, read file in the constructor(pass in file name as argument). Create a vector of the columns.

# high level
go trhough  dataset/feature objects and then assign it a class then check prediction.

## To compile
```
g++ -std=c++11 main.cpp knn.cpp Validator.cpp
```