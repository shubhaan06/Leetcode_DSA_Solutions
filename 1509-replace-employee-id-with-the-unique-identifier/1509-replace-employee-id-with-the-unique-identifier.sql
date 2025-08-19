# Write your MySQL query statement below

SELECT EmployeeUNI.unique_id, employees.name
FROM employees
LEFT JOIN EmployeeUNI ON EmployeeUNI.id = employees.id;