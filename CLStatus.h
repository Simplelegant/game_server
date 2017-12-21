#ifndef CLSTAUTS_H
#define CLSTAUTS_H

class CLStatus{
public:
	//if lReturnCode >= 0 --success
	//else wrong
	CLStatus(long lReturnCode, long lErrorCode);
	CLStatus(const CLStatus& s);
	virtual ~CLStatus();

public:
	bool IsSuccess();

public:
	const long& m_clReturnCode;
	const long& m_clErrrorCode;

private:
	long m_lReturnCode;
	long m_lErrorCode;
};

#endif