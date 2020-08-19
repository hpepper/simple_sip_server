all: sipserver

sipserver: main.cpp server_engine.o udp_server.o ../Common/json_logging.o
	g++ main.cpp -o sipserver -I . -I ../Common server_engine.o udp_server.o ../Common/json_logging.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options

clean:
	rm *.o

distclean: clean
	rm sipserver

../Common/json_logging.o: ../Common/json_logging.cpp
	cd ../Common; make all

.cpp.o:
	g++ -c -I ../Common $<