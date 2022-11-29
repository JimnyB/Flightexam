Exam: Flight_exam.cpp ticketManager.cpp bookingManager.cpp flightManager.cpp ticketManager.hh bookingManager.hh flightManager.hh flights.hh bookings.hh  
	g++ Flight_exam.cpp ticketManager.cpp bookingManager.cpp flightManager.cpp -o Exam
run: Exam
	./Exam -f flights.csv -b bookings.csv 
	
