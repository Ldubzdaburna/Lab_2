# Lab_2
This project consists of two main components: the C++ source file `lab_2.cpp` and the corresponding test file `testLab2.cpp`. The project demonstrates an implementation of certain functions for checking conditions on lists of integers, and testing their correctness using the Doctest testing framework.

## Files

### 1. `lab_2.cpp`

This source file includes a C++ program that:

- Generates large numbers of lists each containing equal counts of 1s and -1s.
- Randomly shuffles these lists using the Fisher-Yates algorithm.
- Checks if a list is "well-balanced" – where the prefix sum is never negative or never positive.
- Computes and prints the proportion of well-balanced lists over a set number of trials.

**Functions in `lab_2.cpp`:**

- `bool non_neg_prefix_sum(const std::vector<int>& list)`: Checks whether the prefix sums of a list are all non-negative.
- `bool non_pos_prefix_sum(const std::vector<int>& list)`: Checks whether the prefix sums of a list are all non-positive.
- `void fisher_yates(std::vector<int>& list)`: Shuffles the elements of the list using the Fisher-Yates algorithm.
- `bool is_well_balanced(const std::vector<int>& list)`: Determines if a list is well-balanced by checking either of the two conditions above.

**Execution**: 
- The user is prompted to input the number of pairs `n`.
- The program simulates the generation of shuffled lists and checks for well-balanced ones over 10,000 trials.
- Outputs the proportion of these lists that are well-balanced.

### 2. `testLab2.cpp`

This file contains unit tests for the functions defined in `lab_2.cpp` using the Doctest framework. 

**Unit Tests:**

- `TEST_CASE("Testing non_neg_prefix_sum")`: Tests the `non_neg_prefix_sum` function with various cases, including both valid and invalid prefix sums.
- `TEST_CASE("Testing non_pos_prefix_sum")`: Tests the `non_pos_prefix_sum` function similarly.
- `TEST_CASE("Testing fisher_yates")`: Ensures that the `fisher_yates` function correctly shuffles the list without altering its elements.
- `TEST_CASE("Testing is_well_balanced")`: Tests the `is_well_balanced` function for various configurations of list entries.

## Installation and Usage

To compile and run the `lab_2.cpp` program:

```bash
g++ -std=c++11 -o lab_2 lab_2.cpp
./lab_2
```

To compile and run the `testLab2.cpp` unit tests:

```bash
g++ -std=c++11 -o testLab2 testLab2.cpp
./testLab2
```

Make sure you have the Doctest framework set up correctly in your environment to run these tests successfully.

## Dependencies

- C++11 or later
- Doctest testing framework for unit tests

## License

No specific license is provided in this README. Please refer to additional project documentation if available for licensing information.
