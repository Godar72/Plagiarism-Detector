# DSA in C Based Plagiarism Detector

## Overview
Plagiarism Detector is a high-performance command-line tool written in C designed to analyze multiple source files and documents to detect similarity. Unlike simple string matching, this tool uses structural analysis to identify overlapping content, making it effective even if whitespace or formatting is modified.

It supports C source code files natively and includes integration with pdftotext to enable the comparison of PDF documents.

## Key Features
1. Multi-Format Support: Capable of analyzing raw .c code files and .pdf documents (via pdftotext integration).
2. High Efficiency: utilizes advanced Quick Sort and Binary Search algorithms to handle comparisons rapidly.
3. Noise Filtering: Automatically normalizes text by removing comments, extra whitespace, and case differences.

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
  pdftotext.exe (for any pdf files)

  ### Compilation
  To compile the project, run the following command in your terminal:
  
  gcc -o PlagiarismDetector PlagiarismDetector.c

  ### Running the Detector
  Pass two or more C files as arguments to compare them:
  
  PlagiarismDetector file1.cpp file2.cpp
  PlagiarismDetector file1.pdf file2.pdf

  ## How It Works
  1. File Conversion: If a file is a PDF, the tool invokes pdftotext to extract raw text content.
  2. Normalization: The text is normalized (removing noise, comments, and converting to lowercase).
  3. Tokenization & Sorting: The normalized text is split into "windows" and sorted using Quick Sort.
  4. Comparison: The tool utilizes Binary Search to find intersections between the documents and calculates a similarity percentage.
