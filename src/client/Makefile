all: sipclient ../common/json_logging.o

sipclient: main.cpp client_engine.o udp_client.o ../common/json_logging.o
	g++ main.cpp -o sipclient -I . -I ../common  client_engine.o udp_client.o ../common/json_logging.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options

clean:
	- rm *.o
	- cd ../common; make clean

distclean: clean
	rm sipclient

../common/json_logging.o: ../common/json_logging.cpp
	cd ../common; make all

.cpp.o:
	g++ -c -I ../common $<
