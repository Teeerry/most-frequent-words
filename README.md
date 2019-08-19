# Most Frequent Words
Interview Question 2 for Shenzhen SinoSmart Digital Tech. Co. LTD.
Write a program for displaying the ten most frequent words in a file such that your program should be efficient in all complexity measures.
Requirement: C/C++.Submission: Source code and a document to describe your solution.

# Description
author: Terry

email:  terryluohello@qq.com

date:   2019-08-19 

This question can be solved with hash map and priority queue. My solution can be divided into hash map part and priority queue part. Time complexity is O(n).

## Hash map
Firstly, we create a hash map for the words in the file.
## Priority queue
Secondly, we iterate the hash map to create a priority queue with size = 10. For each word in the map, we pop the smaller one and push the larger one into the map. We keep update the queue until finish iterating. After iterating, the most 10 frequent words are in the priority queue.
## Test the solution
To test the solution, you can:
```
cd most-frequent-words
mkdir build
cd build
cmake ..
make
cd ..
./build/most_frequent_words test_file.txt
```
You can get the output from terminal window like this:
```
There are 15665 different words in this file.
The most ten frequent words are: 

  Words: Times
      in:  1324
    that:  1334
    they:  1445
       a:  1503
       I:  1570
      of:  2385
      to:  3077
     and:  3402
     the:  3936

Time elapsed :0.075574s
```