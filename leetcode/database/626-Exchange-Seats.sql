# Write your MySQL query statement below

select
    case when id = (select MAX(id) from Seat) then id else id + 1 end AS id,
    student
from Seat
where id % 2 = 1

UNION ALL

select
    id - 1 AS id,
    student
from Seat
where id % 2 = 0

order by id asc;
