# CS-210 Programming Languages Portfolio

## Project Overview

This project was created for CS-210 at Southern New Hampshire University. The Corner Grocer Item Tracker is a C++ program designed to help a grocery store analyze how frequently items are purchased. The program reads grocery item data from an input file and allows the user to search for individual items, display the frequency of all items, and view a histogram of item purchases.

## Project Files

- CornerGrocer.cpp - Contains the C++ source code for the program.
- CornerGrocer.sln - Visual Studio solution file.
- CornerGrocer.vcxproj - Visual Studio C++ project file.
- CS210_Project_Three_Input_File.txt - Input data containing grocery items.
- frequency.dat - Data file used to store item frequency information.
- README.txt - Original project documentation.

## Reflection

### 1. Summarize the project and the problem it was solving.

The Corner Grocer Item Tracker solves the problem of determining how frequently grocery items are purchased. It reads item names from a text file, counts how often each item appears, and provides a menu that allows the user to search for a specific item, view all item frequencies, or display a text-based histogram. This makes the information easier to understand and can help a grocery store identify popular items.

### 2. What did you do particularly well?

I did well at organizing the program into a class and creating a menu that gives users clear options. I used a map to keep track of item frequencies and implemented the search, frequency listing, and histogram features. I also tested the program in Visual Studio to confirm that the menu and its features worked as expected.

### 3. Where could you enhance your code, and how would those improvements make it more efficient, secure, or adaptable?

I could improve the program by adding more error handling for missing or incorrectly formatted input files and invalid user entries. I could also improve input validation and make the program more flexible by allowing the input and output file names to be configured. These changes would make the program more reliable, easier to maintain, and more useful in different situations.

### 4. What was the most challenging part of the code to write, and how did you overcome it?

One challenging part of this project was getting the program set up and running correctly in Visual Studio. I had to work through a project toolset configuration issue before I could successfully build and test the program. I overcame this by troubleshooting the project settings and testing the program again. This helped me understand the importance of checking both the source code and the development environment when solving programming problems.

### 5. What skills from this project will be particularly transferable to other projects or course work?

The skills I developed include using C++, working with classes and maps, reading data from files, writing output to files, validating user input, and testing a program. I also gained experience troubleshooting build configuration issues in Visual Studio. These skills can be applied to future programming projects and other software development tasks.

### 6. How did you make this program maintainable, readable, and adaptable?

I made the program more maintainable by organizing its functionality within a class and separating the different menu operations into distinct tasks. Meaningful variable and function names help make the code easier to follow, and comments help explain important parts of the program. Using a map to store item counts also makes it straightforward to look up and display item frequencies. These choices make the program easier to understand and provide a foundation for future improvements.

## Technologies Used

- C++
- Microsoft Visual Studio
- File input and output
- Maps and frequency counting

## Author

Adam Sir

Southern New Hampshire University

CS-210: Programming Languages
