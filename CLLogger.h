#ifndef CLLogger_H
#define CLLogger_H

#include "CLStatus.h"

class CLLogger
{
public:
	static CLLogger* GetInstance();
	static CLStatus WriteLogMsg(const char *pstrMsg, long lErrorCode);
	CLStatus WriteLog(const char *pstrMsg, long lErrorCOde);
	CLStatus Flush();

private:
	CLLogger(const CLLogger&);
	CLLogger& operator=(const CLLogger&);

	CLLogger();
	~CLLogger();

	int m_Fd;
	static CLLogger *m_pLog;

private:
	char *m_pLogBuffer;
	unsigned int m_nUsedBytesForBuffer;
};

#endif