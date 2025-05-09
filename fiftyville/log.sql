-- I've searched for the descriptions of the crime_scene_reports.
SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND year = 2024
AND street = 'Humphrey Street';

-- With the descriptions, i've searched for transcripts and names of the people who were at the crime scene.
SELECT id,name,transcript
FROM interviews
WHERE year = 2024
AND month = 7
AND day = 28;

 -- Eugene said that saw the thief withdrawing money at that day and i've searched for the atm_transactions.
SELECT *
FROM atm_transactions
WHERE year = 2024
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street';

-- Searching every person's id by the account_number.
SELECT *
FROM bank_accounts
WHERE account_number IN
(SELECT account_number
FROM atm_transactions
WHERE year = 2024
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street');

-- I've searched for phone calls at that day, Raymond said that it was a calling on that day from that thief that it duration was less than 1 minute.
SELECT *
FROM phone_calls
WHERE month = 7
AND day = 28
AND year = 2024
AND duration < 60;

-- Searching every information from the results of bank_accounts.
SELECT *
FROM people JOIN bank_accounts
ON people.id = bank_accounts.person_id
WHERE account_number IN
(SELECT  account_number
FROM atm_transactions
WHERE year = 2024
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street');

--Keeping track from the activities of that especific day.
SELECT bk.*, name
FROM bakery_security_logs bk
JOIN people p
ON bk.license_plate = p.license_plate
WHERE day = 28
AND month = 7
AND year = 2024
AND activity = 'exit'
AND bk.license_plate IN
(SELECT license_plate
FROM people JOIN bank_accounts
ON people.id = bank_accounts.person_id
WHERE account_number IN
(SELECT  account_number
FROM atm_transactions
WHERE year = 2024
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street'));

--I've found Fiftyvilles' id = 8.
SELECT *
FROM airports;

--Catching any information from the flight that would've been on the next day.
SELECT *
FROM flights
WHERE day = 29
AND month = 7
AND year = 2024
AND origin_airport_id = 8;

--Using join to acces the passengers' informations. Combining every single date and i've figured out that
--the thif is: Bruce! And the city the thief escaped to was New York!
SELECT DISTINCT pl.*, ai.city
FROM flights f
JOIN passengers p
ON f.id = p.flight_id
JOIN people pl
ON pl.passport_number = p.passport_number
JOIN phone_calls ph
ON ph.caller = pl.phone_number
JOIN bakery_security_logs bk
ON bk.license_plate = pl.license_plate
JOIN bank_accounts ba
ON ba.person_id = pl.id
JOIN atm_transactions at
ON at.account_number = ba.account_number
JOIN airports ai
ON f.destination_airport_id = ai.id
WHERE f.day = 29
AND f.month = 7
AND f.year = 2024
AND origin_airport_id = 8
AND duration < 60
AND bk.day = 28
AND bk.month = 7
AND bk.year = 2024
AND activity = 'exit'
AND bk.hour = 10
AND bk.minute BETWEEN 10 AND 30
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street'
AND destination_airport_id = 4;

--Serching the accomplice's number.
SELECT *
FROM phone_calls
WHERE caller = '(367) 555-5533'
AND year = 2024
AND month = 7
AND day = 28
AND duration < 60;

--The accomplice is Robin!
SELECT *
FROM people
WHERE phone_number = '(375) 555-8161';

