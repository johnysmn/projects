SELECT DISTINCT name
FROM people
WHERE NOT name = 'Kevin Bacon'
AND id IN
(SELECT DISTINCT people.id
FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN
(SELECT movie_id
FROM stars
WHERE person_id IN
(SELECT id
FROM people
WHERE name = 'Kevin Bacon'
AND birth = 1958)));
