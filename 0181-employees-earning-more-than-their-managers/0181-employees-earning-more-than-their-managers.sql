SELECT
e.name as Employee
FROM Employee e
WHERE e.salary > (
    SELECT m.salary 
    FROM Employee m
    WHERE m.id = e.managerId
);