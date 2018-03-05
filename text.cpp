#include <iostream>
#include "CLPorcess.h"

using namespace std;

class CLMyProcess : public CLPorcess
{
public:
	virtual CLStatus StartFunctionOfProcess(void *pContext)
	{
		cout << (long)pContext << endl;

		return CLStatus(0, 0);
	}
};

int main()
{
	CLMyProcess process;
	process.Run((void *)2);
	process.WaitForDeath();

	return 0;
}