# Write your MySQL query statement below
update salary set sex =
    case when sex ='m' THEN 'f'
    else 'm'
    END;