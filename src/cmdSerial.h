#ifndef CMD_SERIAL_FILE
#define CMD_SERIAL_FILE

#include<Arduino.h>

#define CMDSerialPort Serial
#define CMDMaxPackageSize 256

namespace cmdSerial
{
	class CMDPackage
	{
	public:
		CMDPackage();
		CMDPackage(unsigned char type);

		unsigned char GetSize() { return currentPosition; }
	private:
		unsigned char currentPosition;
		unsigned char data[CMDMaxPackageSize];
	};
	class CMDSerial
	{
	public:
		void send(CMDPackage &package);
		void receive(CMDPackage &package);
	};
}
#endif