all: TheServer TheClient

TheServer:
	cd server && make

TheClient:
	cd client && make

clean:
	- cd common && make clean
	- cd client && make clean
	- cd server && make clean
	- cd ut_common && make clean