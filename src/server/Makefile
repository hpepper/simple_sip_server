all: sipserver

sipserver: main.cpp server_engine.o udp_server.o ../common/json_logging.o ../common/sip_message_register.o ../common/sip_message_base.o
	g++ main.cpp -o sipserver -I . -I ../common server_engine.o udp_server.o ../common/sip_message_register.o ../common/sip_message_base.o ../common/json_logging.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options

clean:
	- rm *.o
	cd ../common; make clean

distclean: clean
	- rm sipserver

../common/json_logging.o: ../common/json_logging.cpp
	cd ../common; make all

.cpp.o:
	g++ -c -I ../common $<
