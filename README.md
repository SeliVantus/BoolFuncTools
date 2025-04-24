BooleanFunction Library

This project implements a set of transformations and utilities for Boolean functions. It allows you to perform operations such as conversion to PDNF (Disjunctive Normal Form), ANF (Algebraic Normal Form), and calculate important properties like Hamming Weight, Autocorrelation, Nonlinearity, and Correlative Immunity.

Files Overview

  BooleanFunction.cpp / .h: Defines the BooleanFunction class that handles the Boolean function and provides methods to convert it to PDNF, ANF, and compute various properties like Hamming weight and autocorrelation.
  Transformations.cpp / .h: Contains the Transformations class with methods for Walsh-Hadamard transform, nonlinearity calculation, DDT (Difference Distribution Table), and LAT (Linear Approximation Table).
  Tests.cpp / .h: Implements the Tests class that runs various tests for Hamming weight, Walsh-Hadamard transform, DDT, and LAT.
main.cpp: Provides an example usage of the BooleanFunction class and the transformations. It demonstrates the functionality of converting a Boolean function, calculating its properties, and running tests. 

How to Use

Creating a Boolean Function: To create a Boolean function, initialize it with a vector of 0s and 1s representing the function's truth table.

               std::vector<int> f = { 0, 0, 1, 0 }; // Boolean function 
               BooleanFunction bf(f);

Tests

Note: The test values used in Tests.cpp are hardcoded.
If you want to test your own Boolean functions, you should manually modify the vectors inside the test methods (e.g., hammingWeightTest, walshTransformTest, ddtTest, latTest) to reflect your specific input.
