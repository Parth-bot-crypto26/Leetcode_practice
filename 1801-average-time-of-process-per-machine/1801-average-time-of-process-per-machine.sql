# Write your MySQL query statement below
WITH ProcessDurations AS (
  SELECT
    machine_id,
    process_id,
    -- Get the 'end' timestamp for this process
    MAX(CASE WHEN activity_type = 'end' THEN timestamp END) -
    -- Get the 'start' timestamp for this process
    MAX(CASE WHEN activity_type = 'start' THEN timestamp END) AS duration
  FROM
    Activity
  GROUP BY
    machine_id,
    process_id
)
/*
  Now, we average the durations for each machine
  and round to 3 decimal places.
*/
SELECT
  machine_id,
  ROUND(AVG(duration), 3) AS processing_time
FROM
  ProcessDurations
GROUP BY
  machine_id
ORDER BY
  machine_id;