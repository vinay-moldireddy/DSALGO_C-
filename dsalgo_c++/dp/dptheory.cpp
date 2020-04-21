overlapping subproblems 
optimal substructure 

example: 
In febinocci series problem 
Non dp method we use f(n)=f(n-1)+f(n-2)  recursive function.
					complexity is O(2^n) which is bad  space complexityis O(n)
using DP method 	complexity is O(n)  
				since there are overlapping subproblems in febinocci problem

				we have top down and  bottom up apporach 

				we add memory to store overlapping subproblems


		space optimisation in bottom up method;
			we need not store entire array 
			we can maintain only two values that need to  sum up 