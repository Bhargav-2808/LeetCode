# Write your MySQL query statement below
(SELECT MAX(SALARY) AS SecondHighestSalary  from Employee WHERE SALARY != (SELECT MAX(SALARY) FROM Employee));