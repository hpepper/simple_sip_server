all: sipserver

sipserver: main.cpp server_engine.o udp_server.o 
	g++ main.cpp -o sipserver -I . server_engine.o udp_server.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options


.cpp.o:
	g++ -c $<