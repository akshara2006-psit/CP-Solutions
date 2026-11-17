# Write your MySQL query statement below
select distinct num AS ConsecutiveNums
from Logs
where (id + 1, num) IN (select id, num from Logs)
  and (id + 2, num) IN (select id, num from Logs);
