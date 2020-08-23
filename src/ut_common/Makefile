# make clean all

CXXTEST=.

all: ../common/sip_message_base.o ../common/sip_message_register.o runner
	./runner

runner: runner.cpp
	g++ -o runner -I${CXXTEST} runner.cpp ../common/sip_message_register.o ../common/sip_message_base.o

runner.cpp: UtSipMessageBase.h UtSipMessageRegister.h
	cxxtestgen --error-printer -o runner.cpp UtSipMessageBase.h UtSipMessageRegister.h

../common/sip_message_base.o:
	cd ../common; make all

../common/sip_message_register.o:
	cd ../common; make all

clean:
	- rm runner.cpp
	- rm runner
	- cd ../common && make clean