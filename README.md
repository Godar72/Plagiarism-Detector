# DSA in C Based Source Code Plagiarism Detector

## Overview
Plagiarism Detector is a high-performance command-line tool written in C that analyzes multiple source files to detect code similarity. Unlike simple string matching, this tool uses structural analysis to identify overlapping code sequences, making it effective even if whitespace or comments are modified.

It is designed for efficiency, utilizing advanced searching and sorting algorithms to handle file comparisons rapidly.

## Data Structures & Algorithms Used
This project demonstrates the practical application of several core Data Structures and Algorithms (DSA) concepts to solve a real-world problem:

1. Advanced Sorting (Quick Sort)
Application: To optimize the comparison process, the tool breaks the source code into overlapping "windows" (shingles) and sorts them using Quick Sort ($O(N \log N)$).
Benefit: Sorting the data pre-structures it, allowing for much faster retrieval than a linear scan.

2. Binary Search
Application: Instead of checking every possible match one by one (which would be slow), the tool uses Binary Search to instantly locate matching code fragments in the sorted dataset.
Benefit: This reduces the lookup complexity from Linear ($O(N)$) to Logarithmic ($O(\log N)$), drastically improving performance on larger files.

3. Two-Pointer Technique (Data Normalization)
Application: The normalize function utilizes a Two-Pointer approach to filter out comments, whitespace, and case differences in a single pass ($O(N)$).
Benefit: This creates a canonical representation of the code, ensuring that the detector focuses on the logic rather than the formatting.

4. Dynamic Memory Management
Application: The tool uses malloc and free to dynamically allocate memory for file buffers and pointer arrays.
Benefit: Allows the program to handle files of varying sizes efficiently without wasting RAM.

  ## Installation & Usage
  ### Prerequisites
  GCC Compiler (or any standard C compiler)

  ### Compilation
  To compile the project, run the following command in your terminal:
  gcc -o PlagiarismDetector PlagiarismDetector.c

  ### Running the Detector
  Pass two or more C files as arguments to compare them:
  PlagiarismDetector file1.cpp file2.cpp

  ## How It Works
  1. Read & Preprocess: The tool reads files into memory and normalizes them (removing noise like comments/spaces).
  2. Tokenization: It splits the normalized code into fixed-size "windows" of characters.
  3. Sort & Search: It sorts the windows of one file and uses binary search to find intersections with the second file.
  4. Scoring: It calculates a similarity percentage based on the number of matching windows versus the total code length.
