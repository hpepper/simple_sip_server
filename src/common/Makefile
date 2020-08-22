all: json_logging.o sip_message_base.o sip_message_register.o

json_logging.o: json_logging.h json_logging.cpp
	g++ -c json_logging.cpp

sip_message_base.o: sip_message_base.h sip_message_base.cpp
	g++ -c sip_message_base.cpp

sip_message_register.o: sip_message_register.h sip_message_register.cpp
	g++ -c sip_message_register.cpp


clean:
	rm *.o

.cpp.o:
	g++ -c $<