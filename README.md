# SIMC Section C: Busy footbridge

![SIMC Logo](simc_logo.png)

This is a followup project after Singapore International Mathematics Challenge (SIMC) 2018 to calculate the numerical answers to Section C using programming.
The simulation is done using C++, while the analysis and graphs are done using Wolfram Mathematica.
Also, an analysis of Model 3 of the Champion Team's report (NUSH) was also done.

The problem statement may be found in SIMC_Part_C.pdf

A summary of the results as well as the derivations could be found in <insert file name>.

## Summary of Results
- Question 1
The model used is the polite and stubborn model, where a polite person must give way while a stubborn person does not give way.

- Question 2

- Question 3

- Question 4
The champion team's model involved k lanes instead of 2. For this part, I analysed the distribution of people along the k lanes 
by dividing the number of people ending at a lane over the total number of people. Except for small values of k, greater values 
of k always resulted in a spike in probability distribution in the 2nd and (k-1)th row (1-indexed) as compared to the rest of the rows. 
The 1st and kth row have the lowest probability distribution. Otherwise, the probability distribution is generally equal.

The figure below shows a graph of probability distribution against lane number when k = 10:
![Probability Distribution for k = 10](analysis/k10graph.png)