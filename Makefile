Exam: flight_exam.cpp ticketManager.cpp bookingManager.cpp flightManager.cpp ticketManager.hh bookingManager.hh flightManager.hh flight.hh bookings.hh  
	g++ flight_exam.cpp ticketManager.cpp bookingManager.cpp flightManager.cpp -o Exam
run: Exam
	./Exam -f flights.csv -b bookings.csv 
	
