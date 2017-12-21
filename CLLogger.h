#ifndef CLLogger_H
#define CLLogger_H

#include "CLStatus.h"

class CLLogger {
public:
	CLLogger();
	virtual ~CLLogger();

	CLStatus WriteLog(const char *pStrMsg, long lErrorCode);

private:
	CLLogger(const CLLogger&);
	CLStatus &operator=(const CLLogger&);

private:
	int m_Fd;
};

#endif