all: sipclient ../common/json_logging.o ../common/sip_message_base.o ../common/sip_message_register.o

sipclient: main.cpp client_engine.o udp_client.o ../common/json_logging.o ../common/sip_message_base.o ../common/sip_message_register.o
	g++ main.cpp -o sipclient -I . -I ../common  client_engine.o udp_client.o ../common/json_logging.o ../common/sip_message_base.o ../common/sip_message_register.o -lstdc++ -L /usr/lib/x86_64-linux-gnu -lboost_program_options

clean:
	- rm *.o
	- cd ../common; make clean

distclean: clean
	rm sipclient

../common/json_logging.o: ../common/json_logging.cpp
	cd ../common; make all

../common/sip_message_base.o:
	cd ../common; make all

../common/sip_message_register.o:
	cd ../common; make all

.cpp.o:
	g++ -c -I ../common $<
