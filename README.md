
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
