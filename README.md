# Longest Compound Word : Impledge Assignment

## Problem Statement

Write a program that:
1. Reads provided files `(Input_01.txt and Input_02.txt)` containing alphabetically sorted words list (one word per line, no spaces, all lower case)

2. Identifies & display below given data in `logs/console/output file`

- longest compounded word  
- second longest compounded word  
- time taken to process the input file

Note: A compounded word is one that can be constructed by combining (concatenating) shorter words
also found in the same file
#### Input 01 
Input_01.txt is a small word list, consisting following words
bash
cat
cats
catsdogcats
catxdogcatsrat
dog
dogcatsdog
hippopotamuses
rat
ratcatdogcat 


#### Answer:

| Longest Compound Word      | ratcatdogcat   |
|-----------|-------------------|
| Second Longest Compound Word  | catsdogcats   |
| Time taken to process file Input_01.txt| 500 milli seconds |



## Approach 
#### Trie Implementation:

The program employs a Trie data structure to efficiently store and search for words. The `Node` structure represents each node in the Trie, featuring links to 26 characters (one for each lowercase letter) and a flag indicating whether it marks the end of a word. The `Trie` class, encapsulating the root node, provides essential methods for inserting, searching, and checking if a word starts with a given prefix.

#### Word Sorting and Input Reading:

To enhance the efficiency of compound word identification, the input words are initially sorted based on their lengths in ascending order. The program reads the input from a file, such as `Input_02.txt`, where each line contains a lowercase word. The sorted words are then stored in a vector for subsequent processing.

#### Breadth-First Search (BFS) Approach:

A BFS algorithm is employed to systematically explore and identify compound words. The sorted words are iterated through, inserted into the Trie, and potential compound words are discovered. For each word, the program identifies indices within the Trie where it ends, adds these compound words to a queue for further exploration, and continues the process until the queue is empty. This BFS approach ensures a systematic examination of compound word possibilities.

#### Determining Longest and Second Longest Compounded Words:

As the BFS proceeds, the program dequeues compound words and their remaining suffixes. It checks if the suffix can form additional compound words and adds them to the queue. Upon fully processing a compound word that has not been marked as visited, the program compares its length with the current longest and second-longest words, updating them accordingly. The final output includes the longest and second-longest compound words, along with the time taken to process the input file.

This structured solution design leverages Trie and BFS to efficiently identify compounded words, incorporating sorting for optimization. The systematic approach ensures comprehensive exploration, and the program outputs the desired information about the longest and second-longest compounded words, as well as the processing time.
## Instructions to run Program

1. Download/Clone Repository:
   - Begin by downloading or cloning the GitHub repository containing the code.

2. Set the Path in `readFile.cpp`:
   - Locate the `readFile.cpp` file in the repository.
   - Inside this file, set the path to the input file on your local machine. Find the line in the code resembling:
     ```cpp
     ifstream inputFile(".../Input_02.txt")`;
     
    - Replace this path with the path to your local input file.

3. Compile the Program:
   - Open your terminal or command prompt. Navigate to the directory where you have the C++ code files.
   - Compile the program using the `g++` command. The file name should be `LongestCompoundWord.cpp` or the name of the main C++ file you extracted from the downloaded repository. For example:
     ```bash
     g++ LongestCompoundWord.cpp     

4. *Execute the Program*:
   - After successfully compiling the program, run it by executing the compiled binary. On Windows, the binary might have an `.exe` extension. Run it using the following command:
     ```bash
     ./a.exe 
   - The program will display the longest, second-longest compound words and time taken to process the input file found in the provided input file.

You have successfully executed the Longest Compound Word Finder program. Enjoy exploring the results!
