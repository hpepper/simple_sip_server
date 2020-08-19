all: sipclient

sipclient: main.cpp client_engine.o udp_client.o ../Common/json_logging.o
	g++ main.cpp -o sipclient -I . -I ../Common  client_engine.o udp_client.o ../Common/json_logging.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options

clean:
	- rm *.o
	- cd ../Common; make clean

distclean: clean
	rm sipclient

../Common/json_logging.o: ../Common/json_logging.cpp
	cd ../Common; make all

.cpp.o:
	g++ -c -I ../Common $<
