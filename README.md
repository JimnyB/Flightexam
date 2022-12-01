# Flightprogram in C++, Movant YH

Main file of the program is : Flight_exam.cpp

## Produce tickets

The main purpose of this program is to match information from existing flights with corresponding bookings.
* The first argument the program takes is information reguarding flights.
* The second argument the program takes is information reguarding bookings.
When the booknig is matched with a flight, a seat will be allocated and a file with the ticket will be created.
Flights without bookings will be canceled and a seperate file with be created containing relevant information.

* Compiling the program is done with make

## Example once compiled
./Flight_exam.cpp -f flights.csv -b booking.csv alternatively, make run.

## Formatting example of the tickets that are produced are shown below:

BOOKING:1011
FLIGHT:308
DEPARTURE:GOT
DESTINATION:LGW 2022-10-27 06:30
PASSENGER:Ulf Johansson
CLASS:business
ROW:29    SEAT:200

## Flights without any bookings will end up in a seperate file, formatting is shown below
Flight nr 312 07:30 is canceled

# Output:

* The tickets that get produced will have the following format:
ticket-{bookingnumber}.txt

* Each file should contain the following information in this format:
BOOKING:{bookingnumber} 
FLIGHT:{flight} DEPARTURE:{dep} DESTINATION: {dest} {date} {time}
PASSENGER {firstname} {surname}
CLASS: {seatclass}
ROW {row} SEAT {seatnumber}


## The ticket program

```
You should create a program that takes two arguments.
The first argument is a file with flight information.
The second argument is a file with booking information.
Your program should create files with a ticket for each booking.
```
**Compiling the program**

```
make
```

**Example running the program:**
```
ticketsystem flights.csv booking.csv

or

make run
```

**Will produce the files:**

```
ticket-1001.txt ticket-1002.txt ticket-1003.txt ticket-1004.txt
ticket-1005.txt ticket-1006.txt ticket-1007.txt ticket-1008.txt
....
```

## Each row in any flights contain 7 seats. There is an aisle between seat 2 and 3, and 5 and 6.

```
Row seating is 2-3-2 the all flights.

[Window] [seat 1][seat 2] aisle [seat 3][seat 4][seat 5] aisle [seat 6][seat 7] [window]

```

## Flight data-file structure:

flights.csv:
```
flightnumber,departure,destination,date,time,f-rows,b-rows,e-rows
```

## Booking data-file structure:

bookings.csv:
```
bookingnumber,date,time,departure,destination,seatclass,firstname,surname
```

## Output:

The tickets should be written to files with the following filename format:

```
ticket-{bookingnumber}.txt
```

Each file should contain the following information in this format: 

```
BOOKING:{bookingnumber} 
FLIGHT:{flight} DEPARTURE:{dep} DESTINATION: {dest} {date} {time}
PASSENGER {firstname} {surname}
CLASS: {seatclass}
ROW {row} SEAT {seatnumber}
```

### Example of ticket filename:

```
ticket-2007.txt
```

### Example of ticket file content:
```
BOOKING:2007
FLIGHT:304 DEPARTURE:GOT DESTINATION:CPH 2022-10-27 06:30
PASSENGER: Kalle Kula
CLASS: first
ROW:4 SEAT:24
```
