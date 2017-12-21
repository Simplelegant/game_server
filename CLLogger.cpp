#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "CLLogger.h"

#define LOG_FILE_NAME "CLLogger.txt"
#define MAX_SIZE 256

CLLogger::CLLogger(){
	m_Fd = open(LOG_FILE_NAME, O_RDWR | O_CREAT | O_APPEND | S_IRUSR | S_IWUSR);
}

CLLogger::~CLLogger(){
	if(m_Fd != -1)
		close(m_Fd);
}

CLStatus CLLogger::WriteLog(const char *pstrMsg, long lErrorCode){
	if(pstrMsg == 0)
		return CLStatus(-1, 0);

	if(strlen(pstrMsg) == 0)
		return CLStatus(-1, 0);

	if(m_Fd == -1)
		return CLStatus(-1, 0);

	char buf[MAX_SIZE];
	snprintf(buf, MAX_SIZE, "	Error Code: %ld\r\n", lErrorCode);

	ssize_t r = write(m_Fd, buf, strlen(buf));

	if(r == -1)
		return CLStatus(-1, errno);

	return CLStatus(0, 0);
}