-- Keep a log of any SQL queries you execute as you solve the mystery.
-- all i know is that the theift took place on July 28, 2020 and  Chamberlin Street
--get the description of the crime

SELECT id, description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2020 AND street = "Chamberlin Street";

-- SEARCH IN THE INTERVIEWS FOR INFORMATION
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2020;

-- check on the interview correctness
SELECT license_plate, hour, minute FROM courthouse_security_logs
WHERE day = 28 AND month = 7 AND year = 2020 AND activity = "exit";

-- check the ATM information
SELECT amount, account_number FROM atm_transactions
WHERE atm_location = "Fifer Street" AND transaction_type = "withdraw"
AND day = 28 AND month = 7 AND year = 2020;

-- check fot the flight
SELECT caller, receiver FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2020 AND duration < 60;

-- see the people that withdrawed money
SELECT name, phone_number, license_plate, passport_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number = 49610011;

-- find the the other man on the phone
SELECT name, phone_number, license_plate, passport_number FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE phone_number = "(725) 555-3243";

-- find the flight and the passenger
SELECT flight_id, destination_airport_id FROM passengers
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id
WHERE day = 29 AND month = 7 AND year = 2020 AND airports.city LIKE "Fiftyville"
AND hour < 10 AND passport_number = 5773159633;

-- find the information about the flight
SELECT * FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE destination_airport_id = 4;
