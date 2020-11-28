//
//
//

#include "RefreshChecker.h"

RefreshChecker::RefreshChecker(int size)
{
	previousValues = new int[size];
}

int RefreshChecker::PassNew(int id, int value)
{
	if (previousValues[id] != value)
	{
		_hasNewData = true;
	}

	previousValues[id] = value;
	return value;
}

bool RefreshChecker::HasNewData()
{
	bool ret = _hasNewData;
	_hasNewData = false;

	return ret;
}
