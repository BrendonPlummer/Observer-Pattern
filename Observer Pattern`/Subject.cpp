#include "Subject.h"

Subject::~Subject(void)
{
	myObservers.clear();
}
void Subject::RegisterObserver(Observer* pNewObserver)
{
	pNewObserver->SetSubject(this);
	myObservers.push_back(pNewObserver);
}
void Subject::RemoveObserver(Observer* pCurrentObserver)
{
	for (int obsCount = 0; obsCount <= myObservers.size(); obsCount++)
	{
		if (myObservers[obsCount] == pCurrentObserver)
		{
			myObservers.erase(myObservers.begin() + obsCount);
			return;
		}
	}
}
bool Subject::ObserverExists(Observer* pObserver)
{
	if (pObserver == nullptr) return false;

	for (int obsCount = 0; obsCount <= myObservers.size(); obsCount++)
	{
		if (myObservers[obsCount] == pObserver)
			return true;
	}
	return false;
}

void Subject::NotifyObserver(void)
{
	for (int obsCount = 0; obsCount <= myObservers.size(); obsCount++)
	{
		myObservers[obsCount]->Update();
	}
}