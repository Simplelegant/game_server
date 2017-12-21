#include <iostream>
#include "CLLogger.h"

int main(){
	CLLogger logger;

	logger.WriteLog("First Error~", 5);
	logger.WriteLog("Second Error~", 6);

	return 0;
}