all: sipserver

sipserver: main.cpp server_engine.o udp_server.o json_logging.o
	g++ main.cpp -o sipserver -I . server_engine.o udp_server.o json_logging.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options

clean:
	rm *.o

distclean: clean
	rm sipserver

.cpp.o:
	g++ -c $<