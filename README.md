# Implementing-Knapsack
In this assignment, you are asked to design and implement algorithms for 0-1 Knapsack  Problem and 0-1 Multiple Knapsack Problem.  
Problem 1: 0-1 Knapsack problem is a well-known combinatorial optimization problem:  Given a set of n items, 𝑁 = {1,2, … , 𝑛}, each with a weight wi and a value vi, determine the  subset of these items to include in a knapsack, so that weight is less than or equal to the  capacity (W) of knapsack and the total value is as large as possible. 
Formally:  Maximize ∑ 𝑣𝑖𝑥𝑖 𝑛 𝑖=1  // The objective is to maximize total value in the knapsack Subject to ∑𝑛 𝑖=1 𝑤𝑖𝑥𝑖 ≤ 𝑊 // You cannot exceed capacity of the knapsack 𝑥𝑖 = {0,1}. // 𝑥𝑖 is equal to 1 if item i is included, and zero otherwise. Problem 2: 0-1 Multiple Knapsack problem is an extension of Knapsack Problem, where  we have m knapsacks, 𝑀 = {1,2, … , 𝑚}, each with capacities Wj . 
Formally:  Maximize ∑ ∑ 𝑣𝑖𝑥𝑖,𝑗 𝑛 𝑖=1 𝑚 𝑗=1  // The objective is to maximize total value in all knapsacks Subject to: ∑𝑛 𝑖=1 𝑤𝑖𝑥𝑖,𝑗 ≤ 𝑊𝑗 ∀𝑗 ∈ 𝑀 //None of the knapsacks can exceed their capacity ∑ 𝑥𝑖,𝑗 ≤ 1 𝑚 𝑗=1  ∀𝑖 ∈ 𝑁 // Each item can be included in only one knapsack 𝑥𝑖,𝑗 = {0,1} // 𝑥𝑖,𝑗 is equal to 1 if item i is included in knapsack j. Project Specification: Your team (up to 2 students) is asked to design and implement an algorithm for both knapsack  problems (Problem 1 and Problem 2). Since Knapsack problem is an NP-hard problem, it is difficult to find optimal solutions  especially for large instances. Your goal is not to design an algorithm for the optimal solution,  but you are requested to do your best. You may do the following:  Read as much as you want to learn about how to solve the (multiple) Knapsack  problem. But you have to cite any resources you use. You may want to start with  some approximation algorithms (such as local search heuristics) in chapter 12.   You may use whichever programming language you want.You may not use the following:  Existing implementations or subroutines  Extensive libraries (if you are not sure, check with the instructor)  Other people’s code. Input format for Problem 1: Inputs will always be given to you as a text file. Input file  format should be as following: n W v1 w1 v2 w2 : : vi wi : : vn wn No other input format will be accepted!  n: number of items W: knapsack capacity vi: value of item i wi: weight of item i Output format for Problem 1: Output should be a text file including following: Total_Value x1 x2 : xi : xn First line should include Total_Value which is the sum of the values of items included in the  knapsack. Next lines include zeros and ones. No other output format will be accepted! Input format for Problem 2: For multiple knapsack problem, input file format should be as  following: n m W1 W2 .. Wm v1 w1 v2 w2 : : vi wi : : vn wn m is the number of knapsacks and Wj is the capacity of j’th knapsack. Output format for Problem 2: Total_Value x1,1 x1,2 ... x1,m x2,1 x2,2 ... x2,m : xi,1 xi,2 ... xi,m : xn,1 xn,2 ... xn,m Example instances: You may find example instances in the web site. There are four example  inputs (sample1a.dat, sample1b.dat, sample1c.dat and sample1d.dat) for Problem 1 and one  example input (sample2a.dat) for problem 2. The optimal values are given in the following  table: Input File Optimal Solution Sample1a.dat 35 Sample1b.dat 2,397 Sample1c.dat 54,503 Sample1d.dat 90,204 Sample2a.dat 333 Outputs for optimal solutions are also available for Sample1a.dat and Sample2a.da
