#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore/QDebug>

#define PORT_NUMBER 8001
#define READ_DELAY  10000 // milli seconds

#define WS_PORT_NO  8010


//#define SIMULATED

#define LINUX

#ifdef LINUX
  #define RS_PORT "/dev/ttyS0"
#else
  #define RS_PORT "COM10"
#endif

#define RS_SPEED 9600

#endif // CONFIG_H

