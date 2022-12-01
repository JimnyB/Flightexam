## Flightprogram in C++, Movant YH
Main file of the program is : Flight_exam.cpp

# Produce tickets
The main purpose of this program is to match information from existing flights with corresponding bookings.
* The first argument the program takes is information reguarding flights.
* The second argument the program takes is information reguarding bookings.
When the booknig is matched with a flight, a seat will be allocated and a file with the ticket will be created.
Flights without bookings will be canceled and a seperate file with be created containing relevant information.

* Compiling the program is done with make

# Example once compiled
./Flight_exam.cpp -f flights.csv -b booking.csv alternatively, make run.

# Formatting example of the tickets that are produced are shown below:
BOOKING:1011
FLIGHT:308
DEPARTURE:GOT
DESTINATION:LGW 2022-10-27 06:30
PASSENGER:Ulf Johansson
CLASS:business
ROW:29    SEAT:200

# Flights without any bookings will end up in a seperate file, formatting is shown below
Flight nr 312 07:30 is canceled

## Output:
* The tickets that get produced will have the following format:
ticket-{bookingnumber}.txt

* Each file should contain the following information in this format:
BOOKING:{bookingnumber} 
FLIGHT:{flight} DEPARTURE:{dep} DESTINATION: {dest} {date} {time}
PASSENGER {firstname} {surname}
CLASS: {seatclass}
ROW {row} SEAT {seatnumber}


